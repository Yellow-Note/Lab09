// Tim Bourque
// Lab 09

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <map>

using namespace std;


map<string, int> FileRead(map<string, int> stringMap) {//map<key,value>
	string fileName, word;
	map<string, int>::iterator it;
	cout << "Enter name of file to read from" << endl;
	cin >> fileName;
	ifstream inFile;
	inFile.open(fileName);
	if (inFile.is_open()) {
		while (inFile >> word) {
			it = stringMap.find(word);
			if (it != stringMap.end()) {//find element ++
				++stringMap[word];
			}
			else {//not find element insert into map
				stringMap.insert(pair<string, int>(word, 1));
			}
			word.clear();
		}
	}
	else {
		cout << "Failed to open file" << endl;
	}

	inFile.close();
	inFile.clear();

	return stringMap;
}

void FileWrite(map<string, int> stringMap) {
	ofstream outFile;
	outFile.open("output.txt");
	if (outFile.is_open()) {
		for (map<string, int>::iterator it = stringMap.begin(); it != stringMap.end(); ++it) {
			while (it->second != 0) {
				outFile << it->first << " ";
				it->second--;
			}
			outFile << endl;
		}
	}
	else {
		cout << "Failed to open file to write" << endl;
	}

	outFile.close();
	outFile.clear();
}

int main()
{
	map<string, int> stringMap;

	stringMap = FileRead(stringMap);
	FileWrite(stringMap);

    return 0;
}
