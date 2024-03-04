#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	//Ex1.1
	int usernumber;
	int digit1, digit2, digit3, digit4, digit5, digit6;

	cout << "enter a six-digit number: ";
	cin >> usernumber;

	if (usernumber >= 100000 && usernumber <= 999999)
	{
		cout << "a number is six-digit" << endl;
	}
	else
		cout << "enter corect number";

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
		cout << "number isn't lucky";
	}

	//Ex1.2
	int usernumber1;
	int digit01, digit02, digit03, digit04;

	cout << "enter a four-digit number: ";
	cin >> usernumber1;

	if (usernumber1 >= 1000 && usernumber1 <= 9999)
	{
		cout << "a number is four-digit" << endl;
	}
	else
		cout << "enter corect number" << endl;

	digit01 = usernumber1 / 1000 % 10;
	digit02 = usernumber1 / 100 % 10;
	digit03 = usernumber1 / 10 % 10;
	digit04 = usernumber1 / 1 % 10;
	 
	cout << digit02;
	cout << digit01;
	cout << digit04;
	cout << digit03;
	
	//Ex1.3
	int num1, num2, num3, num4, num5, num6, num7;
	cout << "enter 7 numbers: ";
	cin >> num1;
	cin >> num2;
	cin >> num3;
	cin >> num4;
	cin >> num5;
	cin >> num6;
	cin >> num7;
	int max = num1;
	if (num2 > max) max = num2;
	if (num3 > max) max = num3;
	if (num4 > max) max = num4;
	if (num5 > max) max = num5;
	if (num6 > max) max = num6;
	if (num7 > max) max = num7;
	cout << "max number: " << max << endl;

	//Ex1.4
	int pointab, pointbc, weight;
	
	cout << "enter the distance from point a to point b: ";
	cin >> pointab;
	cout << "enter the distance from point b to point c: ";
	cin >> pointbc;
	cout << "enter cargo weight: ";
	cin >> weight;

	int consumption;
	if (weight <= 500) consumption = 1;
	else if (weight <= 1000) consumption = 4;
	else if (weight <= 1500) consumption = 7;
	else if (weight <= 2000) consumption = 9;
	else {
		cout << "An airplane can't lift that kind of weight" << endl;
		
	}

	int fuelNeededForAB = pointab * consumption;
	int fuelNeededForBC = pointbc * consumption;
	int totalFuelNeeded = fuelNeededForAB + fuelNeededForBC;
	int fuelRefill = 0;

	if (fuelNeededForAB > 300 || fuelNeededForBC > 300) {
		cout << "It is impossible to overcome the route with a given load." << endl;
		
	}
	else if (totalFuelNeeded > 300) {
		fuelRefill = fuelNeededForBC - (300 - fuelNeededForAB);
	}

	cout << "Minimum amount of fuel for refueling at point B: " << fuelRefill << "l" << endl;

	


//Ex2.2 
	const int SALARY = 200;
	int sales, sales2, sales3 ;
	cout << "Enter sum of firs manegire sales : " << endl;
	cin >> sales;
	cout << "Enter sum of second manegire sales : " << endl;
	cin >> sales2;
	cout << "Enter sum of thirt manegire sales : " << endl;
	cin >> sales3;
	if (sales > 100)
	{
		cout << "Your full salary1 = " << sales / 100 * 8 + SALARY << endl;
	}
	else if (sales > 500)
	{
		cout << "Your full salary1 = " << sales / 100 * 5 + SALARY << endl;
	}
	else
	{
		cout << "Your full salary1 = " << sales / 100 * 3 + SALARY << endl;
	}

	if (sales2 > 100)
	{
		cout << "Your full salary2 = " << sales2 / 100 * 8 + SALARY << endl;
	}
	else if (sales2 > 500)
	{
		cout << "Your full salary2 = " << sales2 / 100 * 5 + SALARY << endl;
	}
	else
	{
		cout << "Your full salary2 = " << sales2 / 100 * 3 + SALARY << endl;
	}

	if (sales3 > 100)
	{
		cout << "Your full salary3 = " << sales3 / 100 * 8 + SALARY << endl;
	}
	else if (sales3 > 500)
	{
		cout << "Your full salary3 = " << sales3 / 100 * 5 + SALARY << endl;
	}
	else
	{
		cout << "Your full salary3 = " << sales3 / 100 * 3 + SALARY << endl;
	}

	int max = sales;
	if (sales2 > max) max = sales2;
	if (sales3 > max) max = sales3;
	
	cout << "The best manegir: " << max/100*8+SALARY+200<<"$" << endl;
	
//Ex2.1
int date1, date2,date3 ;
int dayStart, dayFinish;
int monthStart, monthFinish;
int yearStart, yearFinish;

cout << "Enter first day: ";
cin >> dayStart;
if (dayStart > 32) { cout << "Enter corect date (1-31)"; }
cout << "Enter first mouth: ";
cin >> monthStart;
if (monthStart > 13) { cout << "Enter corect date (1-12)"; }
cout << "Enter first year: ";
cin >> yearStart;


cout << "Enter end day: ";
cin >> dayFinish;
if (dayFinish > 32) { cout << "Enter corect date (1-31)"; }
cout << "Enter end mouth: ";
cin >> monthFinish;
if (monthFinish > 13) { cout << "Enter corect date (1-12)"; }
cout << "Enter end year: ";
cin >> yearFinish;


cout << "First date: " << dayStart<<"/"<<monthStart<<"/"<<yearStart << endl;

cout << "End date: " << dayFinish << "/" << monthFinish << "/"<<yearFinish << endl;

date1 = dayStart - dayFinish;
date2 = monthStart - monthFinish;
date3 = yearStart - yearFinish;

cout << "Difference between dates: " << abs(date1) << "/" << abs(date2) << "/" << abs(date3) << endl;







}