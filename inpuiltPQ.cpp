#include<iostream>
using namespace std;
#include<queue>
int main(){
    priority_queue<int> p;
    p.push(1);
    p.push(71);
    p.push(69);
    p.push(4);
    p.push(-3);
    p.push(34);

    cout<<"Size: "<<p.size()<<endl;
    cout<<"Top: "<<p.top()<<endl;

    while(!p.empty()){
        cout<<p.top()<<endl;
        p.pop();
    }
    return 0;
}
