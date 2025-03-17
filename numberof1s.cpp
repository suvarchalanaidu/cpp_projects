#include <iostream>
#include <cstdint>

int main()

{
    uint64_t n = 0b00010010001101000101011001111111; 
    int count =0;

    while(n>0)
    {
        if(n &1)  //or efficient brian -kernnghans algo :  n = n & (n - 1);  // Clears the rightmost 1-bit or use hardware opt.provided by compiler __builtin_popcount - hammingweight
        {
            count++;
        }

        n = n>>1;
    }

    std::cout <<count <<std::endl;
}
