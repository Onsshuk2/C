#include<iostream>

using namespace std;
int main()
{//Ex1.1
	/*int distance, time,s;
	cout << "Enter distance: " ;
	cin >> distance;
	cout << "Enter time: ";
	cin >> time;
	s = distance / time;
	cout << "Speed of movement: " << s << endl;*/
//Ex1.2
	/*int hour1, minute1, second1, sum;
	int hour2, minute2, second2;
	int hour01, hour02, minute01, minute02, second01, second02;
	int minuteStart, minuteFinish, minute;
	cout << "Enter start in hour, minute, second: ";
	cin >> hour1;
	cin >> minute1;
	cin >> second1;

	cout << "Enter finish in hour, minute, second: ";
	cin >> hour2;
	cin >> minute2;
	cin >> second2;

	hour01 = hour1 * 60;
	second01 = second1 / 60;

	hour02 = hour2 * 60;
	second02 = second2 / 60;

	minuteStart = hour01 + minute1 + second01;
	minuteFinish = hour02 + minute2 + second02;

	minute = minuteFinish - minuteStart;

	sum = minute * 2;

	cout << "The cost of the trip: " << sum << endl;*/
//Ex3.1
	/*int distance, distribution0, distribution, price1,price2,price3;
	int cost1, cost2, cost3;
	
	cout << "Enter distance: ";
	cin >> distance;
	cout << "Enter gasolline distribution on 100km: ";
	cin >> distribution0;
	cout << "Enter price1: ";
	cin >> price1;
	cout << "Enter price2: ";
	cin >> price2;
	cout << "Enter price3: ";
	cin >> price3;

	distribution = distribution0 * distance / 100;

	cost1 = distribution * price1;
	cost2 = distribution * price2;
	cost3 = distribution * price3;
	
	cout << "If price=" << price1 << "; cost=" << cost1 << endl ;
	cout << "If price=" << price2 << "; cost=" << cost2 << endl;
	cout << "If price=" << price3 << "; cost=" << cost3 << endl;*/
	//Ex2.1
	/*int allTime = 86400;
	int hourStart=12,minuteStart=0, secondStart=0 ;
	int hourFinish = 12, minuteFinish = 0, secondFinish = 0;
	int leftTime, currentTime1;
	int minute1, second1, hour1;
	int minute0, second0, hour0;
	int minute, second, hour;

	cout << "Enter time with begine day,s: ";
	cin >> leftTime;

	currentTime1 = allTime - leftTime;
	
	hour1 = leftTime / (60 * 60);
	minute1 = (leftTime / 60) % 60;
	second1 = leftTime % 60;

	hour = hourStart - hour1;
	minute = minuteStart - minute1;
	second = secondStart - second1;
	
	hour0 = hourFinish + hour1;
	minute0 = minuteFinish + minute1;
	second0 = secondFinish + second1;

    cout << "Current time - " << hour << ":" << minute << ":" << second << endl;
	cout << "Time to 00:00 - " << hour0 << ":" << minute0<< ":" << second0 << endl;*/
	//Ex2.2
	int allWorkTime = 8;
	int time, lastTime;
	int hourWork;
	
	cout << "Enter time with begine day,s: ";
	cin >> time;
    hourWork = time / (60 * 60);
	lastTime = allWorkTime - hourWork;
    cout << "You have to work - " << lastTime << " hour" << endl;
	

	

	

}










