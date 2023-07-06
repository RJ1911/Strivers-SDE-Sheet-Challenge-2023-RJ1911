#include<iostream>
#include<vector>
using namespace std;

struct Node{
    Node * children[26];
    bool eow = false;
    Node()
    {
        for(int i = 0 ; i < 26 ; i++)
            children[i] = NULL;
    }
};

class Trie{
    private :
        Node * root;
    public:
        Trie()
        {
            root = new Node();
        }
        void insert(string word)
        {
            Node * curr = root;
            for(int i = 0 ; i < word.length();i++)
            {
                int idx = word[i] - 'a';
                if(curr->children[idx] == NULL)
                {
                    curr->children[idx] = new Node();
                }
                if(i == word.length() - 1)
                    curr->children[idx]->eow = true;
                curr = curr->children[idx];
            }
        }

        bool search(string key)
        {
            Node *curr = root;
            for(int i = 0 ; i < key.length() ; i++)
            {
                int idx = key[i] - 'a';
                if(curr->children[idx] == NULL)
                    return false;
                else if(i == key.length()-1 and curr->children[idx]->eow == false)
                    return false;

                curr = curr->children[idx];
            }
            return true;
        }
        
};
int main()
{
    vector<string> words = {"the","there","a","apples","apps"};

    Trie t;

    for(int i = 0 ; i < words.size(); i++)
    {
        t.insert(words[i]);
    }
    cout<<t.search("apples");
    return 0;
}
