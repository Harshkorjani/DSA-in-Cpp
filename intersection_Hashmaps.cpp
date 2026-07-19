#include<iostream>
#include<unordered_map>
using namespace std;
template<typename T>
void intersection(int* arr1, int* arr2, int n, int m){
    unordered_map<int,int> map;
    for(int i = 0; i<n; i++){
        map[arr1[i]]++;
    }
    for(int i = 0; i<m; i++){
        if(map.count(arr2[i]) > 0){
            cout<<arr2[i]<<endl;
            map[arr2[i]]--;
        }
    }
}
int main(){
    int arr1[5] = {2,6,8,4,3};
    int arr2[4] = {2,5,3,4};
    intersection<int>(arr1,arr2,5,4);
    return 0;
}
