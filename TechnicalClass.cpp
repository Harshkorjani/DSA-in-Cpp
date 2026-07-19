#include<bits/stdc++.h>
using namespace std;
int fib(int n, vector<int> &dp){
    if(n<2) return n;
    if(dp[n] != -1) return dp[n];

    return dp[n] = fib(n-1,dp)+fib(n-2,dp);
}
// int main(){
//     int n;
//     cin>>n;
//     if(n<2) return n;
//     vector<int> dp(n+1,0);
//     dp[0]=0;
//     dp[1]=1;
//     for(int i = 2; i<=n; i++){
//         dp[i] = dp[i-1]+dp[i-2];
//     }
//     cout<<dp[n];
// }

// int uniquepath(int i, int j,vector<vector<int>> &grid,int n,vector<vector<int>> &dp){
//     if(i==n-1 && j==n-1) return 1;
//     if(dp[i][j] != -1) return dp[i][j];
//     int a=0,b=0,c=0;
//     if(i<n-1){
//         a=uniquepath(i+1,j,grid,n,dp);
//     }
//     if(j<n-1){
//         b = uniquepath(i,j+1,grid,n,dp);
//     }
//     if(i<n-1 && j<n-1){
//         c = uniquepath(i+1,j+1,grid,n,dp);
//     }
//     return dp[i][j] = a+b+c;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<vector<int>> grid(n,vector<int>(n,0));
//     vector<vector<int>> dp(n,vector<int>(n,-1));
//     cout<<uniquepath(0,0,grid,n,dp);
//     return 0;
//}
// int helper(int ind, int W, int val[], int wt[], int N,vector<vector<int>> &dp){
//         // Base case:
//         if(ind==N || W==0) return 0;
        
//         if(dp[ind][W] != -1) return dp[ind][W];
        
//         int not_take = helper(ind+1, W,val, wt, N,dp);
//         int take = 0;
//         if(wt[ind]<=W){
//             take = helper(ind,W-wt[ind],val,wt,N,dp)+val[ind];
//         }
//         return dp[ind][W]=max(take,not_take);
//     }
//     int knapSack(int N, int W, int val[], int wt[]){
//         // code here
//         vector<vector<int>> dp(N+1, vector<int>(W+1,-1));
//         return helper(0,W,val,wt,N,dp);
//     }
// int main(){
//     int N,W;
//     int val[1000];
//     int wt[1000];

//     cin>>N;
//     cin>>W;
//     for(int i = 0; i<N; i++){
//         cin>>val[i];
//     }

//     for(int i = 0; i<N; i++){
//         cin>>wt[i];
//     }
//     return knapSack(N, W,val,wt);
// }