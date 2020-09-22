#include <string.h>
#include <fstream>

#include "GetNumberLineTXT.h"

#include "ReadLine.h"

using namespace std;

int GetNumberLineTXT(ifstream& file) {

	int numberLine = 0;
	string ligne;

	while (getline(file, ligne)) numberLine++;

	int& const NumberLineReturn = numberLine;

	return  NumberLineReturn;

}