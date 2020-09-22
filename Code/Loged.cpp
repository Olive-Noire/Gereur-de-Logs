#include <string>
#include <fstream>
#include "Loged.h"

using namespace std;

void Loged(string msg) {


	string logPath("../Data/Log.txt");
	ofstream log(logPath.c_str(), ios::app);

	log << msg;

}