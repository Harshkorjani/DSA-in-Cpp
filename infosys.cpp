#include<bits/stdc++.h>
using namespace std;
int countPrime(int n){
    int count = 0;
    for(int i = 1; i<=n; i++){
        if(n%i == 0) count++;
    }
    return count;
}
bool Tprime(int n){
    return countPrime(n) == 3;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin>>n; 
    int *arr = new int[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i<n; i++){
        cout<<Tprime(arr[i])<<endl;
    }
    delete[] arr;
    return 0;
}