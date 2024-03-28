#include<iostream>
#include<string.h>

using namespace std;
 

//Ex1
void eraseDemo(string str)
{
    str.erase(1,3);
    cout << "After erase: "<< str << endl;
}

//Ex2
void deleteChar(char *string0, char sumbol)
{
	char* readPtr = string0; 
	char* writePtr = string0; 

	for (*readPtr != '\0'; readPtr++;) {
		if (*readPtr != sumbol) {
			*writePtr = *readPtr; 
			++writePtr; 
		}
	}

	
}

//Ex3
void changeSymbol(char *myWord,int num)
{
	
    _strnset(myWord, '*', 2);
	cout << "After line: " << myWord << endl;
}

//Ex4
void userChar(char* str1)
{
	char* str1Ptr = nullptr;
	for (str1Ptr = str1; *str1Ptr; str1Ptr++)
	{
		if (*str1Ptr == '.')
		{
			*str1Ptr = '!';
		}
	}
}

//Ex5
void userchar(char* str1, char target_char) {
	int count = 0;
	for (char* str1ptr = str1; *str1ptr; str1ptr++) {
		if (*str1ptr == target_char) {
			count++;
		}
	}
	cout << "Sumbol '" << target_char << "' is " << count << "in line" << endl;
}
//Ex6
void countCharacters(const char* str, int& letters, int& digits, int& others) 
{
	letters = 0;
	digits = 0;
	others = 0;

	for (size_t i = 0; i < strlen(str); ++i) {
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) 
		{
			letters++;
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			digits++;
		}
		else {
			others++;
		}
	}
}

int main()
{
	//Ex1
    string str("Hello World!");
    cout << "Before erase : "<< str<<endl;
   
    eraseDemo(str);

	//Ex2
	char inputString[] = "Hello, world!";
	char charToRemove = 'l';
    cout << "Before : " << inputString << endl;

	deleteChar(inputString, charToRemove);
    cout << "String after removing '" << charToRemove << "': " << inputString << endl;



	//Ex3
	char string[] = "This is a test";
	int num = 2;
	cout << "New: " << string << endl;
	changeSymbol(string, num);
    
	
	//Ex4
	char mystring[] = "Hello, world. This is a test.";
	userChar(mystring);
	cout << "After: " << mystring << endl;

	
	//Ex5
	char my_string[] = "Hello, world. This is a test.";
	char target_char = '.'; 
	userchar(my_string, target_char);

	//Ex6
	char mystring[] = "Hello, world. This is a test.";
    int letters, digits, others;
	
	countCharacters(mystring, letters, digits, others);

	cout << "Letters: " << letters << endl;
	cout << "Digits: " << digits << endl;
	cout << "Other characters: " << others << endl;


}
