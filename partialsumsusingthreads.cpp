#include <iostream>
#include <thread>
#include <vector>
#include <functional> // For std::ref


//in multi-threading threads cannot return values easily
//void is often used when output is stored in an argument
//std::thread requires a void function
//std::thread does not allow easy return values.
void partialsum(int inp[],int size,std::vector<int>& outarr)
{
    int sum=0;
    for(int i=0;i<size;i++)
    {
        outarr[i] = sum + inp[i];
        sum = outarr[i];
    }
}


int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    std::vector<int> outarr1(size/2,0);
    std::vector<int> outarr2(size-size/2,0);//General Formula for Splitting Any Array coves the odd number of elemetns case
    
    
    //this is read as partialsum(arr,size,std::ref(outarr))
    std::thread t1(partialsum,arr,size/2,std::ref(outarr1));
    std::thread t2(partialsum,arr+size/2,size-size/2,std::ref(outarr2));
    
    t1.join(); //synchronization function to avoid race conditions
    t2.join();
    
    //here thread1 and thread2 give two different outputs and they are not related
    
    int value = outarr1.back();
    
    for(int &i:outarr2)
    {
        i = i + value;
        //std::cout << i <<std::endl;
    }
    
    

    std::cout << "Partial Sums: ";
    for(int i:outarr1)
    {
         std::cout << i << " ";
    }
     for(int j:outarr2)
    {
         std::cout << j << " ";
    }
    return 0;
}