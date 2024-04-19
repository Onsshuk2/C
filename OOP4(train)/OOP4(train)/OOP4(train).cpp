#include <iostream>
using namespace std;

struct Carriage
{
    int number;
    int place;
    int passen;
};

class Train
{

    const int maxCarriage;
    string model;
    int carriageCount;
    Carriage* carriage;

public:
    Train() : model{ "No" }, carriageCount{ 0 }, carriage{ nullptr }, maxCarriage{ 0 } {}
    Train(string mod, int maxCar) : model{ mod }, maxCarriage{ maxCar } {};
   
    Train(const Train& other) : model{ other.model }, maxCarriage{ other.maxCarriage } {
        carriageCount = other.carriageCount;
        carriage = new Carriage[maxCarriage];
        for (int i = 0; i < carriageCount; i++) {
            carriage[i] = other.carriage[i];
        }
    }
    
    ~Train() {
        delete[] carriage;
    }

    void ShowCarriage() const
    {
        cout << "Train: " << model << endl;
        cout << "Carriages: " << carriageCount << endl;
        for (int i = 0; i < carriageCount; i++)
        {
            cout << "Number: " << carriage[i].number << " Passengers: " << carriage[i].passen << endl;
        }
    }
    void AddCarriage(const Carriage& newCarriage)
    {
        if (carriageCount < maxCarriage)
        {
            Carriage* tempArr = new Carriage[carriageCount + 1];
            for(int i=0;i<carriageCount;i++)
            {
                tempArr[i] = carriage[i];
            }
            tempArr[carriageCount] = newCarriage;
            if(carriage!=nullptr)
            {
                delete[]carriage;
            }
			carriage = tempArr;

        }
        else
        {
            cout << "Cannot add more carriages. Maximum limit reached." << endl;
        }
    }

    
    
    
    void AddPassenger(int carriageNum)
    {
        if (carriageNum >= 0 && carriageNum < carriageCount)
        {
            carriage[carriageNum].passen++;
        }
        else
        {
            cout << "Invalid carriage number." << endl;
        }
    }
};


int main()
{
    Train train("Express", 3);
    Carriage c1 = { 1, 50, 0 };
    Carriage c2 = { 2, 60, 0 };

    train.AddCarriage(c1);
    train.AddCarriage(c2);

    train.AddPassenger(0);
    train.AddPassenger(1);

    train.ShowCarriage();

    Train copiedTrain = train; 
    copiedTrain.ShowCarriage();
    
}

