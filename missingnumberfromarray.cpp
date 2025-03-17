/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
int returnmissig(int n[],int s);

int main()
{
    //std::cout<<"Hello World";
    int nums[] = {3,0,1};
    
    int size = sizeof(nums)/sizeof(nums[0]);
    
    int value = returnmissig(nums,size);
    std::cout << value <<std::endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    

    return 0;
}

int returnmissig(int n[],int s)
{
    int arrxor=0;
    int fullarrayxor = 0;
    for(int i=0;i < s;i++)
    {
        arrxor = arrxor ^ n[i];
    }
    
    for(int j=0;j<=s;j++)
    {
        fullarrayxor = j ^ fullarrayxor;
    }
    
    return arrxor ^ fullarrayxor;
}