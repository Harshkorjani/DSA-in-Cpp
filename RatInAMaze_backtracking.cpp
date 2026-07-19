#include<bits/stdc++.h>
using namespace std;
void print(int solution[20][20], int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<solution[i][j]<<" ";
        }
    }
    cout<<endl;
    return;
}
void helper(int maze[20][20], int solution[20][20],int n,int x, int y){
    if(x == n-1 && y == n-1){
        solution[x][y] = 1;
        print(solution,n);
        return;
    }
    if(x>n-1 || x<0 || y>n-1 || y<0 || maze[x][y] == 0 || solution[x][y] == 1){
        return;
    }
    solution[x][y] = 1;
    helper(maze,solution,n,x-1,y);
    helper(maze,solution,n,x+1,y);
    helper(maze,solution,n,x,y-1);
    helper(maze,solution,n,x,y+1);
    solution[x][y] = 0;
}
void RatInAMaze(int maze[20][20],int n){
    int solution[20][20];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            solution[i][j] = 0;
        }
    }
    helper(maze,solution,n,0,0);
}
int main(){
    int n;
    cin>>n;
    int maze[20][20];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>maze[i][j];
        }
    }
    RatInAMaze(maze,n);
    return 0;
}
