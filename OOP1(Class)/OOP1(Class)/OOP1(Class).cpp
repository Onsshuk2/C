#include <iostream>
using namespace std;

class Fraction
{
private:
    int a;
    int b;

public:
    void initNumber()
    {
        cout << "Enter the first number: ";
        cin >> a;
        cout << "Enter the second number: ";
        cin >> b;
    }

    void addition()
    {
        int sum;
        sum = a + b;
        cout << "Addition of number: " << sum << endl;
    }

    void subtraction()
    {
        int sub;
        sub = a - b;
        cout << "Subtraction of number: " << sub << endl;
    }

    void multiplication()
    {
        int mul;
        mul = a * b;
        cout << "Multiplication of number: " << mul << endl;
    }

    void division()
    {
        int div;
        div = a / b;
        cout << "Multiplication of number: " << div << endl;
    }

};



int main()
{
    Fraction num;
    num.initNumber();
    num.addition();
    num.subtraction();
    num.multiplication();
    num.division();
    
}

