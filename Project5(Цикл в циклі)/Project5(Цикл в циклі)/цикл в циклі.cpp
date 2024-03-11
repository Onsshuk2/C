#include <iostream>
using namespace std;

int main()

{  
	//Ex1
	int choice;
	cout << "Enter number from 1 to 10: " << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				if (i == j || j > i)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 2:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				if (i == j || j < i)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 3:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				int N = 10;
				if (j > i && i + j < N - 1)  
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 4:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				int N = 10;
				if  (j < i && i + j > N - 1)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 5:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				int N = 10;
				if (((j > i && i + j < N - 1) || (j < i && i + j > N - 1)) || i == j || i + j == N - 1)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 6:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				int N = 10;
				if (((j > i && i + j > N - 1) || (j < i && i + j < N - 1)) || i == j || i + j == N - 1)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 7:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				int N = 10;
				if (j > i && i + j > N - 1) 
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 8:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				int N = 10;
				if  (j < i && i + j < N - 1)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 9:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				int N = 10;
				if (( i + j < N - 1)  || i + j == N - 1)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 10:
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				int N = 10;
				if ((i + j > N - 1) || i + j == N - 1)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	default:
		break;
	}

	////Ex2.1
	//int number,digitCount,digitSum,zeroCount;
	//cout << "Enter number: ";
	//cin >> number;
	// digitCount=1 ;
	// digitSum=0 ;
	// zeroCount =0;

	//while (number != 0) {
	//	int digit =number % 10;
	//	digitCount++;
	//	digitSum += digit;
	//	if (digit == 0) {
	//		zeroCount++;
	//	}
	//	number /= 10;
	//}

	//
	//int average = digitSum / digitCount;

	//
	//cout << "Count digit: " << digitCount << endl;
	//cout << "Sum: " << digitSum << endl;
	//cout << "Arithmetic: " << average << endl;
	//cout << "Null: " << zeroCount << endl;

	//
	////Ex2.2
	//int width, height;
	//cout << "Enter width: ";
	//cin >> width;
	//cout << "Enter height: ";
	//cin >> height;

	//for (int i = 0; i < height; i++) {
	//	for (int j = 0; j < width; j++) {
	//		cout << "***___";
	//	}
	//	cout << endl;
	//}
}