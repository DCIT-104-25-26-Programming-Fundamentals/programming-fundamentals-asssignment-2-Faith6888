// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// finding the transpose where the rows become the colomns
void transposeMatrix(int matrix[10][10], int rows, int cols, int result[10][10])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}

// the function for adding th matrices provided they are of same size
void addMatrices(int a[10][10], int b[10][10], int rows, int cols, int result[10][10])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// the function for the matrix multiplication
void multiplyMatrices(int a[10][10], int b[10][10], int rowsA, int colsA, int colsB, int result[10][10])
{
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            int sum = 0;
            for (int k = 0; k < colsA; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main()
{
    int rowsA, colsA;

    // Part A: Transpose 
    cout << "Part A: The Transpose" << endl;
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;

    int matrixA[10][10];
    readMatrix(matrixA, rowsA, colsA);

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrixA, rowsA, colsA);
     int transposed[10][10];
    transposeMatrix(matrixA, rowsA, colsA, transposed);

    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transposed, colsA, rowsA);

    // Part B: Addition 
    cout << "\nPart B: Addition" << endl;
    cout << "Enter matrix B (must be " << rowsA << "x" << colsA << "):" << endl;
    int matrixB[10][10];
    readMatrix(matrixB, rowsA, colsA);

    int sumResult[10][10];
    addMatrices(matrixA, matrixB, rowsA, colsA, sumResult);

    cout << "\nSum (A + B):" << endl;
    displayMatrix(sumResult, rowsA, colsA);

    //  Part C: Multiplication 
    cout << "\n Part C: Multiplication" << endl;
    int rowsC, colsC;
    cout << "Enter matrix C rows: ";
    cin >> rowsC;
    cout << "Enter matrix C columns: ";
    cin >> colsC;

    if (rowsC != colsA)
    {
        cout << "Error: columns of A must equal rows of C." << endl;
        return 0;
    }

    int matrixC[10][10];
    readMatrix(matrixC, rowsC, colsC);

    int productResult[10][10];
    multiplyMatrices(matrixA, matrixC, rowsA, colsA, colsC, productResult);

    cout << "\nProduct (A x C):" << endl;
    displayMatrix(productResult, rowsA, colsC);

    return 0;
} 