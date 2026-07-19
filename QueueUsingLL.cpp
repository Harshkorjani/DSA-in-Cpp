#include<iostream>
using namespace std;
template<typename T>
class Node{
    public:
    int data;
    Node<T>* next;
    Node(T data){
        this->data = data;
        next = NULL;
    }
};
template<typename T>
class Queue{
    Node<T>* head;
    Node<T>* tail;
    int size;
    public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int getsize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void enqueue(T element){
        Node<T>* newnode = new Node<T>(element);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode; 
        }
        size++;
    }
    T front(){
        if(isEmpty()){
            return -1;
        }
        return head->data;
    }
    T dequeue(){
        if(isEmpty()){
            return -1;
        }
        Node<T>* temp = head;
        T ans = head->data;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
};
int main(){
    Queue<char> s;
    s.enqueue('a');
    s.enqueue('b');
    s.enqueue('c');
    s.enqueue('d');
    s.enqueue('e');
    s.enqueue('f');

    cout<<s.front()<<endl;

    cout<<s.dequeue()<<endl;
    cout<<s.dequeue()<<endl;
    cout<<s.dequeue()<<endl;

    cout<<s.getsize()<<endl;

    cout<<s.isEmpty()<<endl;
}
