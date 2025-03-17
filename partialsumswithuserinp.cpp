
#include <iostream>
#include <vector>

std::vector<int> partialsums(const std::vector<int>& inparr,int size)
{
    int sum = 0;
    std::vector<int> outputarr(size,0);

    for(int i=0;i<size;i++) //i=0 //i=1 //i=2
    {
         outputarr[i] = inparr[i] + sum; //1+0 //2+1 //3+3
         sum =   outputarr[i]; //1 //3 //6
    }

    return outputarr;
}


int main()
{
    std::vector<int> arr;
    int value;
    int number_of_arrayele;

    std::cout << "Enter number of elements n: ";
    std::cin >> number_of_arrayele;

    for(int i =0;i<number_of_arrayele;i++)
    {
        std::cin >> value;
        arr.push_back(value);
    }

    int size = arr.size();

    std::vector<int> output = partialsums(arr,size); //1,2,3

    for(int outp:output)
    {
        std::cout << outp << std::endl;
    }
    return 0;
}