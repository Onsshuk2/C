#include<iostream>

using namespace std;

int main()
{//EX1.1
    float x = 2, y = 4, z = 8;
    cout << "1/R0=1/R1+1/R2+1/R3=" << (x * y * z) / (y * z + x * z + x * y) << endl;
    //EX1.2
    float p = 3.14, l = 3;
    float r = (l) / (2 * p);
    cout << "S=2*pi*R=" << r * 2 * p << endl;
    //EX1.3
    float v = 2, t = 4, a = 8;
    cout << "S = v*t + (a * t2) / 2 =" << v * t + (a * 2 * t) / 2 << endl;
    //EX2.1
    float number;
    cout << "Enter number in seconds: ";
    cin >> number;
    cout << "Minutes:" << number / 60 << endl;
    cout << "Hour:" << number / 3600 << endl;
    //EX2.2
    float num1;
    cout << "Enter number: ";
    cin >> num1;
    int grn = float(num1);
    int kop = float((num1 - grn) * 100);
    cout << "Sum: " << grn << " grn " << kop << " kop" << endl;
    //EX2.3
    cout << "Calculation of running speed " << endl;
    float distance, time;
    cout << "Enter the length of distance,m: ";
    cin >> distance;
    cout << "Enter the time,hv : ";
    cin >> time;
    cout << "Distance: " << distance << "m" << endl;
    int hv = float(time);
    int sec = float((time - hv) * 100);
    int time1 = time * 60;
    cout << "Time: " << hv << " hv " << sec << " sec = " << time1 << "s" << endl;
    float dis = (distance / 100);
    float time2 = (time1 / 60);
    cout << "You ran fast " << dis / time2 << " km/hour";
    //EX2.4
    int day0, week, day;
    cout << "enter day: ";
    cin >> day0;
    week = day0 / 7;
    day = day0 % 7;
    cout << "week and day: " << week << " week " << day << " day" << endl;
}