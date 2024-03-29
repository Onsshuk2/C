#include<iostream>
using namespace std;


//Ex1.1
void addColumn(int**& matrix, int numrows, int& numcols, int colposition, int defaultvalue) {
    
    int** newmatrix = new int* [numrows];
    for (int i = 0; i < numrows; i++) {
        newmatrix[i] = new int[numcols + 1]; 
    }

    
    for (int i = 0; i < numrows; i++) {
        int col = 0;
        for (int col = 0; col < colposition; col++) 
        {
            newmatrix[i][col] = matrix[i][col];
        }
        newmatrix[i][col] = defaultvalue; 
        for (col=0; col < numcols; col++) {
            newmatrix[i][col + 1] = matrix[i][col];
        }
    }

    
    for (int i = 0; i < numrows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    
    matrix = newmatrix;
    numcols++;
}

//Ex1.2
const int MAXROWS = 100;
const int MAXCOLS = 100;

void print10Matrix(int matrix0[MAXROWS][MAXCOLS], int num0Rows, int num0Cols) {
    for (int i = 0; i < num0Rows; ++i) {
        for (int j = 0; j < num0Cols; ++j) {
            cout << matrix0[i][j] << " ";
        }
        cout << endl;
    }
}
void deleteColumn(int matrix0[MAXROWS][MAXCOLS], int& num0Rows, int& num0Cols, int colIndex) {

    for (int i = 0; i < num0Rows; ++i) {
        for (int j = colIndex; j < num0Cols - 1; ++j) {
            matrix0[i][j] = matrix0[i][j + 1];
        }
    }

    num0Cols--;
}
//Ex1.3
const int MAX_ROWS = 100;
const int MAX_COLS = 100;

void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int numRows, int numCols) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void rotateRows(int matrix[MAX_ROWS][MAX_COLS], int numRows, int numCols, int shiftCount, bool clockwise) {
   

    if (!clockwise) {
        shiftCount = numRows - (shiftCount % numRows); 
    }

    int tempRow[MAX_COLS];

    for (int i = 0; i < numRows; ++i) {
        int newRow = (i + shiftCount) % numRows;
        for (int j = 0; j < numCols; ++j) {
            tempRow[j] = matrix[newRow][j];
        }
        for (int j = 0; j < numCols; ++j) {
            matrix[i][j] = tempRow[j];
        }
    }
}


//Ex2.1
const int ROWS = 10;
const int COLS = 10;

void transposeMatrix(int matrix[ROWS][COLS], int rows, int cols) {
    int transposedMatrix[COLS][ROWS]; 

    
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }

    cout << "Original Matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
           cout << matrix[i][j] << " ";
        }
       cout << endl;
    }
    
    cout << "Transposed Matrix:" << endl;
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
           cout << transposedMatrix[i][j] << " ";
        }
        cout << endl;
    }
}



int main()
{
    //Ex1.1
    int numRows = 3;
    int numCols = 2;
    int** matrix = new int* [numRows];
    for (int i = 0; i < numRows; i++) {
        matrix[i] = new int[numCols];
        for (int j = 0; j < numCols; j++) {
            matrix[i][j] = i * numCols + j + 1;
        }
    }

    cout << "Initial matrix:" << endl;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << matrix[i][j] << " ";
        }
       cout << endl;
    }

    addColumn(matrix, numRows, numCols, 1, 0);

    cout << "Matrix after adding column:" << endl;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < numRows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;


    //Ex2.1
    int matrix1[ROWS][COLS];
    int rows, cols;

    
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix1[i][j];
        }
    }

    
    transposeMatrix(matrix1, rows, cols);

    
    
    //Ex1.2
    int matrix10[MAXROWS][MAXCOLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int num0Rows = 3;
    int num0Cols = 3;

    cout << "Original matrix:" << endl;
    print10Matrix(matrix10, num0Rows, num0Cols);

    
    deleteColumn(matrix10, num0Rows, num0Cols, 1);

  cout << "Matrix after deleting column 1:" << endl;
    print10Matrix(matrix10, num0Rows, num0Cols);


    //Ex1.3
    int matrix0[MAX_ROWS][MAX_COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int numRows = 3;
    int numCols = 3;

    cout << "Original matrix:" << endl;
    printMatrix(matrix0, numRows, numCols);

    
    rotateRows(matrix0, numRows, numCols, 1, false);

    cout << "Matrix after rotating rows left by 1:" << endl;
    printMatrix(matrix0, numRows, numCols);

}