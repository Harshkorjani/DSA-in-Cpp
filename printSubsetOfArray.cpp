#include<iostream>
#include<cmath>
using namespace std;
void printSubsetOfArray(int input[], int n, int output[], int outputsize){
    if(n == 0){
        for(int i = 0; i<outputsize; i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }

    printSubsetOfArray(input+1, n-1, output, outputsize);
    output[outputsize] = input[0];
    printSubsetOfArray(input+1, n-1, output, outputsize + 1);
}
int main(){
    int n;
    cin>>n;
    int input[100];
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    int outputsize = pow(2,n);
    int output[outputsize];
    printSubsetOfArray(input,n,output,0);
    return 0;
}