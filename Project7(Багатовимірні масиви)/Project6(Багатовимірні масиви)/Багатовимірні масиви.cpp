#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 10;

//Ex3
void fillArr(int arr[SIZE][SIZE])
{
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }
}
void showArr(int arr[SIZE][SIZE])
{
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            cout << setw(3) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void offsetArr(int arr[SIZE][SIZE], int offset)
{
    int temp;
    for (size_t i = 0; i < offset; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            temp = arr[j][SIZE - 1];
            for (size_t m = SIZE - 1; m > 0; m--)
            {
                arr[j][m] = arr[j][m - 1];
            }
            arr[j][0] = temp;
        }
    }
}
    int main()
    {
 
        //Ex1

        int a;
        int arr0[5][5];
        cout << "Enter a : " << endl;
        cin >> a;
        for (size_t i = 0; i < 5; i++)
        {
            for (size_t j = 0; j < 5; j++)
            {
                if (i == 0 && j == 0)
                {
                    arr0[i][j] = a;
                }
                else
                    arr0[i][j] = (arr0[i][j - 1] * 2);
            }
        }
        for (size_t i = 0; i < 5; i++)
        {
            for (size_t j = 0; j < 5; j++)
            {
                cout << arr0[i][j] << " ";
            }
            cout << endl;
        }
        //Ex2
        int a1;
        int arr1[5][5];
        cout << "Enter a : " << endl;
        cin >> a1;
        for (size_t i = 0; i < 5; i++)
        {
            for (size_t j = 0; j < 5; j++)
            {
                if (i == 0 && j == 0)
                {
                    arr1[i][j] = a1;
                }
                else
                    arr1[i][j] = (arr1[i][j - 1] + 1);
            }
        }
        for (size_t i = 0; i < 5; i++)
        {
            for (size_t j = 0; j < 5; j++)
            {
                cout << arr1[i][j] << " ";
            }
            cout << endl;
        }
        //Ex3
        srand(time(NULL));
        const int r = 10, c = 10;
        int arr[SIZE][SIZE];
        fillArr(arr);
        showArr(arr);
        cout << endl;
        offsetArr(arr, 2);
        showArr(arr);



 }
    