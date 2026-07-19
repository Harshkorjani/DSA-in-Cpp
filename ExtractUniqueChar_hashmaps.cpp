#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
template<typename T>
string ExtractuniqueChar(string str){
    unordered_map<char,int> map;
    string s;
    if(map.size() == 0){
        map[str[0]] = 1;
        s.push_back(str[0]);
    }
    for(int i = 1; i<str.size(); i++){
        if(map.count(str[i]) > 0){
            continue;
        }
        map[str[i]]++;
        s.push_back(str[i]);
    }
    return s;
}
int main(){
    string str = "abcefdabg";
    str = ExtractuniqueChar<int>(str);
    for(int i = 0; i<str.size(); i++){
        cout<<str[i];
    }
    return 0;
}
