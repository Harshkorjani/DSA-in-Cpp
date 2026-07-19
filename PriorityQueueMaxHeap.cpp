#include<iostream>
using namespace std;
#include<vector>
template<typename T>
class priorityQueue{
    vector<int> pq;
    public:
    priorityQueue{

    }
    bool isEmpty(){
        return pq.size() == 0;
    }
    int getSize(){
        return pq.size();
    }
    int getMax(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }
    void insert(int element){
        pq.push_back(element);
        int CI = pq.size() - 1;
        while(CI > 0){
            int PI = (CI -1) / 2;
            if(pq[CI] > pq[PI]){
                int temp = pq[CI];
                pq[CI] = pq[PI];
                pq[PI] = temp;
            }
            else{
                break;
            }
            CI = PI;
        }
    }

    int getMax(){
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int PI = 0;
        int LCI = 2*PI + 1;
        int RCI = 2*PI + 2;
        while(LCI < pq.size()){
            int maxindex = PI;
            if(pq[LCI] > pq[maxindex]){
                maxindex = LCI; 
            }
            if(RCI < pq.size() && pq[RCI] > pq[maxindex]){
                maxindex = RCI;
            }
            if(maxindex == PI){
                break;
            }
            int temp = pq[PI];
            pq[PI] = pq[maxindex];
            pq[maxindex] = temp;
            PI = maxindex;
            LCI = 2*PI + 1;
            RCI = 2*PI + 2;
        }
        return ans;
    }
};
int main(){
    return 0;
}
