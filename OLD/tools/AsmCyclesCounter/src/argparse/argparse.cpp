#include "argparse.h"


ArgParse::ArgParse()
{

}



void ArgParse::addParam(const char *param, type type, const char *helpStr)
{
	param_t temp;
	char * pch;
	char buff[128];
	strcpy(buff,param);
	//printf ("Splitting string \"%s\" into tokens:\n",param);
	pch = strtok (buff," ");
	temp.param.shortParam = pch;
	while (pch != NULL)
	{
		temp.param.longParam = pch;
		pch = strtok (NULL, " ");
	}
	temp._type = type;
	temp.helpStr = helpStr;

	params.push_back(temp);

}

void ArgParse::parseArgs(int argc, char **argv)
{
	if(argc <=1){
		printHelp();
	}
	for (int i = 1;i < argc;++i) {

		for(int j = 0; j< params.size(); ++j){
			if(argv[i] == params[j].param.shortParam ||argv[i] == params[j].param.longParam ){
				userParam temp(params[j].param.shortParam, argv[i+1] == nullptr ? "": argv[i+1]);
				userParams.push_back(temp);
			}
		}

	}
}

string ArgParse::getParams(string param)
{
	for(int j = 0; j< userParams.size(); ++j){
		if(param == userParams[j].param){
			return userParams[j].value;
		}
	}

	return "";
}

void ArgParse::printHelp()
{
	size_t i = 0;
	printf("Help menu\r\n");
	for (i = 0;i < params.size();++i) {
		printf("%s %s  %s\r\n",params[i].param.shortParam.c_str(),
									params[i].param.longParam.c_str(),
									params[i].helpStr.c_str());
	}
	exit(0);
}
