#include "cli_tokenizer.h"
#include <string.h>
int    _argc;
char  *_argv[ARGV_MAX];
char  *_argv_token;

/* initialize empty argc/argv struct */
void argv_init()
{
    _argc = 0;
    if ((_argv_token = (char*)calloc(ARGV_TOKEN_MAX, sizeof(char))) == NULL)
        puts("argv_init: failed to calloc");
    //bzero(_argv_token, ARGV_TOKEN_MAX * sizeof(char));
}

/* add a character to the current token */
void argv_token_addch(int c)
{
    int n;

    n = strlen(_argv_token) & 0xFFFFFFFF;
    if (n == ARGV_TOKEN_MAX - 1)
        printf("argv_token_addch: reached max token length (%d)", ARGV_TOKEN_MAX);

    _argv_token[n] = c;
}

/* finish the current token: copy it into _argv and setup next token */
void argv_token_finish()
{
    if (_argc == ARGV_MAX)
        printf("argv_token_finish: reached max argv length (%d)", ARGV_MAX);

    /*STATUS("finishing token: '%s'\n", _argv_token);*/
    _argv[_argc++] = _argv_token;
    if ((_argv_token = (char*)calloc(ARGV_TOKEN_MAX, sizeof(char))) == NULL)
        puts("argv_token_finish: failed to calloc");
    //bzero(_argv_token, ARGV_TOKEN_MAX * sizeof(char));
}

cli_tokens_t cli_tokenizer_str2argv(char *s)
{
    bool in_token;
    bool in_container;
    bool escaped;
    char container_start;
    char c;
    int  len;
    int  i;

    container_start = 0;
    in_token = false;
    in_container = false;
    escaped = false;

    len = strlen(s) & 0xFFFFFF;

    argv_init();
    for (i = 0; i < len; i++) {
        c = s[i];

        switch (c) {
        /* handle whitespace */
        case ' ':
        case '\t':
        case '\n':
            if (!in_token)
                continue;

            if (in_container) {
                argv_token_addch(c);
                continue;
            }

            if (escaped) {
                escaped = false;
                argv_token_addch(c);
                continue;
            }

            /* if reached here, we're at end of token */
            in_token = false;
            argv_token_finish();
            break;

            /* handle quotes */
        case '\'':
        case '\"':

            if (escaped) {
                argv_token_addch(c);
                escaped = false;
                continue;
            }

            if (!in_token) {
                in_token = true;
                in_container = true;
                container_start = c;
                continue;
            }

            if (in_container) {
                if (c == container_start) {
                    in_container = false;
                    in_token = false;
                    argv_token_finish();
                    continue;
                } else {
                    argv_token_addch(c);
                    continue;
                }
            }

            /* XXX in this case, we:
             *    1. have a quote
             *    2. are in a token
             *    3. and not in a container
             * e.g.
             *    hell"o
             *
             * what's done here appears shell-dependent,
             * but overall, it's an error.... i *think*
             */
            printf("Parse Error! Bad quotes\n");
            break;

        case '\\':

            if (in_container && s[i+1] != container_start) {
                argv_token_addch(c);
                continue;
            }

            if (escaped) {
                argv_token_addch(c);
                continue;
            }

            escaped = true;
            break;

        default:
            if (!in_token) {
                in_token = true;
            }

            argv_token_addch(c);
        }
    }

    if (in_container)
        printf("Parse Error! Still in container\n");

    if (escaped)
        printf("Parse Error! Unused escape (\\)\n");
    cli_tokens_t temp;
    temp.argc = _argc;
    temp.argv = _argv;
    return temp;
}

void cli_tokenizer_free(cli_tokens_t *args)
{
    for (int i = 0; i < args->argc; ++i) {
        free(args->argv[i]);
    }
}
