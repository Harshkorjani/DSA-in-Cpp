#include<queue>
#include<bits/stdc++.h>
template<typename T>
void Runningmedian(int arr[] ,int n){
    if(n == 0){
        return;
    }
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>, greater<int>> minheap;

    maxheap.push(arr[0]);
    cout<<maxheap.top()<<" ";

    for(int i = 1; i<n; i++){
        if(arr[i] > maxheap.top()){
            minheap.push(arr[i]);
        }
        else{
            maxheap.push(arr[i]);
        }
        if(abs(maxheap.size() - minheap.size()) > 1){
            if(maxheap.size() > minheap.size()){
                minheap.push(maxheap.top());
                maxheap.pop();
            }
            else{
                maxheap.push(minheap.top());
                minheap.pop();
            }
        }
        if(maxheap.size() == minheap.size()){
            int ans = (maxheap.top() + minheap.top()) / 2;
            cout<<ans<<" "; 
        }
        else if(maxheap.size() > minheap.size()){
            cout<<maxheap.top()<<" ";
        }
        else{
            cout<<minheap.top()<<" ";
        }
    }
}