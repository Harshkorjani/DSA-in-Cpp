#include<iostream>
using namespace std;

int linearSearch(int *arr, int n, int x)
{
    for(int i = 0; i<=n; i++){
        if(x == arr[i]){
            return i;
        }
    }
    
        return -1;
    
}
int main(){
    int t, n, x;
    cin>>t>>n>>x;
    
    int arr[100000];

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    for(int i = 1; i<=t; i++){
        int output = linearSearch(arr, n, x);
        cout << output;
    }
    
    return 0;
    
}