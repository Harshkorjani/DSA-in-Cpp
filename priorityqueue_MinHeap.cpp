#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class priorityqueue{
    vector<int> pq;
    public:
    priorityqueue(){

    }
    bool isempty(){
        return pq.size() == 0;
    }
    int getsize(){
        return pq.size();
    }
    int getmin(){
        if(isempty()){
            return 0;
        }
        return pq[0];
    }
    void insert(int element){
        pq.push_back(element);
        int childindex = pq.size() - 1;
        while(childindex > 0){
            int parentindex = (childindex - 1) / 2;
            if(pq[childindex] < pq[parentindex]){
                int temp = pq[childindex];
                pq[childindex] = pq[parentindex];
                pq[parentindex] = temp;
            }
            else{
                break;
            }
            childindex = parentindex;
        }
    }
    int removemin(){
        if(isempty()){
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentindex = 0;
        int LCI = 2*parentindex + 1;
        int RCI = 2*parentindex + 2;
        while(LCI < pq.size()){
            int minindex = parentindex;
            if(pq[minindex] > pq[LCI]){
                minindex = LCI;
            }
            if(RCI < pq.size() && pq[minindex] > pq[RCI]){
                minindex = RCI;
            }
            if(minindex == parentindex){
                break;
            }
            int temp = pq[minindex];
            pq[minindex] = pq[parentindex];
            pq[parentindex] = temp;

            parentindex = minindex;
            LCI = 2*parentindex + 1;
            RCI = 2* parentindex + 2;
        }
        return ans;
    }
};
int main(){
    priorityqueue<int> pq;

    pq.insert(100);
    pq.insert(10);
    pq.insert(15);
    pq.insert(4);
    pq.insert(17);
    pq.insert(21);
    pq.insert(67);
    cout<<pq.getsize()<<endl;
    cout<<pq.getmin()<<endl;
    while(!pq.isempty()){
        cout<<pq.removemin()<<" ";
    }

    return 0;
}