#include<bits/stdc++.h>
using namespace std;

void print(int *arr, int n){
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void helper(int *arr, int n){
    int i = 0;
    int j = n-1;

    while(i<j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}
int main(){
    int n;
    cin>>n;
    int *arr = new int[1000];

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    print(arr,n);
    helper(arr,n);
    print(arr,n);
    return 0;
}
