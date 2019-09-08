#ifndef STRUTIL_H
#define STRUTIL_H

#include <string.h>
#include <utils.h>
#include <ctype.h>
#if defined(__STL_SUPPORT__)
#include <string>
#endif

///@file
namespace yanujz {
#if defined(__STL_SUPPORT__)
// convert case
std::string to_lower(std::string str);
std::string to_upper(std::string str);

char* to_lower(char* str);
char* to_upper(char* str);

// remove space & tabs from string
void filterWhite(std::string &str);

// check if string is numeric
bool isNumeric(const std::string &str);

inline std::string &ltrim(std::string &str);
inline std::string &rtrim(std::string &str);
std::string trim(std::string & str);

// split string by delimeters
std::vector<std::string> split(const std::string& str,char delim = ' ');
// count occurrence of char in string
size_t countOccurrences(const std::string& text, char c);

inline bool isset(const std::string &str);
inline bool isPrintableChar(char &c);
inline bool isBlankChar(char &c);

void removeChar(char *str, char chr);

#endif
size_t split(const char *src, char **&dst, const char *delim);

u8t hexByteStrToByte(const char* byteStr);


inline char *strToUpper(char *str)
{
	char* init = str;
	while (*str) {
		if(*str >= 'a' && *str <= 'z'){
			*str -= 0x20;
		}
		str++;
	}
	return init;
}

inline char *strToLower(char *str)
{
	char* init = str;
	while (*str) {
		if(*str >= 'A'  && *str <= 'Z'){
			*str += 0x20;
		}
		str++;
	}
	return init;
}

}
#endif
