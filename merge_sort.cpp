#include<iostream>
using namespace std;

void merge(int input[], int s, int e){
    int mid = (s + e)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = s;
    for(int i = 0; i<len1;){
        first[i++] = input[k++];
    }
    k = mid + 1;
    for(int i = 0; i<len2;){
        second[i++] = input[k++];
    }

    int i = 0, j = 0;
    k = s;
    for(;i<len1 && j<len2;){
        if(first[i]>second[j]){
            input[k++] = second[j];
            j++;
        }
        else{
            input[k++] = first[i];
            i++;
        }
    }
    for(;i<len1;){
        input[k++] = first[i];
        i++;
    }
    for(;j<len2;){
        input[k++] = second[j];
        j++;
    }
}
void sort(int input[], int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    sort(input,s,mid);
    sort(input, mid + 1, e);
    merge(input,s,e);
}

int main()
{
    int input[100];
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    cout<<"Before Sorting: "<<endl;
    for(int i = 0; i<n; i++){
        cout<<input[i]<<" ";
    }cout<<endl;
    
    sort(input,0,n-1);

    cout<<"After Sorting: "<<endl;

    for(int i = 0; i<n; i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;

    return 0;
}