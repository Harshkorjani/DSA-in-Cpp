#include <iostream>
using namespace std;

int search(int arr[],int size,int key)
{
    int start=0;
    int end= size - 1; 
    while(start<=end){
        int mid = (start + end)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(key>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid = (start + end)/2;
    }
    return -1;  
}
int main()
{
    int even[6]={-12,-9,-7,14,35,74};
    int odd[5]={-15,2,3,5,17};
        
    int found = search(even,6,74);
    cout<<"Index of 74 is "<<found<<endl;
       
    found = search(odd,5,3);
    cout<<"Index of 3 is "<<found<<endl;
        
    return 0;
}