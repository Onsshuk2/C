#include "header.h"
#include <iostream>
#include <ctime>

using namespace std;

void ArrayRandom(int array[], int size)
{
    srand(time(nullptr));

    for (int i = 0; i < size; ++i) {
        array[i] = rand();
    }
}

void ArrayPrint(int arr[], int size1)
{
    for (int i = 0; i < size1; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

void bubbleSort(int arr[], int size1)
{
    for (int i = 0; i < size1 - 1; ++i) {
        for (int j = 0; j < size1 - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}



int MinElement(int arr3[], int size3)
{

    int minElement = arr3[0];
    for (int i = 1; i < size3; i++)
    {
        if (arr3[i] < minElement)
        {
            minElement = arr3[i];
        }
        return minElement;
    }
}

int MaxElement(int arr4[], int size4)
{
    int maxElement = arr4[0];
    for (int i = 1; i < size4; i++)
    {
        if (arr4[i] > maxElement)
        {
            maxElement = arr4[i];
        }
        return maxElement;
    }
}