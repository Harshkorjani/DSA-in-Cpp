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
    int ans = is_prime(30);
    cout<<ans<<endl;

    ans =  is_prime(11);
    cout<<ans<<endl;

    return 0;
}
