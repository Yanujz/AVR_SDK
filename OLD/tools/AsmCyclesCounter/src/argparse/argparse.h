#ifndef ARGPARSE_H
#define ARGPARSE_H
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

enum type:uint8_t{
	uint8,int8,
	uint16,int16,
	uint32,int32,
	uint64,int64,
	str,boolean
};


struct _param{
	string shortParam;
	string longParam;
};

struct param_t{
	_param param;
	type _type;
	string helpStr;
};

struct userParam
{
	userParam(string param, string value){
		this->param = param;
		this->value = value;
	}
	string param;
	string value;
};



class ArgParse
{
public:
	ArgParse();


	void addParam(const char *param, type type, const char* helpStr);
	void parseArgs(int argc,char **argv);

	string getParams(string param);

private:
	void printHelp();

	vector<param_t> params;
	vector<userParam> userParams;
};

#endif // ARGPARSE_H
