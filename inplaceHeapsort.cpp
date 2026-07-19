#include<iostream>
using namespace std;
void heapSort(int arr[],int n){
    for(int i = 1; i < n; i++){
        int childindex = i;
        while(childindex > 0){
            int parentindex = (childindex - 1) / 2;
            if(arr[childindex] > arr[parentindex]){
                int temp = arr[childindex];
                arr[childindex] = arr[parentindex];
                arr[parentindex] = temp;
            }
            else{
                break;
            }
            childindex = parentindex;
        }
    }
    int size = n;
    while(size>1){
        int ans = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = ans;
        size--;
        int parentindex = 0;
        int LCI = 2*parentindex + 1;
        int RCI = 2*parentindex + 2;
        while(LCI <  size){
            int maxindex = parentindex;
            if(arr[maxindex] < arr[LCI]){
                maxindex = LCI;
            }
            if(RCI < size && arr[maxindex] < arr[RCI]){
                maxindex = RCI;
            }
            if(parentindex == maxindex){
                break;
            }
            int temp = arr[maxindex];
            arr[maxindex] =  arr[parentindex];
            arr[parentindex] = temp;
            parentindex = maxindex;
            LCI = 2*parentindex + 1;
            RCI = 2*parentindex + 2; 
        }
    }
}
int main(){
    int n;
    cout<<"Enter The Size of the array:"<<" ";
    cin>>n;

    int input[100];
    cout<<"Enter the elemnts of the array:"<<endl;;
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    heapSort(input,n);
    cout<<"Array after sorting"<<endl;

    for(int i = 0; i<n; i++){
        cout<<input[i]<<" ";
    }
    return 0;
}
