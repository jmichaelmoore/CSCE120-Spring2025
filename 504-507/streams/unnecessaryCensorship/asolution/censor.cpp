#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

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
	for (size_t i = 0; i<numChars; ++i) {
		int ind = random()%10;
		switch (ind) {
			case 0:
				cWd += '!';
				break;
			case 1:
				cWd += '#';
				break;
			case 2:
				cWd += '%';
				break;
			case 3:
				cWd += '$';
				break;
			case 4:
				cWd += '&';
				break;
			case 5:
				cWd += '@';
				break;
			case 6:
				cWd += '*';
				break;
			case 7:
				cWd += '(';
				break;
			case 8:
				cWd += '?';
				break;
			case 9:
				cWd += '-';
				break;
		}
	}
	return cWd;
}

int main(int argc, char *argv[]) {
	string censorWordsFilename;
	string originalTextFilename;
	if (argc == 3) {
		censorWordsFilename = argv[1];
		originalTextFilename = argv[2];
	}
	else {
		// use hard coded if files are not provided
		censorWordsFilename = "censorwords.txt";
		originalTextFilename = "frozen.txt";
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
		cwds.push_back(tolower(wd));
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
		string linelower = tolower(line);
			// get next line
			// see if each censor word is in line
		for (size_t j=0; j<cwds.size(); ++j) {
			string cwd = cwds.at(j);
			size_t position = string::npos;
			do {
				position = linelower.find(cwd);
				if (position != string::npos) {
					line.replace(position, cwd.size(), makeCensor(cwd.size()));
					linelower.replace(position, cwd.size(), cwd.size(), '*');
				}
			} while(position != string::npos);
		}
			// if it is there, replace with symbols
			// output modified line
		ofs << line << endl;
	}
}