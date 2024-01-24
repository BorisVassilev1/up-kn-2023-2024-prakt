#include <iostream>
#include <cstddef>

struct intarray
{
    int *arr;
    std::size_t size;
};

// helper functions
void readAndAllocate(intarray& a);
void print(const intarray& a);
void deallocate(intarray& a);

// actual solution functions
bool mustAdd(int x, const intarray& arr);
void addNumToIntarray(int x, intarray& intarr);
intarray construct(const intarray& a, const intarray& b);

int main()
{
    intarray a, b;
    readAndAllocate(a);
    print(a);
    
    readAndAllocate(b);
    print(b);

    intarray c = construct(a, b);
    print(c);

    deallocate(a);
    deallocate(b);
    deallocate(c);

    return 0;
}

bool mustAdd(int x, const intarray& intarr)
{
    // counter how many times x occurs in intarr
    int counter = 0;

    for (std::size_t i = 0; i < intarr.size; ++i)
    {
        if (intarr.arr[i] == x)
        {
            ++counter;
        }
    }

    // check if x occured at least x times in intarr
    return counter >= x;
}
void addNumToIntarray(int x, intarray& intarr)
{
    // allocating new buffer
    int* newArr = new int[intarr.size + 1];

    // copy old values
    for (std::size_t i = 0; i < intarr.size; ++i)
    {
        newArr[i] = intarr.arr[i];
    }
    // add the new value
    newArr[intarr.size] = x;

    deallocate(intarr);
    // redirect intarr.arr
    intarr.arr = newArr;
    ++intarr.size;
}
intarray construct(const intarray& a, const intarray& b)
{
    intarray result;
    result.arr = nullptr;
    result.size = 0;

    for (std::size_t i = 0; i < a.size; ++i)
    {
        if (mustAdd(a.arr[i], b))
        {
            addNumToIntarray(a.arr[i], result);
        }
    }

    return result;
}

void readAndAllocate(intarray& a)
{
    std::cin >> a.size;

    a.arr = new int[a.size];
    for (std::size_t i = 0; i < a.size; ++i)
    {
        std::cin >> a.arr[i];
    }
}
void print(const intarray& a)
{
    std::cout << "Array with size " << a.size << std::endl;
    
    for (std::size_t i = 0; i < a.size; ++i)
    {
        std::cout << a.arr[i] << ' ';
    }
    std::cout << std::endl;
}
void deallocate(intarray& a)
{
    delete[] a.arr;
}