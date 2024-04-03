#include <iostream>
using namespace std;

//Ex1
struct number 
{
    float a;
    float b;

};
//Ex2

struct automobile
{
    float length;
    float height;
    float volume;
    float power;
    int D;
    char color;
    char transmission;

};
automobile value(float len, float heig, float vol, float pow, int d, char col, char trans)
{
    automobile car;
    car.length = len;
    car.height = heig;
    car.volume = vol;
    car.power = pow;
    car.D = d;
    car.color = col;
    car.transmission = trans;
    return car;

}
void enterCarDetails(automobile& car) {
    cout << "Enter car length: ";
    cin >> car.length;
    cout << "Enter car height: ";
    cin >> car.height;
    cout << "Enter car volume: ";
    cin >> car.volume;
    cout << "Enter car power: ";
    cin >> car.power;
    cout << "Enter car D: ";
    cin >> car.D;
    cout << "Enter car color: ";
    cin >> car.color;
    cout << "Enter car transmission: ";
    cin >> car.transmission;
}
void displayCarInfo(const automobile& car) 
{
   cout << "Car Details:" << endl;
   cout << "Length: " << car.length << endl;
   cout << "Height: " << car.height << endl;
   cout << "Volume: " << car.volume << endl;
   cout << "Power: " << car.power << endl;
   cout << "Diameter: " << car.D << endl;
   cout << "Color: " << car.color << endl;
   cout << "Transmission: " << car.transmission << endl;
}
void searchCar(const automobile& car, char searchKey, char searchValue) {
    switch (searchKey) {
    case 'L':
        if (car.length == searchValue) {
            displayCarInfo(car);
        }
        break;
    case 'H':
        if (car.height == searchValue) {
            displayCarInfo(car);
        }
        break;
    case 'V':
        if (car.volume == searchValue) {
            displayCarInfo(car);
        }
        break;
    case 'P':
        if (car.power == searchValue) {
            displayCarInfo(car);
        }
        break;
    case 'D':
        if (car.D == searchValue) {
            displayCarInfo(car);
        }
        break;
    case 'C':
        if (car.color == searchValue) {
            displayCarInfo(car);
        }
        break;
    case 'T':
        if (car.transmission == searchValue) {
            displayCarInfo(car);
        }
        break;
    default:
        cout << "Invalid search key." << endl;
        break;
    }
}
int main()
{
    //Ex1

    number num1, num2;
    cout << "Enter first number: ";
    cin >> num1.a;
    cout << "Enter second number: ";
    cin >> num2.b;
    cout << "Sum: " << num1.a + num2.b << endl;
    cout << "Difference: " << num1.a - num2.b << endl;
    cout << "Multiplication: " << num1.a * num2.b << endl;
    cout << "Division: " << num1.a / num2.b << endl;

    //Ex2
    
    automobile myCar;
    enterCarDetails(myCar);
    displayCarInfo(myCar);

    char searchKey;
    char searchValue;
    cout << "Enter search key (L/H/V/P/D/C/T): ";
    cin >> searchKey;
    cout << "Enter search value: ";
    cin >> searchValue;

    searchCar(myCar, searchKey, searchValue);
    
   
   
}

