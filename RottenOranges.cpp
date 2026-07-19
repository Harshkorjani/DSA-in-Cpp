#include<bits/stdc++.h>
using namespace std;
int rottenOranges(vector<vector<int>> &grid){
    queue<pair<int,pair<int,int>>>q;
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(),0));
    for(int i = 0; i<grid.size(); i++){
        for(int j = 0; j<grid[0].size(); j++){
            visited[i][j] = grid[i][j];
            if(grid[i][j] == 2){
                q.push({0,{i,j}});
            }
        }
    }
    int maxi = 0;
    while(!q.empty()){
        int t = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        maxi = max(maxi,t);
        q.pop();

        int row[4] = {1,-1,0,0};
        int column[4] = {0,0,1,-1};

        for(int i = 0; i<4; i++){
            int nr = r + row[i];
            int nc = c + column[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc <grid[0].size() && visited[nr][nc] == 1){
                visited[nr][nc] = 2;
                q.push({t+1,{nr,nc}});
            }
        }
    }
    for(int i = 0; i<grid.size(); i++){
        for(int j = 0; j<grid[0].size(); j++){
            if(visited[i][j] == 1) return -1;
        }
    }
    return maxi;
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m,0));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>grid[i][j];
        }
    }

    cout<<rottenOranges(grid);
    return 0;
}