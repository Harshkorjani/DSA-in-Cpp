#include<iostream>

using namespace std;

int main()

{
    int i=1,n,j;
    cin>>n;
    while(i<=n)
    {
        int k=1;
        while(k<=n-i)
        {
            cout<<" ";
            k=k+1;
        }
        j=1;
        int val=i;
        while(j<=i)
        {
            cout<<val;
            val=val+1;
            j=j+1;
        }
        j=i-1;
        int val1=2*i-2;
        while(j>=1)
        {
            cout<<val1;
            val1=val1-1;
            j=j-1;
        }
        cout<<endl;
        i=i+1;
    }
    return 0;
}
