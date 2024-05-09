#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
    T* data;
    int size;
    int capacity;
    int grow;

public:
    Array(int initialCapacity = 10, int growBy = 1) : size(0), capacity(initialCapacity), grow(growBy) {
        if (initialCapacity <= 0 || growBy <= 0) {
            cerr << "Error: Capacity and grow must be positive." << endl;
            
        }
        data = new T[capacity];
    }

    ~Array() {
        delete[] data;
    }

    int GetSize() const {
        return size;
    }

    void SetSize(int newSize, int growBy = 1) {
        if (newSize < size) {
            size = newSize;
        }
        else {
            while (capacity < newSize) {
                capacity += growBy;
            }
            T* newData = new T[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            size = newSize;
        }
    }

    int GetUpperBound() const {
        return size - 1;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    void FreeExtra() {
        if (size < capacity) {
            capacity = size;
            T* newData = new T[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
    }

    void RemoveAll() {
        delete[] data;
        data = new T[capacity];
        size = 0;
    }

    T GetAt(int index) const {
        if (index < 0 || index >= size) {
            cerr << "Error: Index out of range." << endl;
            
        }
        return data[index];
    }

    void SetAt(int index, const T& value) {
        if (index < 0 || index >= size) {
            cerr << "Error: Index out of range." << endl;
            
        }
        data[index] = value;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            cerr << "Error: Index out of range." << endl;
            
        }
        return data[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) {
            cerr << "Error: Index out of range." << endl;
            
        }
        return data[index];
    }

    void Add(const T& value) {
        if (size >= capacity) {
            SetSize(size + grow);
        }
        data[size++] = value;
    }

    void Append(const Array& other) {
        int newSize = size + other.size;
        SetSize(newSize);
        for (int i = 0; i < other.size; i++) {
            data[size++] = other.data[i];
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            size = other.size;
            grow = other.grow;
            data = new T[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    T* GetData() const {
        return data;
    }

    void InsertAt(int index, const T& value) {
        if (index < 0 || index > size) {
            cerr << "Error: Index out of range." << endl;
            
        }
        if (size >= capacity) {
            SetSize(size + grow);
        }
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= size) {
            cerr << "Error: Index out of range." << endl;
            
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }
};

int main() {
    Array<int> intArray(5, 5);
    intArray.Add(1);
    intArray.Add(2);
    intArray.Add(3);
    intArray.Add(4);
    intArray.Add(5);
    intArray.Add(6);
    intArray.SetAt(6, 7);

    if (intArray.GetSize() > 1) {
        cout << "Element at index 1: " << intArray.GetAt(1) << endl;
    }
    else {
        cerr << "Error: Array size is too small." << endl;
        
    }

    
}
//зробила дз щось воно не пішло , закинула в чат jpt, воно мені виправило , замінило cout на cerr, але всеодно якась помилка при запуску , можливо щось не так з виділенням і очисткою памяті? 
