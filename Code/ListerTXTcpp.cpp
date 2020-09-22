#include <fstream>
#include <string.h>
#include <iostream>

#include "ListerTXT.h"
#include "Loged.h"

using namespace std;

void ListerTXT(ifstream& file) {

	string ligne;

	if (!file) file.open("../Data/Log.txt");

	while (getline(file, ligne)) {

		cout << ligne + "\n";

	}

	if (!getline(file, ligne)) file.close();

}