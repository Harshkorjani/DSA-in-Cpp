// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;

//      int i = 1;
//      while(i<=n){
//            int space = 1;
//            while(space<=n-i){
//                cout<<" ";
//                space++;
//            }
//         int j = 1;
//         int p=i;
//         while(j <= i){
//             // cout<<i + j - 1;
//             cout<<p;
//              p++;
//              j++;
//            }
//          j=i-1;
//          p=p-2;
//         while(j>0){
//             cout<<p;
//             p--;
//             j--;
//         }
//         cout<<endl;
//         i++;
//      }
// }
long cc(int *d, int ind, int v,vector<vector<long>> &dp){
    if(v==0) return 1;
    if(ind<0) return 0;
    if(dp[v][ind+1] != -1) return dp[v][ind+1];
    long not_take = cc(d,ind-1,v,dp);
    long take = 0;
    if(d[ind]<=v){
        take = cc(d,ind,v-d[ind],dp);
    }
    return dp[v][ind+1]=take+not_take;
}
long countWaysToMakeChange(int *denominations, int n, int value){
    //Write your code here.
    vector<vector<long>> dp(value+1,vector<long>(n+1,-1));
    return cc(denominations, n-1,value,dp);   
}