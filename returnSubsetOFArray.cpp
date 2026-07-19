#include<iostream>
using namespace std;
int subset(int input[], int n, int output[][20]){
    if(n==0){
        output[0][0] = 0; 
        return 1;    
    }

    int small = subset(input + 1, n - 1, output);
    for(int i = 0; i<small; i++){
        int k = output[i][0] + 1;
        output[small + i][0] = k;
        output[small + i][1] = input[0];
        for(int j = 2; j<=k; j++){
            output[small + i][j] = output[i][j-1];
        }
    }
    return 2*small;
}
int main(){
    int n;
    cin>>n;
    int input[1000];
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    int output[3500][20];
    int ans = subset(input,n,output);
    for(int j = 0; j<ans; j++){
        for(int i = 0; i<4; i++){
            cout<<output[j][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}