#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main(){
    unordered_map<string,int> ourmap;
    pair<string,int> p("abc", 1);
    ourmap.insert(p);

    ourmap["def"] = 2;

    cout<<ourmap["abc"]<<endl;
    cout<<ourmap.at("abc")<<endl;

    ourmap["ghi"] = 3;
    cout<<ourmap["ghi"]<<endl;
    cout<<ourmap.at("ghi")<<endl;

    cout<<ourmap.size()<<endl;
    if(ourmap.count("ghi") > 0){
        cout<<"ghi is present"<<endl;
    }

    ourmap.erase("ghi");
    cout<<ourmap.size()<<endl;

    return 0;
}
