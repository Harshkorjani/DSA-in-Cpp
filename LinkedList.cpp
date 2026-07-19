#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};
int main(int argc, char const *argv[]){
    node n1(1);
    node n2(2);
    node n3(3);
    n1.next = &n2;
    n2.next = &n3;

    node *temp = &n1;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}
