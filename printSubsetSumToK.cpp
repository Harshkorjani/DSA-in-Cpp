#include<iostream>
#include<cmath>
using namespace std;
void SubsetSumToK(int input[], int n, int output[], int outsize, int k){
    if(n == 0){
        if(k == 0){
            for(int i = 0; i<outsize; i++){
                cout<<output[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    SubsetSumToK(input + 1, n-1, output, outsize,k);
    output[outsize] = input[0];
    SubsetSumToK(input + 1, n-1, output, outsize + 1,k - input[0]);
}
int main()
{
    int n; 
    cin>>n;
    int input[100];
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    int k;
    cin>>k;
    int outsize = pow(2,n);
    int output[outsize];
    SubsetSumToK(input,n,output,0,k);
    return 0;
}
