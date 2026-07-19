#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number"<<" ";
    cin>>n;

    int product = 1, i = 1;
    while(i<=n)
    {
        product = product*i;
        i++;
    } 

    cout<<"The product is"<<" ";
    cout<<product;

    return 0;
}
