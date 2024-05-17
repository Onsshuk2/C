#include <iostream>
#include <string>
using namespace std;


void dil(int a, int b) 
{
	int res;
   try
	{
	   if (b == 0)
	   {
		   throw "ERROR";
	   }
	res = a / b;
	cout << "Result: " << res << endl;
    }
	catch (const char*)
	{
		cout << "Enter corect number"<<endl;
	}
}
class NegativeNumberException : public exception 
{
private:
	string message;
public:
	
	explicit NegativeNumberException(const string& msg) : message(msg) {}
	const char* what() const noexcept override {
		return message.c_str();
	}
};

void checkNumber(int number) 
{
	if (number < 0) 
	{
		throw NegativeNumberException("Number is negative");
	}
	else {
		cout << "Number is non-negative: " << number << endl;
	}
}

class Array {
private:
	string message;
public:
	explicit Array(const string& msg) : message(msg) {}

	const char* what() const {
		return message.c_str();
	}
};

int getElementAtIndex(int* array, int size, int index) {
	if (index < 0 || index >= size) {
		throw Array("Array index out of bounds exception: Invalid index " + to_string(index));
	}
	return array[index];
}

class MyExceptionClass {
public:
	MyExceptionClass() {
		throw "This is a custom exception";
	}
};

void some_function() {
	
	throw runtime_error("This is a runtime error");
	int a[10];
	a[10] = 5; 
}

class CustomException : public exception {
public:
	int code;
	string message;

	CustomException(int code, const string& message) : code(code), message(message) {}

	const char* what() const throw() {
		return message.c_str();
	}
public:
	
};
void process_data() {
		try {
			
			throw CustomException(404, "No data");
		}
		catch (const CustomException& e) {
			cout << "Error  " << e.code << ": " << e.what() << endl;
		}
	}

int main()
{
	
	int num1, num2;
	cout << "Enter num1: ";
	cin >> num1;
	cout << "Enter num2: ";
	cin >> num2;
	dil(num1, num2);

	int number;
    cout << "Enter an integer: ";
	cin >> number;
    try {
		checkNumber(number);
	}
	catch (const NegativeNumberException& e) {
		cerr << "Caught an exception: " << e.what() << endl;
	}

	const int size = 5;
	int array[size] = { 1, 2, 3, 4, 5 };
	int index;
	

	cout << "Enter the index : ";
	cin >> index;

	try {
		int value = getElementAtIndex(array, size, index);
		cout << "Element at index " << index << " is " << value << endl;
	}
	catch (const Array& e) {
		cerr << "Caught an exception: " << e.what() << endl;
	}

	try {
		int numerator = 10;
		int denominator = 0;

		try {
			if (denominator == 0) {
				throw "ERROR!";
			}
			int result = numerator / denominator;
			cout << "Result: " << result << endl;
		}
		catch (const char* msg) {
			cout << "Enter corect number: " << msg << endl;
		}

		int array[5] = { 1, 2, 3, 4, 5 };
		int index = 6;

		try {
			if (index >= 5) {
				throw "This element in arreray";
			}
			int element = array[index];
			cout << "Element in arreray: " << element << endl;
		}
		catch (const char* msg) {
			cout << "ERROR: " << msg << endl;
		}
	}
	catch (...) {
		cout << "General error" << endl;
	}

	
	int size = 100; 

	try {
		int* bigArray = new int[size]; 
		cout << "Memory for the array was successfully allocated." << endl;

		for (int i = 0; i < size; ++i) {
			bigArray[i] = i * 2; 
		}

		
		int sum = 0;
		for (int i = 0; i < size; ++i) {
			sum += bigArray[i];
		}
		cout << "Sum: " << sum << endl;

		delete[] bigArray; 
		cout << "Memory for the array has been freed successfully." << endl;
	}
	catch (...) {
		cout << "Error" << endl;
	}

	try {
		MyExceptionClass ec;
	}
	catch (const exception& e) {
		cout << "An exception occurred: " << e.what() << endl;
	}

	try {
		
		some_function();
	}
	catch (runtime_error& e) {
		
		cerr << "Runtime error: " << e.what() << endl;
	}
	catch (out_of_range& e) {
		
		cerr << "Out of range error: " << e.what() << endl;
	}
	catch (...) {
		
		cerr << "Unknown error" << endl;
	}

	process_data();
}

