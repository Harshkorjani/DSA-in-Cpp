#include<bits/stdc++.h>
using namespace std;
int helper(int arr[], int k, int n){
    if(n == 0){
        if(k == 0){
            return 1;
        }
        return 0;
    }
    int a = helper(arr+1,k-arr[0],n-1);
    int b = helper(arr+1,k,n-1);
    return a + b; 
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        int arr[15];
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }

        cout<<helper(arr,k,n);
    }
    return 0;
}
