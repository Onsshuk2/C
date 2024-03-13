#include <iostream>
#include <cmath>
#include <iomanip>




using namespace std;
//Ex1.1
int degree(int number, int num)
{
	return pow(number, num);
}

//Ex1.2
int sum(int num1, int num2)
{
	int summ=0;
	for (size_t i = num1 + 1; i < num2; i++)
	{
		summ += i;
	}return summ;
}

//Ex1.3
void findPerfectNumbers(int start, int end) 
{
	
	for (int numm = start; numm <= end; ++numm) 
	{
		int sum0 = 0;
		for (int i = 1; i < numm; ++i) 
		{
			if (numm % i == 0) 
			{
				sum0 += i;
			}
		}
		if (sum0 == numm) 
		{
			cout << "Perfect number: "<< numm << " ";
		}
	}
	cout <<endl;
}
//Ex1.4
void showCard(int suit, int num) {
	
	char suits[] = {1,2,3,4};
	char ranks[] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K' };

	cout << " _________" << endl;
	cout << "| " << ranks[num - 1] << setw(2) << suits[suit - 1] << "     |" << endl;
	cout << "|         |" << endl;
	cout << "|         |" << endl;
	cout << "|    " << suits[suit - 1] << "    |" << endl;
	cout << "|         |" << endl;
	cout << "|         |" << endl;
	cout << "|      "<< ranks[num - 1] << setw(2) << suits[suit - 1] << "|" << endl;
	cout << " ---------" << endl;
}


//Ex1.5
int luckyNumber(int usernumber)
{
	int digit1, digit2, digit3, digit4, digit5, digit6;
	if (usernumber >= 100000 && usernumber <= 999999)
	{
		cout << "a number is six-digit" << endl;
	}
	else
	{
	cout << "enter corect number";
	}

	digit1 = usernumber / 100000 % 10;
	digit2 = usernumber / 10000 % 10;
	digit3 = usernumber / 1000 % 10;
	digit4 = usernumber / 100 % 10;
	digit5 = usernumber / 10 % 10;
	digit6 = usernumber / 1 % 10;

	if ((digit1 + digit2 + digit3) == (digit4 + digit5 + digit6))
	{
		cout << "number is lucky";
	}
	else
	{
		cout << "number isn't lucky" << endl;
	}
	return usernumber;
}

int main()
{
	/*int number, num;
	cout << "Enter number: ";
	cin >> number;
	cout << "Enter degree: ";
	cin >> num;
	cout << "Number in degree=" << degree(number, num) << endl;

	int num1, num2;
	cout << "Enter number1: ";
	cin >> num1;
	cout << "Enter number2: ";
	cin >> num2;
	cout << "Sum from num1 to num2: "<< sum(num1, num2) << endl ;
	
	int usernumber;
	cout << "Enter 6-digit number: ";
	cin >> usernumber;
	luckyNumber(usernumber);

	int start, end;
	cout << "Enter start: ";
	cin >> start;
	cout << "Enter end: ";
	cin >> end;

	findPerfectNumbers(start, end);*/

	int suit, num;

	cout << "Enter suit (1-Hearts, 2-Diamonds, 3-Clubs, 4-Spades): ";
	cin >> suit;

	cout << "Enter card number (1-Ace, 2-10, 11-Jack, 12-Queen, 13-King): ";
	cin >> num;

	showCard(suit, num);

}