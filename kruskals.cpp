#include <iostream>
#include<algorithm>
using namespace std;
class Edge{
    public:
    int source;
    int dest;
    int weight;
};
bool compare(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}
int findParent(int v, int*parent){
    if(parent[v] == v){
        return v;
    }
    return findParent(parent[v],parent);
}
void kruskals(Edge *input, int n, int E){
    //Sort the input array in terms of weight using compare function
    sort(input, input + E, compare);
    int * parent = new int[n];
    for(int i = 0; i<n; i++){
        parent[i] = i;
    }
    Edge *output = new Edge[n-1];
    int count = 0;
    int i = 0;
    while(count != n-1){
        // check if the current edge can be included in MST or Not
        Edge currentedge = input[i];
        int sourceParent = findParent(currentedge.source, parent);
        int destParent = findParent(currentedge.dest, parent);
        if(sourceParent != destParent){
            output[count] = currentedge;
            parent[sourceParent] = destParent;
            count++;
        }
        i++;
    }
    for(int i = 0; i<n-1; i++){
        if(output[i].source < output[i].dest){
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else{
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        }
    }
}
int main() {
    // Write your code here
    int n,E;
    cin>>n>>E;
    Edge *input = new Edge[E];
    for(int i = 0; i<E; i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    kruskals(input,n,E);
}