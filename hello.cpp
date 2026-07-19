#include<bits/stdc++.h>
using namespace std;
class node{
    public :
    int val;
    node *next;

    node(int val){
        this->val = val;
        this->next = NULL;
    }
};

int print(){
    node *n1 = new node(1);
    node *n2 = new node(2);
    node *n3 = new node(3);

    n1->next = n3;
    n3->next = n2;
    int sum = 0;
    node *temp = n1;
    while(temp != NULL){
        sum += temp->val;
        cout<<temp->val<<endl;
        temp = temp->next;
    }
    cout<<"The sum of all the nodes of the LL is : ";
    return sum;
}

int main(){
    cout<< print();
    return 0;
}