#include<unordered_map>
template<typename T>
int pairSum(int* arr, int n){
    unordered_map<int,int> map;
    for(int i = 0; i<n; i++){
        map[arr[i]]++;
    }
    int count = 0;
    for(int i = 0; i<n; i++){
        if(map[-arr[i]] > 0){
            map[arr[i]]--;
            count = count + map[-arr[i]];
        }
    }
    return count;
}