#include <iostream>
#include <fstream>
#include<string>
#include <cctype> 
#include <cstring>
using namespace std;


int main()
{
	//Ex1
	ifstream fin1("file1.txt");
	ifstream fin2("file2.txt");

	if (!fin1 || !fin2) {
		cout << "Error opening files." << endl;
		return 1;
	}

	string line1, line2;
	int lineNumber = 0;
	bool differencesFound = false;

	while (getline(fin1, line1) && getline(fin2, line2)) {
		++lineNumber;

		if (line1 != line2) {
			differencesFound = true;
			cout << "Difference at line " << lineNumber << ":" << endl;
			cout << "File 1: " << line1 << endl;
			cout << "File 2: " << line2 << endl;
		}
	}

	
	while (getline(fin1, line1)) {
		++lineNumber;
		differencesFound = true;
		cout << "Difference at line " << lineNumber << ":" << endl;
		cout << "File 1: " << line1 << endl;
		cout << "File 2: <end of file>" << endl;
	}

	while (getline(fin2, line2)) {
		++lineNumber;
		differencesFound = true;
		cout << "Difference at line " << lineNumber << ":" << endl;
		cout << "File 1: <end of file>" << endl;
		cout << "File 2: " << line2 << endl;
	}

	if (!differencesFound) {
		cout << "No differences found between the files." << endl;
	}

	fin1.close();
	fin2.close();

	//Ex2
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin || !fout) {
        cout << "Error opening files." << endl;
        return 1;
    }

    int charCount = 0;
    int lineCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;

    char ch;
    while (fin.get(ch)) {
        
        charCount++;

       
        if (ch == '\n') {
            lineCount++;
        }

        
        if (isalpha(ch)) {
            ch = tolower(ch); 
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelCount++;
            }
            else {
                consonantCount++;
            }
        }

        
        if (isdigit(ch)) {
            digitCount++;
        }
    }

   
    if (charCount > 0) {
        lineCount++;
    }

    
    fout << "Character count: " << charCount << endl;
    fout << "Line count: " << lineCount << endl;
    fout << "Vowel count: " << vowelCount << endl;
    fout << "Consonant count: " << consonantCount << endl;
    fout << "Digit count: " << digitCount << endl;

    cout << "Statistics written to output.txt." << endl;

    fin.close();
    fout.close();
	
	

	//Ex3
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin || !fout) {
        cout << "Error opening files." << endl;
        return 1;
    }

    string line;
    int shift = 3; 

    while (getline(fin, line)) {
        for (char& ch : line) {
            if (isalpha(ch)) {
                char baseChar = isupper(ch) ? 'A' : 'a';
                ch = baseChar + (ch - baseChar + shift) % 26;
            }
        }
        fout << line << endl; 
    }

    fin.close();
    fout.close();

    cout << "Encryption completed. Encrypted text written to output.txt." << endl;
}


