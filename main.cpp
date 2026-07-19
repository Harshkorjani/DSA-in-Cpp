#include<iostream>
using namespace std;

void SelectionSort(int arr[], int n){
    for(int i = 0; i<n; i++){
        int MinIndex = i;
        for(int j = i + 1; j<n;j++){
            if(arr[j]<arr[MinIndex]){
                MinIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[MinIndex];
        arr[MinIndex] = temp;
    }
}

int main(){

    int arr[5] = {6,2,8,4,10};

    SelectionSort(arr,5);

    for(int i = 0; i<5; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}