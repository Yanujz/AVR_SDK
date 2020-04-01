/*
	

	Author : Yanujz

	Created in : 01/11/2020

    Copyright (C) 2020  Yanujz

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

	You may contact the author by:
		e-mail: yanujz@live.it
*/
#pragma once
#include <stdio.h>
#include <stdint.h>


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// for debugging
//#define STATUS(format, args...)
//   printf("here: %d. ", __LINE__); printf(format, ## args); printf("\n"); fflush(stdout);


/* currently building the argc/argv stuff in a global context */
#define ARGV_MAX  255
#define ARGV_TOKEN_MAX  255

struct cli_tokens_t {
 int argc;
 char **argv;
};

/* main parser */
cli_tokens_t cli_tokenizer_str2argv(char *s);
void cli_tokenizer_free(cli_tokens_t* args);

