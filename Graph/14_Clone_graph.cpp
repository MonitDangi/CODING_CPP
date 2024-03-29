#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
    unordered_map<Node *, Node *>mp;
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)return NULL;
        if(mp[node])return mp[node];
        Node * ans = new Node(node->val);
        ans->neighbors.resize(node->neighbors.size());
        mp[node] = ans;
        for(int i = 0; i < node->neighbors.size(); i++){
            ans->neighbors[i] = cloneGraph(node->neighbors[i]);
        }
        return ans;
    }
};
int main(){
}