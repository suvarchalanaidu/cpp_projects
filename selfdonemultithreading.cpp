/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <thread>
#include <vector>
#include <functional>

void partialsums(int inparr[],int size,std::vector<int>& outarr)
{
   int sum=0;
   for (int i =0; i <size ;i++)
   {
       outarr[i] = sum + inparr[i];
       sum = outarr[i];
   }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    std::vector<int> outarr1(size/2,0);
    std::vector<int> outarr2(size-size/2,0);
    
    std::thread t1(partialsums,arr,size/2,std::ref(outarr1));
    std::thread t2(partialsums,&arr[size/2],size-size/2,std::ref(outarr2));

    t1.join();
    t2.join();
    
    int lastelementofoutarr1 = outarr1.back();
    
    for(int &i:outarr2)
    {
        i = i + lastelementofoutarr1;
    }
    
    std::cout << "Partial Sums: ";
    for(int ps1 : outarr1)
    {
        std::cout << ps1 << " ";
    }
    for(int ps2 : outarr2)
    {
        std::cout << ps2 << " ";
    }
    return 0;
}