#include<iostream>
#include<climits>

using namespace std;

int main(){
    int n;
    cout<<"Enter the num of element; "<<endl;
    cin>>n;

    int* p = new int[n];
    for(int i = 0; i<n; i++){
        cin>>p[i];
    }

    int max = INT_MIN;
    for(int i = 0; i<n; i++){
        if(max < p[i]){
            max = p[i];
        }
    }
    cout<<"Max element is: "<< max<<endl;

}