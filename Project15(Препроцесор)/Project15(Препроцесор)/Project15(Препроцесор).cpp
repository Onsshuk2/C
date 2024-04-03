#include "header.cpp"
#include <iostream>
using namespace std;


int main()
{
    //1
    const int SIZE = 10;
    int myArray[SIZE];
    ArrayRandom(myArray, SIZE);
    cout << "Array with random values:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << myArray[i] << " ";
    }cout << endl;

    //2
    const int SIZE1 = 20;
    int myArray1[SIZE1];
    for (int i = 0; i < SIZE1; ++i) 
    {
        myArray1[i] = i * 2;
    }
  ArrayPrint(myArray1, SIZE1);

    //3
    const int SIZE3 = 5;
    int myArray3[SIZE3] = { 5, 3, 9, 1, 7 };
    int minElement = MinElement(myArray3, SIZE3);

    if (minElement != -1) {
        cout << "Minimum element in the array: " << minElement << endl;
    }

    //5
   cout << "Sorted array in ascending order:" << endl;
   ArrayPrint(myArray1, SIZE1);

    //4
    const int SIZE4 = 10;
    int myArray4[SIZE4] = {1,11,23,52, 5, 0, 9, 8, 7,12 };

    int maxElement = MaxElement(myArray4, SIZE4);

    if (maxElement != 0) 
    {
        cout << "Minimum element in the array: " << maxElement << endl;
    }
}


