#include <iostream>
using namespace std;

void sayHello()
{
	cout << "Hello" << endl;

}
void sayGood()
{
	cout << "Good" << endl;

}

int retSum(int a, int b)
{
	return a + b;

}

int main()
{

	

	sayHello();
	cout << sayHello << endl;
	cout << &sayHello << endl;
	int (*funcPtr)(int, int);
	int* (*funcPtr)(int, int);
	funcPtr = retSum;
	void (*helloPtr)();
	helloPtr = sayHello;
	
	void (*arrFunct[2])() {sayGood,sayHello};
	 ((*helloPtr)());

	 auto result = retSum(22, 22);
	 cout << result << endl;
}

