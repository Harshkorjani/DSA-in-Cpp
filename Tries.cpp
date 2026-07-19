#include<iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* *children;
    bool isTerminal;

    TrieNode(char data){
        this->data;
        children = new TrieNode*[26];
        for(int i = 0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }

};
class Trie{
    TrieNode* root;
    public:
    Trie(){
        root = new TrieNode('\0');
    }
    void insertword(TrieNode* root, string word){
        //Base case
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }
        //Small claculation
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        //recursive call
        insertword(child,word.substr(1));
    }
    void insertword(string word){
        insertword(root,word);
    }
    bool search(TrieNode* root, string word){
        //Base case
        if(word.size() == 0){
            if(root->isTerminal == false){
                return false;
            }
            return true;
        }
        //Small claculation
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        //recursive Call
        return search(child,word.substr(1));
    }

    bool search(string word){
        return search(root,word);
    }

    void removeword(TrieNode* root, string word){
        //Base case
        if(word.size() == 0){
            root->isTerminal = false;
            return;
        }
        //Small calculation
        TrieNode* child;
        int index = word[0] - 'a';
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return;
        }
        //Recursive call
        removeword(child,word.substr(1));
        if(child->isTerminal == false){
            for(int i = 0; i<26; i++){
                if(child->children[i] != NULL){
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }
    void removeword(string word){
        removeword(root,word);
    }
};