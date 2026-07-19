#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int count=0;
    int var=0,r;

    while(n!=0){
       
        r = (n%10);
        
        if(r%2 == 0){
            count = count + r;

        }
        else{
            var = var + r;

        }
        n = n/10;
        
    }
    cout<<count<<" "<<var;


    return 0;
}
