#include <bits/stdc++.h>
struct Node {
    Node *child[26];
};  
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    Node *root = new Node();
    int n = s.length();
    int count = 0;
    for(int i = 0 ; i < n ;i++)
    {
        Node * curr = root;
        for(int  j = i ; j < n ;j++)
        {
            int idx = s[j] - 'a';
            if(curr->child[idx] == 0) 
            {
                curr->child[idx] = new Node();
                count++;
            }
                
            curr = curr->child[idx];
        }
    }

    return count+1;
}
