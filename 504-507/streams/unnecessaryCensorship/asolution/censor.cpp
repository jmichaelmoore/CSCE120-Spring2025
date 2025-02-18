#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using std::cin, std::cout, std::cerr, std::endl, std::string;
using std::istringstream, std::ifstream, std::ofstream;
using std::vector;

int main(int argc, char *argv[]) {
	// use hard coded if files are not provided
	string censorWordsFilename = "censorwords.txt";
	string originalTextFilename = "frozen.txt";

	// Get filenames if provided in command line arguments
	string censoredTextFilename = "censored-" + originalTextFilename;

	// Declare/Define/Open filestreams
	ifstream ifs_cwds(censorWordsFilename);
	ifstream ifs_txt(originalTextFilename);
	ofstream ofs(censoredTextFilename);

	// make sure all files were opened and give feedback if not
	if (!ifs_cwds.is_open()) {
		cerr << "Unable to open: " << censorWordsFilename << endl;
		return 1;
	}

	if (!ifs_txt.is_open()) {
		cerr << "unable to open: " << originalTextFilename << endl;
		return 1;
	}

	if (!ofs.is_open()) {
		cerr << "Unable to open: " << censoredTextFilename << endl;
		return 1;
	}

	// get list of words to censor from file
	vector<string> cwds;
	string wd;
	while (ifs_cwds >> wd) {
		cwds.push_back(wd);
	}

	// print out list of censored words (for debugging) remove later from final program
	for (size_t i=0; i<cwds.size(); ++i) {
		cout << cwds.at(i) << endl;
	}

	while (!ifs_txt.eof()) {
		// read original, process and send to output
		// process line by line
		string line;
		getline(ifs_txt, line);
			// get next line
			// see if each censor word is in line
		for (size_t j=0; j<cwds.size(); ++j) {
			string cwd = cwds.at(j);
			size_t position = line.find(cwd);
			if (position != string::npos) {
				line.replace(position, cwd.size(), cwd.size(), '*');
			}
		}
			// if it is there, replace with symbols
			// output modified line
		ofs << line << endl;
	}
}