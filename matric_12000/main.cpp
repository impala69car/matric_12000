#include <iostream>
#include "windows.h"
using namespace std;

int main()
{
    int sizeX, sizeY;
	sizeX = 12000;
	sizeY = 25000;

    if (sizeX <= 0)
    {
        return -1;
    }
    if (sizeY <= 0)
    {
        return -1;
    }
    unsigned int** array2d;
    unsigned int* temp = new unsigned int[sizeX * sizeY];
    array2d = new unsigned int*[sizeY];
    for (int i = 0; i < sizeY; ++i)
    {
        array2d[i] = (temp + i * sizeX);
    }
    for (int y = 0; y < sizeY; ++y)
    {
        for (int x = 0; x < sizeX; ++x)
        {
            array2d[y][x] = x + y * sizeX;
        }
    }
    for (int y = 0; y < sizeY; ++y)
    {
        for (int x = 0; x < sizeX; ++x)
        {
            std::cout << std::hex << &(array2d[y][x]) << ' ';
        }
    }
    std::cout << "\n\n";
    for (int y = 0; y < sizeY; ++y)
    {
        std::cout << std::hex << &(array2d[y][0]) << std::dec;
        std::cout << ": ";
        for (int x = 0; x < sizeX; ++x)
        {
            std::cout << array2d[y][x] << ' ';
        }
        std::cout << std::endl;
    }
    delete[] array2d[0];
    delete[] array2d;
    array2d = nullptr;
    return 0;
}