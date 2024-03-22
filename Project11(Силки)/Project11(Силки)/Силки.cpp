#include <iostream>
using namespace std;


int main()
{
	//Ex1
	int M, N;
	cout << "Enter first: ";
	cin >> M;
	cout << "Enter second: ";
	cin >> N;

	int* A = new int[M];
	int* B = new int[N];
	int* C = new int[M + N];

	cout << " Elements first: ";

	for (int i = 0; i < M; i++) {
		cin >> A[i];
		
	}

	cout << "Elements second: ";

	for (int i = 0; i < N; i++) {
		cin >> B[i];
		
	}
	int newSize = 0;
	for (int i = 0; i < M; i++) {
		bool found = false;
		for (int j = 0; j < N; j++) {
			if (A[i] == B[j]) {
				found = true;
				break;
			}
		}
		if (!found) {
			C[newSize] = A[i];
			newSize++;
		}
	}

	
	for (int i = 0; i < N; i++) {
		bool found = false;
		for (int j = 0; j < M; j++) {
			if (B[i] == A[j]) {
				found = true;
				break;
			}
		}
		if (!found) 
		{
			C[newSize] = B[i];
			newSize++;
		}
	}

	cout << "Arrerey C: ";
	for (int i = 0; i < newSize; i++) {
		cout << C[i] << " ";
	}
	cout << endl;
	
	

	delete[] A;
	delete[] B;
	delete[] C;

	//Ex2
	int M, N;
	cout << "Enter (M): ";
	cin >> M;
	cout << "Enter (N): ";
	cin >> N;

	int* A = new int[M];
	int* B = new int[N];
	int* C = new int[M + N];

	cout << "Enter elements 1: ";
	for (int i = 0; i < M; i++) {
		cin >> A[i];
	}

	cout << "Enterelements 2 : ";
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	int newSize = 0;
	for (int i = 0; i < M; i++) {
		bool found = false;
		for (int j = 0; j < N; j++) {
			if (A[i] == B[j]) {
				found = true;
				break;
			}
		}
		if (!found) {
			C[newSize] = A[i];
			newSize++;
		}
	}

	for (int i = 0; i < N; i++) {
		bool found = false;
		for (int j = 0; j < M; j++) {
			if (B[i] == A[j]) {
				found = true;
				break;
			}
		}
		if (!found) {
			C[newSize] = B[i];
			newSize++;
		}
	}
	cout << "Arrerey C: ";
	for (int i = 0; i < newSize; i++) {
		cout << C[i] << " ";
	}
	cout << endl;

	delete[] A;
	delete[] B;
	delete[] C;

}