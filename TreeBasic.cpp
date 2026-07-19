#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include<math.h>
template<typename T>
class Treenode{
    public:
    T data;
    vector<Treenode<T>*>children;
    Treenode(T data){
        this->data = data;
    }
};
void PrintTree(Treenode<int>*root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i = 0; i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i = 0; i<root->children.size();i++){
        PrintTree(root->children[i]);
    }
}
void printTreeLevelwise(Treenode<int>*root){
    if(root == NULL){
        return;
    }
    queue<Treenode<int>*>pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size() != 0){
        
        Treenode<int>*front = pendingnodes.front();
        cout<<front->data<<":";
        pendingnodes.pop();
        for(int i = 0; i<front->children.size();i++){
            int j = front->children.size() - 1;
            if(i == j){
                cout<<front->children[i]->data;
                pendingnodes.push(front->children[i]);
                break;
            }
            cout<<front->children[i]->data<<" ";
            pendingnodes.push(front->children[i]);
        }
        cout<<endl;
    }
}
int NumNodes(Treenode<int>*root){
    int ans = 1;
    for(int i = 0; i<root->children.size();i++){
        ans = ans + NumNodes(root->children[i]);
    }
    return ans;
}
Treenode<int>* takeinput(){
    int rootdata;
    cout<<"Enter data"<<endl;
    cin>>rootdata;
    Treenode<int>*root = new Treenode<int>(rootdata);
    int n;
    cout<<"Enter the no. of childrens: "<<endl;
    cin>>n;
    for(int i = 0; i<n; i++){
        Treenode<int>* child = takeinput();
        root->children.push_back(child);
    }
    return root;
}
Treenode<int>* takeinputLevelwise(){
    int rootdata;
    cout<<"Enter the root data: "<<endl;
    cin>>rootdata;
    Treenode<int>*root = new Treenode(rootdata);
    queue<Treenode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size() != 0){
        Treenode<int>*front = pendingnodes.front();
        pendingnodes.pop();
        cout<<"Enter no. of child of "<<front->data<<" ";
        int numchild;
        cin>>numchild;
        for(int i = 0; i<numchild;i++){
            int childdata;
            cout<<"Enter "<<i<<"th child of "<<front->data<<" ";
            cin>>childdata;
            Treenode<int>*child = new Treenode(childdata);
            front->children.push_back(child);
            pendingnodes.push(child);
        }
    }
    return root;
}
int Height(Treenode<int>* root){
    int height = 0;
    for(int i = 0; i<root->children.size();i++){
        int ch = Height(root->children[i]);
        height = max(height,ch);
    }
    height += 1;
    return height;
}
int main(){
    /*Treenode<int>*root = new Treenode<int>(1);
    Treenode<int>*node1 = new Treenode<int>(2);
    Treenode<int>*node2 = new Treenode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
    */
    Treenode<int>*root = takeinputLevelwise();
    printTreeLevelwise(root);
    int ans = NumNodes(root);
    cout<<ans<<endl;
    int height = Height(root);
    cout<<height;
    return 0;
}
