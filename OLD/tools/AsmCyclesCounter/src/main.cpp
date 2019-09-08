#include "argparse.h"
#include "asmanalyzer.h"

using namespace std;



int main(int argc, char **argv)
{
	//funcList_t funcList;
	atmega2560_t mega2560;
	AsmAnalyzer asmAnalyzer(mega2560);
	ArgParse *argParse = new ArgParse;

	argParse->addParam("-if --inputfile",type::str,"Filename to read");
	argParse->addParam("-of --outfile",type::boolean,"Output file name");
	argParse->addParam("-fN --funcname",type::str,"Function Name");
	argParse->addParam("-l --list",type::boolean,"List functions in file");
	argParse->parseArgs(argc, argv);



	asmAnalyzer.loadFile(argParse->getParams("-if"));
	//asmAnalyzer.listISA(AVR_ISA);
	asmAnalyzer.parseRoutines();
	asmAnalyzer.createFile(argParse->getParams("-of"));
	//asmAnalyzer.listFunctions();
	return 0;
}
