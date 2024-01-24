#include <iostream>
#include <cstddef>

const std::size_t MAX_ROWS = 20, MAX_COLS = 30;

// funtion to read matrix
void readMatrix(int matrix[][MAX_COLS], std::size_t& rows, std::size_t& cols);

// function to find min value in array(a row of a matrix is just an array)
int findMinInRow(int row[], std::size_t size);

// function to find max value in col of a matrix
int findMaxInCol(int matrix[][MAX_COLS], std::size_t rows, std::size_t cols, std::size_t col);

// the actual function to solve the problem
void printSaddlePoints(int matrix[][MAX_COLS], std::size_t rows, std::size_t cols);

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    std::size_t n, m;
    
    readMatrix(matrix, n, m);
    printSaddlePoints(matrix, n, m);

    return 0;
}

void readMatrix(int matrix[][MAX_COLS], std::size_t& rows, std::size_t& cols)
{
    std::cin >> rows >> cols;
    if (rows == 0 || cols == 0 || rows > MAX_ROWS || cols > MAX_COLS)
    {
        std::cout << "Invalid sizes of the matrix\n";
        return;
    }

    for (std::size_t i = 0; i < rows; ++i)
    {
        for (std::size_t j = 0; j < cols; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }

    return;
}
void printSaddlePoints(int matrix[][MAX_COLS], std::size_t rows, std::size_t cols)
{
    // array of min values for each row in the matrix
    // minRowValues[i] = the min value in row i of the matrix
    int minRowValues[MAX_ROWS] = { 0, };
    for (std::size_t i = 0; i < rows; ++rows)
    {
        minRowValues[i] = findMinInRow(matrix[i], cols);
    }

    // array of max values for each col in the matrix
    // maxColValues[i] = the max value in col i of the matrix
    int maxColValue[MAX_COLS] = { 0 };
    for (std::size_t i = 0; i < cols; ++i)
    {
        maxColValue[i] = findMaxInCol(matrix, rows, i);
    }

    for (std::size_t i = 0; i < rows; ++i)
    {
        for (std::size_t j = 0; j < cols; ++j)
        {
            // condition for a saddle point
            if (matrix[i][j] == minRowValues[i] &&
                matrix[i][j] == maxColValue[j])
            {
                std::cout << matrix[i][j] << ' ';
            }
        }
    }
    std::cout << std::endl;
}

int findMinInRow(int arr[], std::size_t size)
{
    int min = arr[0];
    for (std::size_t i = 1; i < size; ++i) {
        min = (arr[i] < min ? arr[i] : min);
    }

    return min;
}
int findMaxInCol(int matrix[][MAX_COLS], std::size_t rows, std::size_t col)
{
    int max = matrix[0][col];
    for (std::size_t i = 1; i < rows; ++i) {
        max = (matrix[i][col] > max ? matrix[i][col] : max);
    }

    return max;
}