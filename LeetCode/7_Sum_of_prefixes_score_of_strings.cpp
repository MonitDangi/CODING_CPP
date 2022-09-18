#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    vector<int>qua;
    vector<Node*>child;
    Node (){
        child.resize(26,NULL);
        qua.resize(26,0);
    }
};

class Solution {
    void insert(Node * root, string & word){
        for(int i=0;i<word.size();i++){
            int j = word[i]-'a';
            if(root->child[j]==NULL){
                Node * neu = new Node();
                root->child[j] = neu; 
            }
            root->qua[j]++;
            root = root->child[j];
        }
    }
    int search(string word,Node * root){
        
        int prev=0;
        for(int j=0;j<word.length();j++){
            prev += root->qua[word[j]-'a'];
            root = root->child[word[j]-'a'];
            if(root==NULL)break;
            
        }
        return prev;
    }
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Node * head = new Node();
        for(int i=0;i<words.size();i++){
            insert(head,words[i]);
        }
        vector<int>ans;
        for(int i=0;i<words.size();i++){
            int temp = search(words[i],head);
            ans.push_back(temp);
        }
        return ans;
    }
};
int main(){
    return 0;
}