#include <iostream>
#include <cmath>
using namespace std;

int main()
{
//Ex1.1
	int num1, sum1=0;
	cout << "enter start nummer: ";
	cin >> num1;
	
	for (int i = num1; i < 500; i++)
		sum1 = sum1+i;
	{
		cout << " sum of numbers: " << sum1 << endl;
	}
//Ex1.2
	int x, y;
	cout << "enter first nummer: ";
	cin >> x;
	cout << "enter second nummer: ";
	cin >> y;
	cout << "x  in pow y =  " << pow(x, y) << endl;
//Ex1.3
	float number1, number2, sum, arithmetic;
	number1 = 1;
	number2 = 1000;
	sum = 0;
       for (int i = number1; i <= number2; i++)
			sum = sum + i;
	arithmetic = sum / 1000;
	cout << "Arithmetic mean: " << arithmetic << endl;
//Ex1.4
	int a, sum0 = 1;
	cout << "Enter nummer from 1 to 20: ";
	cin >> a;

	for (int i = a; i <=20; i++)
		sum0 = sum0 * i;
	{
		cout << " Sum of Numbers: " << sum0 << endl;
	}
	//Ex1.5
	int variant;
	cout << "Enter number: ";
	cin >> variant;
	for (int i = variant; i <= 10; i++)
		
	{
		cout << variant << " * " << i << " = " << variant * i << endl;
		
	}
	//Ex2.1
	
	int count = 0;
	int hundreds, tens, ones;
	cout << "Count number with two identical digit: ";
        
	for (int i = 100; i < 1000; i++)
	{
		hundreds = i / 100;
		tens = (i / 10) % 10;
		ones = i / 10;
		
		if ((hundreds == tens && hundreds != ones) || (hundreds == ones && hundreds != tens) || (ones == tens && tens != hundreds))
		{
            

			 count++;
			
		}
	}cout << count << " ";

	//Ex2.2
	int count1 = 0;
	int hundreds1, tens1, ones1;
	cout << "count number with two identical digit: ";

	for (int i = 100; i < 1000; i++)
	{
		hundreds1 = i / 100;
		tens1 = (i / 10) % 10;
		ones1 = i / 10;
		
		if ((hundreds1 != tens1) && ( hundreds1 != ones1) && (tens1 != ones1))
		{
           count1++;
			
	    }
		
	}cout  << count1 << " "<< endl;
	//Ex2.3
	
		int inputNumber;
		cout << "Enter number: ";
		cin >> inputNumber;

		int resultNumber = 0;
		int multiplier = 1;
		bool hasThreeOrSix = false;

		while (inputNumber != 0) 
		{
			int currentDigit = inputNumber % 10;
			if (currentDigit != 3 && currentDigit != 6)
			{

				resultNumber += currentDigit * multiplier;
				multiplier *= 10;
			}
			else
			{
				hasThreeOrSix = true;
			}
			inputNumber /= 10;
		}

		if (hasThreeOrSix) 
		{
			cout << "Number without 6 or 3: " << resultNumber << endl;
		}
		else 
		{
			cout << "Enter corect number" << endl;
		}

	
	//Ex2.4
	int a;
	cout << "Enter number:";
	cin >> a;
	for (size_t b = 1; b < 5000; b++)
	{
		if (a % (b * b) == 0 && a % (b * b * b)!=0)
		{
			cout << b << " ";
	    }
	}

	
	//Ex2.5
	int a, numb,sum=0;
	cout << "enter number:";
	cin >> a;
	do 
	{
		numb = a % 10;
		sum += numb;
		a /= 10;
	} while (numb > 0);
	cout << sum << endl;
	a* a == sum * sum ? cout << true << endl : cout << false << endl;
	
	
	//Ex2.6
	int n;
	cout << "Enter number: ";
	cin >> n;
	cout << "Multiplex number: ";
	for (int i = 0; i < 100; i++)
	{
		if (i % n == 0)
			cout << i << " "; 
		   
	}
	//Ex2.7
	int n1,n2;
	cout << "enter number1: ";
	cin >> n1;
	cout << "enter number2: ";
	cin >> n2;
	cout << "multiplex numbers: ";
	for (int i = 0; i < 100; i++)
	{
		if (i % n1  == 0 && i % n2 == 0)
		{
           cout << i << " ";
		}
			

	}





	

}