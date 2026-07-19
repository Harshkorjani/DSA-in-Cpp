#include<bits/stdc++.h>
using namespace std;
void lcs(string s, string t){
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    string str = "";
    int i = n, j = m;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            str += s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    reverse(str.begin(), str.end());
    cout<<str<<endl;
}

int main(){
    string s,t;
    cin>>s;
    cin>>t;
    lcs(s,t);
    return 0;
}