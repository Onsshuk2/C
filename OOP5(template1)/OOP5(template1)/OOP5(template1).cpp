#include <iostream>
#include <algorithm>

using namespace std;

//1
template <typename T>
T GetMax(T* arr, int size)
{
	T max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
//2
template <typename T1>
T1 GetMin(T1* arrm, int sizem)
{
	T1 min = arrm[0];
	for (int i = 0; i < sizem; i++)
	{
		if (arrm[i] < min)
		{
			min = arrm[i];
		}
	}
	return min;
}

//3
template <typename T2>
void Sort(T2* arrS, int sizeS)
{
	sort(arrS, arrS + sizeS);
	for (int i = 0; i < sizeS; i++)
	{
		cout << arrS[i] << " ";
	}
	cout << endl;
}

template <typename T3>
bool Binary(const T3* arr, int size, const T3& value)
{
	return binary_search(arr, arr + size, value);
}


int main()
{
	//1
	/*int arr0[5]{ 11,2,34,4,2 };
	float arr1[4]{ 1.2, 24.5, 33.11, 4.1 };
	string arr2[3]{ "hello","hi","good" };
	cout << " Int Max: " << GetMax(arr0, 5)<<endl;
	cout << " Float Max: " << GetMax(arr1, 4)<<endl;
	cout << " String Max: " << GetMax(arr2, 3) << endl;*/
	
	
	int arr0[5];
	float arr1[4];
	string arr2[3];

	cout << "Enter 5  int-number:";
	for (int i = 0; i < 5; ++i)
	{
		cin >> arr0[i];
	}
    cout << "Int Max: " << GetMax(arr0, 5) << endl;
	
	cout << "Enter 4 float-number:";
	for (int i = 0; i < 4; ++i)
	{
		cin >> arr1[i];
	}
    cout << "Float Max: " << GetMax(arr1, 4) << endl;
	
    cout << "Enter 3 words:";
	for (int i = 0; i < 3; ++i)
	{
		cin >> arr2[i];
	}
    cout << "String Max: " << GetMax(arr2, 3) << endl;

	
	//2
    int arr0m[5]{ 11,2,34,4,2 };
	float arr1m[4]{ 1.2, 24.5, 33.11, 4.1 };
	string arr2m[3]{ "hello","hi","good" };
	cout << " Int Min: " << GetMin(arr0m, 5) << endl;
	cout << " Float Min: " << GetMin(arr1m, 4) << endl;
	cout << " String Min: " << GetMin(arr2m, 3) << endl;
	
	//3
	int arr0s[5]{ 11, 2, 34, 4, 3 };
	float arr1s[4]{ 1.2, 24.5, 33.11, 4.1 };
	cout << "int sort:"; 
	Sort(arr0s, 5);
	cout << "float sort:";
	Sort(arr1s, 4);
	
	//4
	int arr0b[3]{4,5,6};
	char arr1b[3]{'a','s','d'};
	cout << "search int: " << Binary(arr0b, 3, 5) << endl;
	cout << "search char: " << Binary(arr1b, 3, 's') << endl;
	
}

