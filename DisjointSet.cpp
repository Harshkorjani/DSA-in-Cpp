#include<bits/stdc++.h>
using namespace std;
class disjointSet{
    vector<int> parent, rank,size;
public:
    disjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUltimateParent(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        
    }

    void unionBySize(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main(){
    disjointSet ds(4);
    ds.unionBySize(0,1);
    ds.unionBySize(1,2);
    
    if(ds.findUltimateParent(2) == ds.findUltimateParent(3)){
        cout<<"same"<<endl;
    }else{
        cout<<"not same"<<endl;
    }

    ds.unionBySize(2,3);

    if(ds.findUltimateParent(2) == ds.findUltimateParent(3)){
        cout<<"same"<<endl;
    }else{
        cout<<"not same"<<endl;
    }
    
    return 0;
}
