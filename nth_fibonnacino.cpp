#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int first = 1;
    int second = 1;
    int next;
    if(n==1||n==2){
            cout<<first;
    }
    else{

    for(int i = 3; i<=n; i++){
        
        
        next = first + second;
        first = second;
        second = next;
              

    }

    cout<<next;
    }

}