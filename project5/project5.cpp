#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	ifstream inputFile ("testInput.txt");
	string token;
	char aChar;
	unordered_map<string, int> tokenMap;
	map<string, int> freqMap;
	unordered_map<string, int>::iterator i;

	//Take token form file
	while (!inputFile.eof()) {
		do {
			inputFile.get(aChar);
		} while ((!inputFile.eof()) && ((aChar == ' ') || (aChar == '\n')));

		if (!inputFile.eof()) {
			token.clear();
			while ((!inputFile.eof()) && ((aChar != ' ') && (aChar != '\n'))) {
				token += aChar;
				inputFile.get(aChar);
			}
			//Token is set to a single word
			tokenMap[token]++;
		}
	}
	
	for(i = tokenMap.begin(); i != tokenMap.end(); ++i){
		cout << i->first << " " << i->second << endl;
	}
	
	
	return 0;
}

bool mapComp(const pair<string, int> a, const pair<string, int>b) {
	return (a.second < b.second);
}