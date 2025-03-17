/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

std::vector<int> partialsum(const std::vector<int>& inparr,int sizeinparr)
{
    int sum = 0;
    std::vector<int> sumarr(sizeinparr,0);
    
    for(int i=0 ;i<sizeinparr;i++)
    {
        sum = sum+inparr[i];
        sumarr[i] = sum;
   }
   return sumarr;
}


int main()
{
    
    std::vector<int> inp = {3,1,4,1,5,9,2};
    //int size = sizeof(inp) / sizeof(inp[0]);
    int size = inp.size();
    
    std::vector<int> op = partialsum(inp,size);
    
    std::cout << "Partial Sums: ";
    for(int o:op)
    {
        std::cout << o << " ";
    }
    
    
    //std::cout << std::endl;

    return 0;
}