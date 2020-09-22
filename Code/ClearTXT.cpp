#include <fstream>
#include <string>

int main() {

	std::string LogPath("../Data/Log.txt");
	std::ifstream Log(LogPath);

	Log.open(LogPath, std::ofstream::out | std::ofstream::trunc);
	Log.close();

}