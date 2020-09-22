#include "ReadLine.h"
#include <string.h>
#include <fstream>

using namespace std;

string ReadLine(ifstream& file, int numberLine) {

	string ligne;

	for (int i = 0; i < numberLine; i++) getline(file, ligne);

	file.close();

	return ligne;

}
