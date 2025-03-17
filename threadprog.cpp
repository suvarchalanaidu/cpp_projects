/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <thread>

void runloop()
{
    for(int i =0; i <=100;i++)
    {
        std::cout << "Loop" << i <<std::endl;
    }
    
}

int main()  //main started and t1 started 
{
    std::thread t1(runloop);
    std::cout<<"Inside Main"; //as t1 is running separately main continues
    
    t1.join(); //t1 joins with main else you get a core dump error

    return 0;
}