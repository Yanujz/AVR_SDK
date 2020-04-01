#include "str_utils.h"
using namespace yanujz;

#if defined(__STL_SUPPORT__)

std::string to_lower(std::string str)
{
    for(size_t i = 0; i < str.size();++i){
        str[i] = tolower(str[i]);
    }
    return str;
}



std::string to_upper(std::string str)
{
    for(size_t i = 0; i < str.size();++i){
        str[i] = toupper(str[i]);
    }
    return str;
}


void filterWhite(std::string &str)
{
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());
}


bool isNumeric(const std::string &str)
{
    size_t i = 0;
    if(str[0] == 43 || str[0] == 45) {
        ++i;
    }
    while (str[i] >= 0x30 && str[i] <= 0x39) {
        ++i;

    }
    if(i == str.size()){
        return true;
    }


    return false;

}
inline std::string & ltrim(std::string & str){
    size_t i = 0;
    while (isPrintableChar(str[i]) == false && isBlankChar(str[i])) {
        str.erase(0,1);
        ++i;
    }
    return str;
}
inline std::string & rtrim(std::string & str){
    size_t i = str.size()-1;
    while (isPrintableChar(str[i]) == false && isBlankChar(str[i])) {
        str.pop_back();
        --i;
    }
    return str;
}


std::string trim(std::string & str){
    return ltrim(rtrim(str));
}

std::vector<std::string> split(const std::string& str,char delim)
{
    std::vector<std::string> cont;
    std::size_t current, previous = 0;
    current = str.find(delim);
    while (current != std::string::npos) {
        cont.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find(delim, previous);
    }
    cont.push_back(str.substr(previous, current - previous));
    return cont;
}

size_t countOccurrences(const std::string &text, char c)
{
    size_t count = 0;
    for (auto & _c: text) if(_c==c) count++;

    return count;
}


bool isset(const std::string &str)
{
    if(str.size())
        return true;

    return false;
}


bool isPrintableChar(char &c)
{
    if(c >= 0x20 & c <= 0x7E){
        return true;
    }
    return false;
}

bool isBlankChar(char &c)
{
    char buf[] = " \t\r\n\v";
    for(uint8_t i = 0; i < ELEMENT_IN_ARRAY(buf); ++i){
        if(c == buf[i]){
            return true;
        }
    }
    return false;
}


void removeChar(char *str, char chr)
{
    //for(u8t i = 0; i < strlen(str); ++i){
    //
    //}
}
#endif


size_t split(const char *src, char **&dst, const char *delim)
{
    char *_src = new char[strlen(src)+1];
    strcpy(_src,src);
    dst = (char**) malloc(sizeof(char*));
    char *ptr = strtok(_src, delim);
    u8t i = 0;
    while(ptr != NULL)
    {
        dst[i] = (char*) malloc(strlen(ptr)+1);
        strcpy(dst[i], ptr);
        ptr = strtok(NULL, delim);
        dst = (char**)realloc(dst, (i + 2) * sizeof(char*));
        if(dst == nullptr){
            return 0xDEAD;
        }
        ++i;
    }
    delete[] _src;

    return i; // Returns number of tokens
}


u8t hexByteStrToByte(const char *byteStr)
{
    u8t size = strlen(byteStr);
    if(size != 2){
        return 0;
    }

    u8t data;
    if(toupper(byteStr[0]) >= 'A'){
        data = ((byteStr[0] - 0x37) << 4);
    }
    else {
        data = byteStr[0] & 0xF;
    }

    if(toupper(byteStr[1]) >= 'A'){
        data |= byteStr[1] - 0x37;
    }
    else {
        data |= byteStr[1] & 0xF;
    }
    return data;
}









