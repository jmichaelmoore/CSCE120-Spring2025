#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using std::cin, std::cout, std::cerr, std::endl, std::string;
using std::istringstream, std::ifstream, std::ofstream;
using std::vector;

string tolower(string str) {
	for (size_t i=0; i<str.size(); ++i) {
		str.at(i) = tolower(str.at(i));
	}
	return str;
}

string makeCensor(size_t numChars) {
	string cWd;
	for (size_t i=0; i<numChars; ++i) {
		int rndVal = random()%10;
		switch (rndVal) {
			case 0:
				cWd += '@';
				break;
			case 1:
				cWd += '$';
				break;
			case 2:
				cWd += '~';
				break;
			case 3:
				cWd += '&';
				break;
			case 4:
				cWd += '!';
				break;
			case 5:
				cWd += '#';
				break;
			case 6:
				cWd += '*';
				break;
			case 7:
				cWd += '%';
				break;
			case 8:
				cWd += '?';
				break;
			case 9:
				cWd += '^';
				break;
		}
	}
	return cWd;
}

int main(int argc, char *argv[]) {
	string censorWordsFilename;
	string originalTextFilename;
	// Get filenames if provided in command line arguments
	if (argc != 3) {
		censorWordsFilename = "censorwords.txt";
		originalTextFilename = "frozen.txt";	
	}
	else {
		censorWordsFilename = argv[1];
		originalTextFilename = argv[2];
	}

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
		cerr << "Unable to open: " << originalTextFilename << endl;
		return 1;
	}

	if (!ofs.is_open()) {
		cerr << "Unable to open: " << censoredTextFilename << endl;
		return 1;
	}

	// get list of words to censor from file
	vector<string> censorWds;
	string censorWd;
	while (ifs_cwds >> censorWd) {
		censorWds.push_back(tolower(censorWd));
	}

	// print out list of censored words (for debugging) remove later from final program
	for (size_t i=0; i<censorWds.size(); ++i) {
		cout << censorWds.at(i) << endl;
	}

	// read original, process and send to output
	while (!ifs_txt.eof()) {
	// process line by line
	string line;
	getline(ifs_txt, line);
	string linelower = tolower(line);
	for (size_t j = 0; j<censorWds.size(); ++j) {
		string cWd = censorWds.at(j);
		size_t position = string::npos;
		do {
			position = linelower.find(cWd);
			if (position != string::npos) {
				line.replace(position, cWd.size(), makeCensor(cWd.size()));
				linelower.replace(position, cWd.size(), makeCensor(cWd.size()));
			}
		} while (position != string::npos);
	}
		// get next line
		// see if each censor word is in line
		// if it is there, replace with symbols
		// output modified line
	ofs << line << endl;
	}
}