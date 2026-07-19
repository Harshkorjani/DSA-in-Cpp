#include<unordered_map>
#include<vector>
using namespace std;
vector<int> LCS(int * arr, int n){
    unordered_map<int,bool> map;
    vector<int> v;
    for(int i = 0; i<n; i++){
        map[arr[i]] = true;
    }
    for(int i = 0; i<n; i++){
        if(map.count(arr[i] - 1) > 0){
            map[arr[i]] = false;
        }
    }
    int ml = 0;
    int msp = 0;
    for(int i = 0; i<n; i++){
        if(map[arr[i]] == true){
            int tl = 1;
            int tsp = arr[i];
            while(map.count(arr[i] + tl) > 0){
                tl++;
            }
            if(tl > ml){
                ml = tl;
                msp = tsp;
            }
        }
    }
    v.push_back(msp);
    v.push_back(msp + ml -1);
    return v;
}