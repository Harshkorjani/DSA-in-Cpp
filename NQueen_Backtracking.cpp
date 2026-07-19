#include<bits/stdc++.h>
using namespace std;
int board[11][11];
bool isPossible(int n,int row,int column){
    for(int i = row - 1; i>=0; i--){
        if(board[i][column] == 1){
            return false;
        }
    }
    for(int i = row - 1,j = column - 1; i>=0 && j>=0; i--,j--){
        if(board[i][j] == 1){
            return false;
        }
    }
    for(int i = row - 1, j = column + 1;i>=0 && j<n; i--,j++){
        if(board[i][j] == 1){
            return false;
        }
    }
    return true;
}
void Nqueenhelper(int n, int row){
    if(row == n){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    for(int j = 0; j<n; j++){
        if(isPossible(n,row,j)){
            board[row][j] = 1;
            Nqueenhelper(n,row + 1);
            board[row][j] = 0;
        }
    }
    return;
}
int main(){
    int n; 
    cin>>n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            board[i][j] = 0;
        }
    }
    Nqueenhelper(n,0);
    return 0;
}
