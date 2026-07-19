#include<unordered_map>
#include<vector>
#include<climits>
#include<iostream>
using namespace std;
int highestFrequency(int * arr, int n){
    unordered_map<int,int> map;
    vector<int> output;
    for(int i =0; i<n; i++){
        if(map.count(arr[i]) > 0){
            map[arr[i]]++;
            continue;
        }
        map[arr[i]] = 1;
        output.push_back(arr[i]);
    }
    int max = INT_MIN;
    int ans;
    for(int i = 0; i < output.size(); i++){
        if(map[output[i]] > max){
            max = map[output[i]];
            ans = output[i];
        }
    }
    return ans;
}
int main(){
    int arr[] = {1,2,2,1};
    int ans = highestFrequency(arr,4);
    cout<<ans<<" ";
    cout<<endl;
    return 0;
}
