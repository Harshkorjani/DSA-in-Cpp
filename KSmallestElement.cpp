#include<iostream>
using namespace std;
#include<vector>
#include<queue>
vector<int> Ksmallest(int input[], int n, int k){
    priority_queue<int> p;
    vector<int> v;
    for(int i = 0; i<k; i++){
        p.push(input[i]);
    }
    for(int i = k; i<n; i++){
        if(input[i] < p.top()){
            p.push(input[i]);
            p.pop();
        }
    }
    while(!p.empty()){
        v.push_back(p.top());
        p.pop();
    }
    return v;
}