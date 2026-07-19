#include<iostream>
using namespace std;
void Reverse(int arr[],int n){
    int s = 0;
    int e = n -1;
    while(s<=e){
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }
}
int main(){
    int arr[1000];
    int n;
    cout<<"Enter the no. of elements in array: ";
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    Reverse(arr,n);
    cout<<"After swapping: ";
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}