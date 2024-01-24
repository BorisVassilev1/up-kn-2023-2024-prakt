#include <iostream>
#include <cstddef>

const int MOVES_COUNT = 4;

// right -> down -> left -> up
const int dRows[] = { 0, 1, 0, -1 };
const int dCols[] = { 1, 0, -1, 0 };
const int VISITED = -1;

// helper functions
int** allocateSquareMatrix(std::size_t n);
void deallocateSquareMatrix(int** matrix, std::size_t n);
void printSquareMatrix(int** matrix, std::size_t n);

int** readLab(std::size_t& n)
{
    std::cin >> n;

    int** lab = allocateSquareMatrix(n);

    for (std::size_t i = 0; i < n; ++i)
    {
        for (std::size_t j = 0; j < n; ++j) {
            std::cin >> lab[i][j];
        }
    }

    return lab;
}

bool reachedFinal(
    const std::size_t currentRow,
    const std::size_t currentCol,
    const std::size_t finalRow,
    const std::size_t finalCol
) {
    return currentRow == finalRow &&
        currentCol == finalCol; 
}
bool isValidPos(
    const std::size_t row,
    const std::size_t col,
    const std::size_t n,
    int** lab
) {
    return row < n && col < n && lab[row][col] != VISITED;
}

void findMaxSum(
    int** lab,
    const std::size_t n,
    std::size_t currentRow,
    std::size_t currentCol,
    const std::size_t finalRow,
    const std::size_t finalCol,
    int& sum,
    int& maxSum
) {
    int currentNumber = lab[currentRow][currentCol];
    sum += currentNumber;
    lab[currentRow][currentCol] = VISITED;
    //std::cout << "Current row: " << currentRow << " Current col: " << currentCol << " Current number: " << currentNumber << " Current sum: " << sum << " Current max sum: " << maxSum << std::endl;
    
    if (reachedFinal(currentRow, currentCol, finalRow, finalCol))
    {
        maxSum = (sum > maxSum ? sum : maxSum);
        //printSquareMatrix(lab, n);
    }
    else
    {
        for (int i = 0; i < MOVES_COUNT; ++i)
        {
            std::size_t nextRow = currentRow + dRows[i],
                nextCol = currentCol + dCols[i];

            if (isValidPos(nextRow, nextCol, n, lab))
            {
                findMaxSum(lab, n, nextRow, nextCol, finalRow, finalCol, sum, maxSum);
            }
        }
    }

    lab[currentRow][currentCol] = currentNumber;
    sum -= currentNumber;
}

void printMaxSum(
    int** lab,
    const std::size_t n,
    const std::size_t startRow,
    const std::size_t startCol,
    const std::size_t finalRow,
    const std::size_t finalCol
) {
    int sum = 0, maxSum = 0;
    findMaxSum(lab, n, startRow, startCol, finalRow, finalCol, sum, maxSum);

    std::cout << maxSum << std::endl;
}
int main()
{
    std::size_t n;
    int** lab = readLab(n);
    //printSquareMatrix(lab, n);

    printMaxSum(lab, n, 0, 0, n-1, n-1);

    deallocateSquareMatrix(lab, n);

    return 0;
}

int** allocateSquareMatrix(std::size_t n)
{
    int** matrix = new int*[n];
    for (std::size_t i = 0; i < n; ++i)
    {
        matrix[i] = new int[n];
    }

    return matrix;
}
void deallocateSquareMatrix(int** matrix, std::size_t n)
{
    for (std::size_t i = 0; i < n; ++i)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}
void printSquareMatrix(int** matrix, std::size_t n)
{
    for (std::size_t i = 0; i < n; ++i)
    {
        for (std::size_t j = 0; j < n; ++j)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}