#include<iostream>
using namespace std;
// main logic in the function SubSetSumToK;
int SubSetSumToK(int input[], int n, int output[][50],int k){
    if(n == 0){
        if(k == 0){
            output[0][0] = 0;
            return 1;
        }
        return 0;
    }
    int output1[1000][50];
    int output2[1000][50];

    int small1 = SubSetSumToK(input + 1, n-1, output1,k);
    int small2 = SubSetSumToK(input + 1, n-1, output2, k - input[0]);

    for(int i = 0; i<small1; i++){
        int size = output1[i][0];
        for(int j = 0; j<=size; j++){
            output[i][j] = output1[i][j]; 
        }
    }

    for( int i = 0; i<small2; i++){
        int size = output2[i][0];
        output[i + small1][0] = size + 1;
        output[i + small1][1] = input[0];
        for(int j = 0; j<size; j++){
            output[i + small1][j + 2] = output2[i][j+ 1]; 
        }
    }
    return (small1 + small2);
}
int main()
{
    int n;
    cin>>n;
    int input[1000];
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    int k;
    cin>>k;
    int output[1000][50];
    int ans = SubSetSumToK(input,n,output,k);
    for(int i = 0; i<ans; i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;
    return 0;
}
