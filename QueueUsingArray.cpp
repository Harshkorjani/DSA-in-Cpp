#include<iostream>
using namespace std;
template<typename T>
class queue{
    T *data;
    int nextindex;
    int size;
    int firstindex;
    int capacity;
    public:
    queue(int s){
        data = new T[s];
        nextindex = 0;
        size = 0;
        firstindex = -1;
        capacity = s;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void enqueue(T element){
        if(size == capacity){
            T* newdata = new T[2*capacity];
            int j = 0;
            for(int i = firstindex; i<capacity;i++){
                newdata[j] = data[i];
                j++;
            }
            for(int i = 0; i<firstindex; i++){
                newdata[j] = data[i];
                j++;
            }
            delete [] data;
            data = newdata;
            firstindex = 0;
            nextindex = capacity;
        }
        data[nextindex] = element;
        nextindex = (nextindex + 1)% capacity;
        if(firstindex == -1){
            firstindex = 0;
        }
        size++;
    }
    T front(){
        if(isEmpty()){
            cout<<"Queue is Empty ! "<<endl;
            return 0;
        }
        return data[firstindex];
    }
    T dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty ! "<<endl;
            return 0;
        }
        T ans = data[firstindex];
        firstindex = (firstindex + 1)%capacity;
        size--;
        if(size == 0){
            firstindex = -1;
            nextindex = 0;
        }
        return ans;
    }
};
int main(){
    queue<int> s(5);
    s.enqueue(10);
    s.enqueue(20);
    s.enqueue(30);
    s.enqueue(40);
    s.enqueue(50);
    s.enqueue(60);

    cout<<s.front()<<endl;

    cout<<s.dequeue()<<endl;
    cout<<s.dequeue()<<endl;
    cout<<s.dequeue()<<endl;

    cout<<s.getSize()<<endl;

    cout<<s.isEmpty()<<endl;

}
