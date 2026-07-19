#include<iostream>
using namespace std;

int sum(int a[], int size, int start = 0){
    int ans = 0;
    for(int i = start; i<size; i++){
        ans += a[i];

    }
    return ans;
}

int main()
{
    int a[20];
    for(int i = 0; i<5; i++){
        cin>>a[i];
    }
    cout<<sum(a,5)<<endl;
    return 0;
}
