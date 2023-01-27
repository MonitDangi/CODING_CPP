#include<bits/stdc++.h>
using namespace std;
class Trie{
    public:
    Trie * child[26];
    bool isEnd;
    Trie(){
        for(int i = 0; i < 26; i++)child[i] = NULL;
        isEnd = false;
    }
};
class Solution {
    Trie * mainroot;
private:
    void insert(int ind, string & word, Trie * root){
        if(ind == word.size())return;
        if(!root->child[word[ind]-'a']){
            Trie * node  = new Trie();
            root->child[word[ind]-'a'] = node;
        }
        if(ind == word.size()-1){
            root->child[word[ind]-'a']->isEnd = true;
            return;
        }
        insert(ind+1, word, root->child[word[ind]-'a']);
    }
    bool find(int ind, string & word, Trie * root, int count){
        if(ind == word.size()-1){
            if(root->child[word[ind]-'a'] && root->child[word[ind]-'a']->isEnd)return count;
            return false;
        }
        if(!root->child[word[ind]-'a'])return false;
        int num = 0;
        bool b = false;
        if(root->child[word[ind]-'a']->isEnd){
            b = find(ind+1, word, mainroot,count+1);
        }
        bool a = find(ind+1, word, root->child[word[ind]-'a'],count);
        return a | b;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie * x = new  Trie();
        mainroot = x;
        for(auto & x: words){
            insert(0, x, mainroot);
        }
        vector<string>ans;
        for(auto & x: words){
            if(find(0, x, mainroot,0))ans.push_back(x);
        }
        return ans;
    }
};
int main(){
}