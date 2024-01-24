#include <iostream>
#include <cstddef>

bool isDigit(char c);
void moveOnePosToTheRight(char* str, std::size_t from, std::size_t to);
void insertSorted(char* str, int lastIndex, char newDigit);
void shuffle(char* str);

int main()
{
    char str[100] = { '\0' };
    std::cin.getline(str, 100);
    
    shuffle(str);
    
    std::cout << str << std::endl;

    return 0;
}

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}
void moveOnePosToTheRight(char* str, std::size_t from, std::size_t to)
{
    while (to > from)
    {
        str[to] = str[to - 1];
        --to;
    }

    return;
}
void insertSorted(char* str, int lastIndex, char newDigit)
{
    while (lastIndex > 0 && str[lastIndex - 1] > newDigit)
    {
        str[lastIndex] = str[lastIndex - 1];
        --lastIndex;
    }

    str[lastIndex] = newDigit;

}
void shuffle(char* str)
{
    // digitIndex - index to write the next found digit
    std::size_t digitIndex = 0, pos = 0;

    while (str[pos] != '\0')
    {
        if (isDigit(str[pos]))
        {
            // save the found digit
            char digit = str[pos];
            // move everything from digitIndex 1 pos rightwards
            moveOnePosToTheRight(str, digitIndex, pos);

            // now digitIndex is free to write on

            // insert the digit in front of the str
            insertSorted(str, digitIndex, digit);
            ++digitIndex;
        }

        ++pos;
    }

    return;
}