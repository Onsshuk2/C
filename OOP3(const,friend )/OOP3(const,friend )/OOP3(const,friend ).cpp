#include <iostream>
using namespace std;

//Ex1
class Overcoat 
{
    string type;
    int size;
    int price;
public:
    Overcoat(string type, int size, int price) :type {type}, size{ size }, price{ price } {}

    void Show()const
    {
        cout << " Type: " << type << " Size: " << size << " Price: "<< price << endl;
    }

  
    Overcoat& operator=( Overcoat& other)
 {
          this->size = other.size;
          return *this;
 } 
    
    
    friend bool operator==(const Overcoat& o1, const Overcoat& o2);
    friend bool operator>(const Overcoat& o1, const Overcoat& o2);
};

 bool operator==(const Overcoat& o1, const Overcoat& o2)
    {
        return o1.type==o2.type;
    }

 

bool operator>(const Overcoat& o1, const Overcoat& o2)
 {
     return o1.price > o2.price;
 }

//Ex2
class Flat
{
    float area;
    int object;
    int price1;
public:
    Flat (float area, int object, int price1) :area{ area }, object{ object }, price1{ price1 } {}

    void Show1()const
    {
        cout << " Area: " << area << " Object: " << object << " Price: " << price1 << endl;
    }


    Flat& operator=(Flat& other)
    {
        this->object = other.object;
        return *this;
    }


    friend bool operator==(const Flat& f1, const Flat& f2);
    friend bool operator>(const Flat& f1, const Flat& f2);
};

bool operator==(const Flat& f1, const Flat& f2)
{
    return f1.area == f2.area;
}



bool operator>(const Flat& f1, const Flat& f2)
{
    return f1.price1 > f2.price1;
}


int main()
{
    //Ex1
    Overcoat o1("Top",31,4);
    o1.Show();
    Overcoat o2("Top", 22, 4);
    o2.Show();


    o1 = o2;
    cout << "New size: ";
    o1.Show();

    bool abc = o1 == o2;
    cout << "If you see 1 - type are the same, 0 - type aren't the same: "<< abc << endl;
    
    if (o1 > o2)
    {
        cout << "Top1 more expencive";
    }
    else
    {
        cout << "Top1 the cheapest";
    }cout << endl;

    cout << "__________________________________________________________" << endl;
    //Ex2
    Flat f1(32.3, 31, 4);
    f1.Show1();
    Flat f2(33.4, 22, 4);
    f2.Show1();


    f1 = f2;
    cout << "New object: ";
    f1.Show1();

    bool abc1 = f1 == f2;
    cout << "If you see 1 - type are the same, 0 - type aren't the same: " << abc1 << endl;

    if (f1 > f2)
    {
        cout << "Flat1 more expencive";
    }
    else
    {
        cout << "Flat1 the cheapest";
    }

    
}


