#include <bits/stdc++.h> 
struct Node{
    Node *child[26];
    bool eow;
};
class Trie{
    private :
        Node * root;
    public :
        Trie()
        {
            root = new Node();
        }
        void insert(string &s)
        {
            int n = s.length();
            Node * curr = root;

            for(int  i = 0 ; i < n ; i++)
            {
                int idx = s[i] - 'a';
                if(curr->child[idx] == NULL)
                    curr->child[idx] = new Node();
                curr = curr->child[idx];
            }
            curr->eow = true;
        }
        bool search(string &s)
        {
            int n = s.length();
            Node * curr = root;
            for(int i = 0 ; i < n ;i++)
            {
                int idx = s[i] - 'a';
                if(curr->child[idx] == NULL or curr->child[idx]->eow == false)
                    return false;
                curr = curr->child[idx];
            }
            return true;
        }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie t;
    for(int i = 0 ; i < n ; i++)
        t.insert(a[i]);
    string ans = "";
    for(int i = 0 ; i < n ;i++)
    {
        if(t.search(a[i]))
        {
            if(a[i].length() > ans.length())
                ans = a[i];
            else if(a[i].length() == ans.length() and a[i] < ans)
                ans = a[i];
        }
    }
    return ans != "" ? ans : "None";
}
