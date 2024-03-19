#include<iostream>
using namespace std;

int main()
{
	//Ex1
	int arr1[5]{1,2,3,4,5 };
	int arr2[10]{0};
	
	int *parr1=arr1;
	int *parr2=arr2;

	for (size_t i = 0; i < 5; i++)
	{
		*(parr2 + i) = *(parr1 + i);
	}
	cout << "First: ";
	for (int i = 0; i < 5; i++) {
		cout << arr1[i] << " ";
	}cout << endl;

	cout << "Second: ";
	for (int i = 0; i < 5; i++) {
		cout << arr2[i] << " ";
	}cout << endl;

	//Ex2
    int const SIZE = 5;
    int myArray[]{ 1, 2, 3, 4, 5 }; 
    cout << "First: ";
    for (int i = 0; i < SIZE; i++) {
        cout << myArray[i] << " ";
    }
    int* start = myArray;
    int* end = myArray + SIZE - 1;
    while (start < end) {

        int temp = *start;
        *start = *end;
        *end = temp;


        start++;
        end--;
    }cout << endl;

    cout << "New: ";
    for (int i = 0; i < SIZE; i++) {
        cout << myArray[i] << " ";
    }cout << endl;

	//Ex3
    int arr01[] = { 1, 2, 3, 4, 5 };
    int arr02[5]; 

    int* ptr1 = arr01;
    int* ptr2 = arr02 + 4; 

    for (int i = 0; i < 5; i++) {
        *(ptr2 - i) = *(ptr1 + i);
    }

    
    cout << "First: ";
    for (int i = 0; i < 5; i++) {
        cout << arr01[i] << " ";
    }cout << endl;

    cout << "Second: ";
    for (int i = 0; i < 5; i++) {
        cout << arr02[i] << " ";
    }

}