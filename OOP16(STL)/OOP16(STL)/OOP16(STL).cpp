#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Car {
private:
    string name;
    int year;
    int engineCapacity;
    double price;

public:
    Car() : name("no name"), year(0), engineCapacity(0), price(0.0) {}
    Car(string nameC, int yearC, int engineCapacityC, double priceC)
        : name(nameC), year(yearC), engineCapacity(engineCapacityC), price(priceC) {}

    string getName() const { return name; }
    int getYear() const { return year; }
    int getEngineCapacity() const { return engineCapacity; }
    double getPrice() const { return price; }

    void setName(string nameC) { name = nameC; }
    void setYear(int yearC) { year = yearC; }
    void setEngineCapacity(int engineCapacityC) { engineCapacity = engineCapacityC; }
    void setPrice(double priceC) { price = priceC; }
};

class CarDealership {
private:
    vector<Car> cars;

public:
    void addCar(const Car& car) {
        cars.push_back(car);
    }

    bool removeCar(const string& name) {
        auto it = find_if(cars.begin(), cars.end(),
            [&name](const Car& car) { return car.getName() == name; });

        if (it != cars.end()) {
            cars.erase(it);
            return true;
        }
        return false;
    }

    void displayCars() const {
        for (const Car& car : cars) {
            cout << "Name: " << car.getName() << endl;
            cout << "Year: " << car.getYear() << endl;
            cout << "Engine capacity: " << car.getEngineCapacity() << endl;
            cout << "Price: " << car.getPrice() << endl;
            cout << "-------------------------" << endl;
        }
    }

    void sortCarsByName() {
        sort(cars.begin(), cars.end(),
            [](const Car& a, const Car& b) { return a.getName() < b.getName(); });
    }

    void sortCarsByYear() {
        sort(cars.begin(), cars.end(),
            [](const Car& a, const Car& b) { return a.getYear() < b.getYear(); });
    }

    void sortCarsByEngineCapacity() {
        sort(cars.begin(), cars.end(),
            [](const Car& a, const Car& b) { return a.getEngineCapacity() < b.getEngineCapacity(); });
    }

    void sortCarsByPrice() {
        sort(cars.begin(), cars.end(),
            [](const Car& a, const Car& b) { return a.getPrice() < b.getPrice(); });
    }

    vector<Car> searchCarsByName(const string& name) const {
        vector<Car> results;
        copy_if(cars.begin(), cars.end(), back_inserter(results),
            [&name](const Car& car) { return car.getName() == name; });
        return results;
    }

    vector<Car> searchCarsByYear(int year) const {
        vector<Car> results;
        copy_if(cars.begin(), cars.end(), back_inserter(results),
            [&year](const Car& car) { return car.getYear() == year; });
        return results;
    }

    vector<Car> searchCarsByEngineCapacity(int engineCapacity) const {
        vector<Car> results;
        copy_if(cars.begin(), cars.end(), back_inserter(results),
            [&engineCapacity](const Car& car) { return car.getEngineCapacity() == engineCapacity; });
        return results;
    }

    vector<Car> searchCarsByPrice(double price) const {
        vector<Car> results;
        copy_if(cars.begin(), cars.end(), back_inserter(results),
            [&price](const Car& car) { return car.getPrice() == price; });
        return results;
    }
};

int main() {
    CarDealership dealership;

    Car car1("Toyota", 2015, 2000, 15000.0);
    Car car2("Honda", 2018, 2500, 20000.0);
    Car car3("Ford", 2020, 3000, 25000.0);

    dealership.addCar(car1);
    dealership.addCar(car2);
    dealership.addCar(car3);

    dealership.displayCars();

    dealership.sortCarsByYear();
    dealership.displayCars();

    vector<Car> results = dealership.searchCarsByPrice(20000.0);
    for (const Car& car : results) {
        cout << "Name: " << car.getName() << endl;
        cout << "Year: " << car.getYear() << endl;
        cout << "Engine capacity: " << car.getEngineCapacity() << endl;
        cout << "Price: " << car.getPrice() << endl;
        cout << "-------------------------" << endl;
    }

    bool removed = dealership.removeCar("Ford");
    cout << "Car removed: " << (removed ? "true" : "false") << endl;

    dealership.displayCars();

    
}