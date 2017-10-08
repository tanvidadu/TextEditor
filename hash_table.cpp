

#include<iostream>
#include<map>
using namespace std;

class TrieNode{
public:
    char data;
    int  isTerminal;
    map<char,TrieNode*> children;

    TrieNode(char d){
        data = d;
        isTerminal = 0;
    }
};

class Trie{

public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }
    void insertWordHelper(char *word,TrieNode*node){
        if(word[0]=='\0'){
            node->isTerminal += 1;
            return;
        }
        int currentChar = word[0];
        auto  it =
        node->children.find(currentChar);

        TrieNode*child = NULL;
        if(it == node->children.end()){
            child = new TrieNode(currentChar);
            node->children[currentChar] = child;

        }
        else{
            child = it->second;
        }
        insertWordHelper(word+1, child);


    }

    void insertWord(char *word){
        insertWordHelper(word,root);
    }
    bool searchWord(char *word){
        ///Iterative Search

        TrieNode* node = root;

        for(int i=0;word[i]!='\0';i++){
            int currentChar = word[i];
            auto it =
            node->children.find(currentChar);

            if(it==node->children.end()){
                return false;

            }
            else{
                node = it->second;
            }
        }
        return node->isTerminal;

    }


};


int main(){

    Trie t;
    char words[][10] = {"are","a","no","news"};
    char sword[][10] = { "a","new","mango","no","nope"};

    for(int i=0;i<4;i++){
        t.insertWord(words[i]);
    }
    for(int i=0;i<5;i++){
        if(t.searchWord(sword[i])){
            cout<< sword[i]<<" found in trie !" <<endl;
        }
        else{
            cout<< sword[i]<<" not found in trie!"<<endl;
        }
    }
    return 0;
}







