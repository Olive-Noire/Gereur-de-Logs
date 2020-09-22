#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

#include "CommandEnter.h"

#include "Loged.h"
#include "ClearTXT.h"
#include "ListerTXT.h"
#include "GetNumberLineTXT.h"
#include "ReadLine.h"

using namespace std;

string logPath("../Data/log.txt");
ifstream logGet(logPath);

string CommandesPath("../Data/commandes.txt");
ofstream Commandes(CommandesPath, ios::app);
ifstream CommandesGet(CommandesPath);

int commandNumber = GetNumberLineTXT(CommandesGet);
vector<string> commands(commandNumber);

string prefix("/");

void CommandEnter(string command) {

	cout << "faites !help Pour consultez les commandes\n";
	cout << ReadLine(CommandesGet, 1) << "\n";

	for (int i = 0; i < commandNumber; i++) {

		CommandesGet.open(CommandesPath, ios::app);
		if (i < (commandNumber - 1)) commands[i] = prefix + ReadLine(CommandesGet, (i + 1));
		if (i == (commandNumber - 1)) commands[i] = ReadLine(CommandesGet, (i + 1));

	}

	cin >> command;

	while (!command.empty()) {

		int i = 0;

		while (command != commands[i]) {

			if (i < commandNumber) i++;

			while (i == commandNumber) {

				cout << "ceci n'est pas une commande !\n";
				Loged("L'utilisateur a utiliser une commande inconnu (" + command + ")\n");
				cin >> command;
				i = 0;

			}

		}


		while (command == commands[i]) {

			Loged("L'utilisateur a utiliser la commande " + command + "\n");

			if (i == 0) {
				ListerTXT(logGet);
				Loged("L'utilisateur a consultez les logs !\n");
			}

			if (i == 1) {
				Loged("ECHEC : Application non clear ! VEUILLEZ REESSAYER OU OUVRIR LE FICHIER\n");
				ClearTXT(logGet);
			}

			if (i == 2) {
				Loged("Application fermer !\n");
				exit(3);
			}

			if (command == "!help") {

				for (int i = 0; i < (commandNumber - 1); i++) {

					if (i == 0) cout << "\nVoici les commandes : \n---------------------\n\n";
					cout << commands[i] << "\n";
					if (i == (commandNumber - 2)) cout << "\n---------------------\n\n";
					Loged("L'utilisateur a utiliser !help Pour voir les commandes !\n");

				}

			}

			cin >> command;

		}

	}

}