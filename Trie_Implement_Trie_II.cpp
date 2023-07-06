#include <bits/stdc++.h>

struct Node {
    Node * child[26];
    int eow = 0;
    int cp = 0;
};
class Trie{
    private: 
        Node *root;
    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        int n = word.size();
        Node * curr = root;
        for(int i=0 ;i < n ;i++)
        {
            int idx = word[i] - 'a';
            if(curr->child[idx] == NULL)
            {
                curr->child[idx] = new Node();
            }
            curr->child[idx]->cp += 1;
            curr = curr->child[idx];
        }
        curr->eow += 1;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        int n = word.size();
        Node * curr = root;
        for(int i = 0 ; i < n ;i++)
        {
            int idx = word[i] - 'a';
            if(curr->child[idx] == NULL)
                return 0;
            curr = curr->child[idx];
        }
        return curr->eow;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        int n = word.size();
        Node * curr = root;
        for(int i = 0 ; i < n ;i++)
        {
            int idx = word[i] - 'a';
            if(curr->child[idx] == NULL)
                return 0;
            curr = curr->child[idx];
        }
        return curr->cp;
    }

    void erase(string &word){
        // Write your code here.
        if(countWordsEqualTo(word)==0) 
            return;
        int n = word.size();
        Node *curr = root;
        for(int i = 0 ; i < n ;i++)
        {
            int idx = word[i] - 'a';

            curr->child[idx]->cp -= 1;
            curr = curr->child[idx];
        }
    
        curr->eow -= 1;
        
    }
};
