#ifndef ASMANALYZER_H
#define ASMANALYZER_H
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <regex>
#include <algorithm>
#include <sys/stat.h>
#include <sstream>

using namespace std;


struct isa_t
{
	string mnemonic;
	int nCycles;

};

struct avr_isa_t{
	string mnemonic;
	int nCycles;
};



enum ISA{
	AVR_ISA
};
struct funcList_t
{
	string addr;
	string mangledName;
	string name;
	vector<string> rows;
};

struct microController_t
{
	microController_t(){}
	size_t fcpu;
	size_t ramSize;
};

struct atmega2560_t : microController_t{
	atmega2560_t(){
		fcpu = 16000000;
		ramSize = 8192;
	}
};
class AsmAnalyzer
{
public:
	AsmAnalyzer();
	AsmAnalyzer(microController_t micro);
	void loadFile(string filename);
	void loadStr(char *str);
	void listFunctions();
	void parseRoutines();

	void listISA(ISA isa);
	void createFile(string filename);

private:
	//-------- Methods --------//
	string getRow(size_t funcIndex, size_t rowIndex);
	void  setRow(size_t funcIndex, size_t rowIndex, string str);


	bool validateRoutine();
	void removeGarbage();

	string getStdoutFromCommand(string cmd);
//-------- Variables --------//
	vector<funcList_t> funcList;
	microController_t microcontroller;
};

#endif
