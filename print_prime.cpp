#include<iostream>
using namespace std;

bool is_prime(int n){
    int d = 2;
    while(d < n){
        if(n % d == 0){
            return false;
        }
        d++;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;

    cout<<is_prime(n)<<endl;
    for(int x = 2; x < n; x++){
        if(is_prime(x)){
            cout<<x<<" ";
        }
    }
    return 0;
   
 
}
