#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int x = 0xaabbccdd;

    // unsigned char 
    unsigned char y = (unsigned char)x;
    unsigned char z = 0xdd;

    if (y == 0xdd)
        cout << "Little Endian";
    else if (y == 0xaa)
        cout << "Big Endian";

    return 0;
}