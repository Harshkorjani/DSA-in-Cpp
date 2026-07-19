#include<iostream>
using namespace std;
template <typename T>
class BinaryTree{
    public:
    T data;
    BinaryTree<T>* left;
    BinaryTree<T>* right;
    BinaryTree(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class BST{
    public:
    BinaryTree<int>* root;
    BST(){
        root = NULL;
    }
    private:
    bool searchhelper(int data, BinaryTree<int>* node){
        if(node == NULL){
            return NULL;
        }
        if(node->data == data){
            return true;
        }
        else if(node->data < data){
            return searchhelper(data,node->right);
        }
        else{
            return searchhelper(data,node->left);
        }
        return node;
    }
    BinaryTree<int>* inserthelper(int data,BinaryTree<int>* node){
        if(root == NULL){
            BinaryTree<int>* newnode = new BinaryTree<int>(data);
            return newnode;
        }
        if(data <= node->data){
            node->left = inserthelper(data,node->left);
        }
        else{
            node->right = inserthelper(data,node->right);
        }
        return node;
    }
    BinaryTree<int>* deletehelper(int data,BinaryTree<int>* node){
        if(node == NULL){
            return NULL;
        }
        if(data < node->data){
            node->left = deletehelper(data,node->left);
            return node;
        }
        else if(data > node->data){
            node->right = deletehelper(data,node->right);
            return node;
        }
        else{
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }
            else if(node->left == NULL){
                BinaryTree<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if(node->right == NULL){
                BinaryTree<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else{
                BinaryTree<int>* minnode = node->right;
                while(minnode->left != NULL){
                    minnode = minnode->left;
                }
                int rightmin = minnode->data;
                node->data = rightmin;
                node->right = deletehelper(rightmin,node->right);
                return node;
            }
        }
    }
    void printTreehelper(BinaryTree<int>* node){
        if(node == NULL){
            return;
        }
        cout<<node->data<<":";
        if(node->left != NULL){
            cout<<"L:"<<node->left->data<<",";
        }
        if(node->right != NULL){
            cout<<"R:"<<node->right->data;
        }
        printTreehelper(node->left);
        printTreehelper(node->right);
    }
    public:
    void insert(int data){
        root = inserthelper(data,root);
    }
    void deletedata(int data){
        root = deletehelper(data,root);
    }
    void printTree(){
        printTreehelper(root);
    }
    bool search(int data){
        return searchhelper(data,root);
    }
};
int main(){
    BST b;
    b.insert(4);
    b.insert(5);
    b.insert(3);
    b.insert(6);
    b.printTree();
    return 0;
}