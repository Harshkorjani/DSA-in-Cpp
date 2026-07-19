#include<iostream>
using namespace std;

void SelectionSort(int arr[], int n){
    int i = 0;
    while(i<n-1){
        int min = arr[i], minIndex = i;
        for(int j = i + 1;j<n;j++){
            if(arr[j]<min){
                min = arr[j];
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        i++;
    }

}
int main()
{
    int arr[1000] = {3,1,6,9,0,4};

    SelectionSort(arr,6);

    for(int i = 0; i<=5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}
