#include <iostream>
#include <fstream>
using namespace std;



class Equation {
public:
    virtual ~Equation() = default;
    virtual void calculateRoots(double roots[], int& numRoots) const = 0;
};

class LinearEquation : public Equation {
private:
    double a;
    double b;

public:
    LinearEquation(double a, double b) : a(a), b(b) {}

    void calculateRoots(double roots[], int& numRoots) const override {
        if (a == 0) {
            cout << "Coefficient 'a' cannot be zero in a linear equation." << endl;
            numRoots = 0;
        }
        else {
            roots[0] = -b / a;
            numRoots = 1;
        }
    }
};

class QuadraticEquation : public Equation {
private:
    double a;
    double b;
    double c;

public:
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    void calculateRoots(double roots[], int& numRoots) const override {
        if (a == 0) {
            cout << "Coefficient 'a' cannot be zero in a quadratic equation." << endl;
            numRoots = 0;
            return;
        }

        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            cout << "The equation has no real roots." << endl;
            numRoots = 0;
        }
        else if (discriminant == 0) {
            roots[0] = -b / (2 * a);
            numRoots = 1;
        }
        else {
            double sqrt_discriminant = sqrt(discriminant);
            roots[0] = (-b + sqrt_discriminant) / (2 * a);
            roots[1] = (-b - sqrt_discriminant) / (2 * a);
            numRoots = 2;
        }
    }
};


class Shape {
public:
    virtual ~Shape() = default;

    virtual void Show() const = 0;
    virtual void Save(const string& filename) const = 0;
    virtual void Load(const string& filename) = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r = 0) : radius(r) {}

    void Show() const override {
        cout << "Circle with radius: " << radius << endl;
    }

    void Save(const string& filename) const override {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << "Circle " << radius << endl;
            outFile.close();
        }
        else {
            cerr << "Unable to open file for saving!" << endl;
        }
    }

    void Load(const string& filename) override {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            string type;
            inFile >> type >> radius;
            if (type != "Circle") {
                cerr << "Invalid shape type in file!" << endl;
            }
            inFile.close();
        }
        else {
            cerr << "Unable to open file for loading!" << endl;
        }
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w = 0, double h = 0) : width(w), height(h) {}

    void Show() const override {
        cout << "Rectangle with width: " << width << ", height: " << height << endl;
    }

    void Save(const string& filename) const override {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << "Rectangle " << width << " " << height << endl;
            outFile.close();
        }
        else {
            cerr << "Unable to open file for saving!" << endl;
        }
    }

    void Load(const string& filename) override {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            string type;
            inFile >> type >> width >> height;
            if (type != "Rectangle") {
                cerr << "Invalid shape type in file!" << endl;
            }
            inFile.close();
        }
        else {
            cerr << "Unable to open file for loading!" << endl;
        }
    }
};



int main()
{
    LinearEquation le(2, -4);
    double linearRoots[1];
    int numLinearRoots;
    le.calculateRoots(linearRoots, numLinearRoots);

    cout << "Linear Equation Roots:" << endl;
    for (int i = 0; i < numLinearRoots; ++i) {
        cout << linearRoots[i] << endl;
    }

    QuadraticEquation qe(1, -3, 2);
    double quadraticRoots[2];
    int numQuadraticRoots;
    qe.calculateRoots(quadraticRoots, numQuadraticRoots);

    cout << "Quadratic Equation Roots:" << endl;
    for (int i = 0; i < numQuadraticRoots; ++i) {
        cout << quadraticRoots[i] << endl;
    }

    Shape* shapes[] = {
        new Circle(5.0),
        new Rectangle(3.0, 4.0)
    };

    for (Shape* shape : shapes) {
        shape->Show();
        shape->Save("shape.txt");
        shape->Load("shape.txt");
        shape->Show();
        delete shape;
    }

}

