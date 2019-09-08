#include "asmanalyzer.h"

avr_isa_t avr_isa[]={
	//Arithmetic and logic Instructions
	{"add",			1}, {"adc",			1}, {"adiw",		2}, {"sub",			1},
	{"subi",		1},	{"sbc",			1},	{"sbci",		2},	{"sbiw",		1},
	{"and",			1},	{"andi",		1},	{"or",				1},	{"ori",			1},
	{"eor",			1},	{"com",			1},	{"neg",			1},	{"sbr",			1},
	{"cbr",			1},	{"inc",			1},	{"dec",			1},	{"tst",			1},
	{"clr",			1},	{"ser",			1},	{"mul",			2},	{"muls",		2},
	{"mulsu",	2},	{"fmul",		2},	{"fmuls",	2},	{"fmulsu",2},
	//Branch Instructions
	{"rjmp",	 2},	{"ijmp",	 2},	{"eijmp",		2},	{"jmp",	 3},
	{"rcall", 4},	{"icall", 4},	{"eicall",	4},	{"call", 5},
	{"ret",		 5},	{"reti",	 5},	{"cpse",			3},	{"cp",		 1},
	{"cpc",		 1},	{"cpi",		 1},	{"sbrc",			3},	{"sbrs", 3},
	{"sbic",	 3},	{"sbis",	 3},	{"brbs",			2},	{"brbc", 2},
	{"breq",	 2},	{"brne",	 2},	{"brcs",			2},	{"brcc", 2},
	{"brsh",	 2},	{"brlo",	 2},	{"brmi",			2},	{"brpl", 2},
	{"brge",	 2},	{"brlt",	 2},	{"brhs",			2},	{"brhc", 2},
	{"brts",	 2},	{"brtc",	 2},	{"brvs",			2},	{"brvc", 2},
	{"brie",	 2},	{"brid",	 2},
	//Bit and Bit-Test Instructions
	{"sbi",		2},	{"cbi",		2},	{"lsl",		1},	{"lsr",	 1},
	{"rol",		1},	{"ror",		1},	{"asr",		1},	{"swap", 1},
	{"bset",	1},	{"bclr",	1},	{"bst",		1},	{"bld",	 1},
	{"sec",		1},	{"clc",		1},	{"sen",		1},	{"cln",	 1},
	{"sez",		1},	{"clz",		1},	{"sei",		1},	{"cli",	 1},
	{"ses",		1},	{"cls",		1},	{"sev",		1},	{"clv",	 1},
	{"set",		1},	{"clt",		1},	{"seh",		1},	{"clh",	 1},
	//Data transfer instructions
	{"mov",	1},	{"movw",1},	{"ldi",	1},	{"ld",		2},
	{"ldd",	2},	{"lds",	2},	{"st",		2},	{"std",	2},
	{"sts",	2},	{"lpm",	3},	{"elpm",3},	{"spm",	0},
	{"in",		1},	{"out",	1},	{"push",2},	{"pop",	2},
	// MCU Control Instructions
	{"nop",		1},	{"sleep",1},	{"wdr",		1},	{"break",0},
};




AsmAnalyzer::AsmAnalyzer()
{

}

AsmAnalyzer::AsmAnalyzer(microController_t micro){
	microcontroller = micro;
}

void AsmAnalyzer::loadFile(string filename)
{
	string nFunc = getStdoutFromCommand("avr-objdump -t -C "+filename+"| grep '.text' | wc -l");

	for(int i  = 2; i <= atoi(nFunc.c_str());++i){
		funcList_t temp;
		temp.addr = getStdoutFromCommand("avr-objdump -t "+filename+" | "
																																																														"grep '.text' | sed -n "+std::to_string(i)+"p | cut -d' ' -f1");

		temp.addr.erase(remove(temp.addr.begin(), temp.addr.end(), ' '), temp.addr.end());
		temp.addr.erase(remove(temp.addr.begin(), temp.addr.end(), '\n'), temp.addr.end());
		temp.name = getStdoutFromCommand("avr-objdump -t -C "+filename+" | grep '.text' | sed -n "+std::to_string(i)+"p | cut -c 32-");
		temp.name.erase(remove(temp.name.begin(), temp.name.end(), '\n'), temp.name.end());
		temp.mangledName = getStdoutFromCommand("avr-objdump -t "+filename+" | grep '.text' | sed -n "+std::to_string(i)+"p | cut -c 32-");
		temp.mangledName.erase(remove(temp.mangledName.begin(), temp.mangledName.end(), ' '), temp.mangledName.end());
		temp.mangledName.erase(remove(temp.mangledName.begin(), temp.mangledName.end(), '\n'), temp.mangledName.end());
		string tmpString = getStdoutFromCommand("avr-objdump -d "+filename+"| awk -v RS= '/^[[:xdigit:]]+ <"+temp.mangledName+">/'");

		std::istringstream ss(tmpString);
		while (getline(ss, tmpString)) {
			temp.rows.push_back(tmpString);
		}
		funcList.push_back(temp);
	}
	removeGarbage();
}

