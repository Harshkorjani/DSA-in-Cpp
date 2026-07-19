#include<queue>
template<typename T>
int buyTicket(int arr[], int n, int k){
    priority_queue<int> pq;
    queue<int> q;
    for(int i = 0; i<n; i++){
        if(i == k){
            q.push(-1);
        }
        q.push(arr[i]);
        pq.push(arr[i]);
    }
    int time = 0;
    while(q.front() != -1 || pq.top() != arr[k]){
        if(pq.top() == q.front()){
            time++;
            q.pop();
            pq.pop();
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }
    time++;
    return time;
}