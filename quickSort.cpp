#include<iostream>
using namespace std;
int partition(int input[], int s, int e){
    int p = input[s];
    int count = 0; 
    for(int i = s + 1; i<=e; i++){
        if(input[i]<=p){
            count++;
        }
    }
    int pi = s + count;
    int temp = input[s];
    input[s] = input[pi];
    input[pi] = temp;

    int i = s;
    int j = e;
    while(i<=pi && j>=pi){
        while(input[i]<=p){
            i++;
        }
        while(input[j]>p){
            j--;
        }
        if(i<pi && j>pi){
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }
    return pi;
}
void quick_sort(int input[], int s, int e){
    if(s>=e){
        return;
    }
    int pi = partition(input, s, e);
    quick_sort(input,s,pi-1);
    quick_sort(input,pi + 1,e);
}
  int main()
{
    int input[5] = {1,5,2,7,3};
    for(int i = 0; i<=4; i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    quick_sort(input,0,4);
    for(int i= 0; i<=4; i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    return 0;
}
