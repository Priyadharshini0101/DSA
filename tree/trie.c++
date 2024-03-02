#include <iostream>
#include <bits/stdc++.h>

const int ALPHABET_SIZE = 26;

struct TrieNode{
    bool isEndOfWord;
    std::vector<TrieNode*> children;
    TrieNode(): isEndOfWord(false), children(ALPHABET_SIZE, NULL) {}
};

class Trie{
    private:
        TrieNode* root;

        TrieNode* getNode(){
            TrieNode* newNode = new TrieNode();
            return newNode;
        }
        
        bool isEmpty(TrieNode* temp){
            for(int i=0;i<ALPHABET_SIZE;i++){
                if(temp -> children[i] != NULL){
                    return false;
                }
            }
            return true;
        }
     
    public:
        Trie(){
            root = getNode();
        }
        
        void insert(std::string word){
            TrieNode* current = root;
            for(char c:word){
                int i = c - 'a';
                if(current -> children[i] == NULL){
                    current -> children[i] = getNode();
                }
                current = current -> children[i];
            }
            current -> isEndOfWord = true;
        }
        
        bool search(std::string word){
            TrieNode* current = root;
            for(char c:word){
                int i = c - 'a';
                if(current -> children[i] == NULL){
                    return false;
                }
                current = current -> children[i];
            }
            return current -> isEndOfWord;
        }
        
        bool hasPrefix(std::string prefix){
            TrieNode* current = root;
            for(char c: prefix){
                int i = c - 'a';
                if(current -> children[i] == NULL){
                    return false;
                }
                current = current -> children[i];
            }
            return true;
        }
        
        void deleteHelper(TrieNode* current, std::string word, int index){
            if(index == word.length()){
                current -> isEndOfWord = false;
                return;
            }
            int i = word[index] - 'a';
            if(current -> children[i] == NULL){
             return;   
            }
            deleteHelper(current -> children[i], word, index + 1);
            if(isEmpty(current -> children[i])){
                delete current -> children[i];
                current -> children[i] = NULL;
            }
        }
        
        void deleteWord(std::string word){
            deleteHelper(root,word,0);
        }
};

int main(){
    Trie trie;
    
    trie.insert("apple");
    trie.insert("ape");
    trie.insert("banana");
    
    std::cout<<"Search apple:"<<trie.search("apple")<<"\n";
    std::cout<<"Search ape:"<<trie.search("ape")<<"\n";
    std::cout<<"Search banana:"<<trie.search("banana")<<"\n";
    
    trie.deleteWord("ape");
    
    std::cout<<"Search ape after deletion:"<<trie.search("ape")<<"\n";
    
    std::cout<<"Prefix search app:"<<trie.hasPrefix("app")<<"\n";
    
    return 0;
}