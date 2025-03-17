#include <iostream>
#include <vector>

std::vector<int> partialsums(int arr[],int size)
{
    int sum=0;
    std::vector<int> outarr(size,0);

    for(int i=0;i <size;i++) //i=0  //i=1
    {
        outarr[i] = arr[i] + sum; //outarr[0] = 1 +0 =1 //outarr[1] = 2+1
        sum = outarr[i]; //sum = 1 //sum = 3
    }

    return outarr;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    std::vector<int> output = partialsums(arr,size);

    for(int ps : output)
    {
        std::cout << ps << std::endl;
    }


}