void AsmAnalyzer::listFunctions()
{
	printf("There are %u functions\r\n", funcList.size());

	for(int i = 0; i< funcList.size();++i){
		printf("Addr %s Name  %s Mangled Name %s\r\n",funcList[i].addr.c_str() ,funcList[i].name.c_str(), funcList[i].mangledName.c_str());
		for(int j = 0; j< funcList[i].rows.size();++j ){
			printf("Row[%d] %s\r\n",j,funcList[i].rows[j].c_str());
		}
	}
	cout << endl;


}

string AsmAnalyzer::getRow(size_t funcIndex,size_t rowIndex)
{
	return funcList[funcIndex].rows[rowIndex];
}

void AsmAnalyzer::setRow(size_t funcIndex,size_t rowIndex, string str)
{
	funcList[funcIndex].rows[rowIndex] = str;
}


void AsmAnalyzer::parseRoutines()
{

	regex mnemonics("^\\s*[a-z]+\\s*");
	regex whiteSpaces("\\s"); //remove Comment
	std::smatch mnemonicMatch;
	int totCycles = 0;


	for(int j = 0; j< funcList.size();++j){
		for (int i = 0; i < funcList[j].rows.size();++i) {

			string line = getRow(j,i);

			if (std::regex_search(line, mnemonicMatch, mnemonics)) {

				std::string cmd = regex_replace(mnemonicMatch.str(),whiteSpaces,"");

				for(int k = 0; k < sizeof(avr_isa)/sizeof(avr_isa[0]);++k){

					if(cmd == avr_isa[k].mnemonic){
						string temp = line;
						temp.insert(temp.begin(), '\t');
						temp.insert(temp.end(), 30-temp.size(), ' ');
						string _temp = ";"+ to_string(avr_isa[k].nCycles)+" Cycles";
						temp.insert(30-_temp.size(),_temp);
						setRow(j,i,temp);
						totCycles+= avr_isa[k].nCycles;
					}

				}
			}

		}
		float period = (1.0/microcontroller.fcpu)*1e6;
		string footerStr =
				"; Tot cycles = "+to_string(totCycles)+"->"+to_string(totCycles)+"*"+to_string(period)+" = "+to_string(totCycles*period)+"uS\n\n";
		funcList[j].rows.push_back(footerStr);
		totCycles = 0;
	}


}

void AsmAnalyzer::removeGarbage()
{
	regex reComments(";.*$"); //remove Comment
	/*
		Example :
				After		: 26:	80 91 00 00 	lds	r24, 0x0000	; 0x800000 <__SREG__+0x7fffc1>
				Before : 26:	80 91 00 00 	lds	r24, 0x0000
*/
	regex reOpCode("\\t?[^\\.][a-zA-Z0-9]+:\\t[a-zA-Z0-9]+\\s[a-zA-Z0-9]+"
																"\\s([a-zA-Z0-9]+)?\\s([a-zA-Z0-9]+)?"); // Remove OpCodes
	/*
		Example :
				After		: 26:	80 91 00 00 	lds	r24, 0x0000	; 0x800000 <__SREG__+0x7fffc1>
				Before :																		lds	r24, 0x0000	; 0x800000 <__SREG__+0x7fffc1>
*/

	regex reAddr("[0-9a-zA-Z]+\\s+(?=(<_+?[a-zA-Z0-9]+_?[a-zA-Z0-9]+?>:))"); // Remove Address From label
	/*
	Example:
	After		: 00000024 <__vector_21>:
	Before :										<__vector_21>:
*/

	string line;

	for(size_t j = 0; j< funcList.size();++j){
		for (size_t i = 0; i < funcList[j].rows.size();++i) {
			line = getRow(j,i);
			line = regex_replace(line, reComments, "");
			line = regex_replace(line, reOpCode, "");
			line = regex_replace(line, reAddr, "");
			replace(line.begin(), line.end(), '\t', ' ');
			line.erase(line.begin(), std::find_if(line.begin(), line.end(),
																																									std::bind1st(std::not_equal_to<char>(), ' ')));
			setRow(j,i,line);
		}

	}


}

void AsmAnalyzer::createFile(string filename)
{
	ofstream ofs (filename, ofstream::out);
	ofs.close();
	ofs.open(filename, ofstream::app);

	for(int j = 0; j< funcList.size();++j){
		for (int i = 0; i < funcList[j].rows.size();++i) {
			ofs << getRow(j,i)+'\n';

		}

	}
	ofs.close();

}

string AsmAnalyzer::getStdoutFromCommand(string cmd) {

	string data;
	FILE * stream;
	const int max_buffer = 4096;
	char buffer[max_buffer];
	cmd.append(" 2>&1");
	//cout<< cmd<<endl;
	stream = popen(cmd.c_str(), "r");
	if (stream) {
		while (!feof(stream))
			if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
		pclose(stream);
	}
	return data;
}

void AsmAnalyzer::listISA(ISA isa)
{

	switch (isa) {
	case ISA::AVR_ISA:
		cout << "N instructions "<< sizeof(avr_isa)/sizeof(avr_isa[0]) <<endl;
		for(int i = 0; i < sizeof(avr_isa)/sizeof(avr_isa[0]);++i){
			cout <<"Cmd : "<< avr_isa[i].mnemonic<<" N Cycles " <<avr_isa[i].nCycles <<endl;
		}

		break;
	default:
		break;
	}
}



