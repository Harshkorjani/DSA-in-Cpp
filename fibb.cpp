#include<iostream>
using namespace std;

int fibb(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibb(n-1) + fibb(n-2);
}

int mian(){
    int n;
    cin>>n;
    int output = fibb(n);
}