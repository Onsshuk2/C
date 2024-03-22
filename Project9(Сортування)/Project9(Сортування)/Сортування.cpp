#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

//Ex1
const int MAX_SIZE = 100;


void initMatrix(int arr[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = rand() % 10;
        }
    }
}


void initMatrix(double arr[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = static_cast<double>(rand()) / RAND_MAX * 10;
        }
    }
}

void initMatrix(char arr[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = 'A' + rand() % 26;
        }
    }
}

//Ex2
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

//Ex3
int generateRandomNumber() {
    srand(time(0));
    return 1000 + rand() % 9000;
}


void compareNumbers(int secretNumber, int guessedNumber, int& bull, int& cow) {
    bull = 0;
    cow = 0;

    for (int i = 0; i < 4; i++) {
        int secretDigit = (secretNumber / int (pow(10, i))) % 10;
        int guessedDigit = (guessedNumber / int (pow(10, i))) % 10;
        if (secretDigit == guessedDigit) {
            bull++;
        }
        else {
            for (int j = 0; j < 4; j++) {
                if (secretDigit == (guessedNumber / int (pow(10, j))) % 10) {
                    cow++;
                }
            }
        }
    }
}

void playGame(int secretNumber, int attempts) {
    cout << "Enter number: ";
    int guessedNumber;
    cin >> guessedNumber;

    if (guessedNumber == secretNumber) {
        cout << "You win " << attempts << " attempts." << endl;
    }
    else {
        int bull, cow;
        compareNumbers(secretNumber, guessedNumber, bull, cow);
        cout << "Bull: " << bull << ", Cow: " << cow << endl;
        playGame(secretNumber, attempts + 1);
    }
}

int main() 
{
    //Ex1
    const int size = 3; 

   
    int intMatrix[MAX_SIZE][MAX_SIZE];
    initMatrix(intMatrix, size);

    
    cout << "Integer Mftric:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << intMatrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    double doubleMatrix[MAX_SIZE][MAX_SIZE];
    initMatrix(doubleMatrix, size);

    
    cout << "Mftric of Real Numbers:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << doubleMatrix[i][j] << "\t";
        }
        cout << endl;
    }

    
    char charMatrix[MAX_SIZE][MAX_SIZE];
    initMatrix(charMatrix, size);

    
    cout << "Mftric of Real Numbers:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << charMatrix[i][j] << "\t";
        }
        cout << endl;
    }
    int matr[5][6]; 

    for (int i = 0; i < 5; ++i) {
        
        sort(matr[i], matr[i] + 6);
    }

   

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }

    //Ex2
    int num1, num2;
    cout << "First number: ";
    cin >> num1;
    cout << "Second number: ";
    cin >> num2;

    int result = gcd(num1, num2);
    cout << "NSK " << num1 << " and " << num2 << ": " << result << endl;

    //Ex3
    int secretNumber = generateRandomNumber();
    cout << "Game \"Bull and cow\". Guess the four digit number." << endl;
    playGame(secretNumber, 1);

}