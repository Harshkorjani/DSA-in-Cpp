#include<bits/stdc++.h>
using namespace std;
int fibo_2(int n){
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    for(int i = 2; i<n+1; i++){
        ans[i] = ans[i-1] + ans[i-2];
    }
    return ans[n];
}
int fibo_1(int n){
    if(n <= 1){
        return n;
    }
    int a = fibo_1(n-1);
    int b = fibo_1(n-2);
    return a + b;
}
int fibo_helper(int n, int* arr){
    if(n <= 1){
        return n;
    }
    if(arr[n] != -1){
        return arr[n];
    }
    int a = fibo_helper(n-1,arr);
    int b = fibo_helper(n-2,arr);
    arr[n] = a + b;
    return arr[n]; 
}
int fibo(int n){
    int *arr = new int[n + 1];
    for(int i = 0; i<=n; i++){
        arr[i] = -1;
    }
    return fibo_helper(n,arr);
}
int main(){
    int n;
    cin>>n;
    cout<<fibo_2(n)<<endl;
    return 0;
}
