#include <string.h>

#include "Loged.h"
#include "CommandEnter.h"

using namespace std;

string msg;

int main() {

	Loged("Application lancer !\n");

	CommandEnter(msg);

	return 0;

}