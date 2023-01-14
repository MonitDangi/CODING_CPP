#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int>par;
    public:
    DisjointSet(int n){
        par.resize(n);
        for(int i = 1; i<26; i++){
            par[i] = i;
        }
    }
    int findpar(int node){
        if(par[node] == node)return node;
        return par[node] = findpar(par[node]);
    }
    void unionBySize(int u, int v){
        int pu = findpar(u);
        int pv = findpar(v);
        if(pu == pv)return;
        if(pu < pv){
            par[pv] = par[pu];
        }
        else{
            par[pu] = par[pv];
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds(26);
        for(int i = 0; i<s1.size(); i++){
            ds.unionBySize(s1[i]-'a', s2[i]-'a');
        }
        string ans;
        for(int i=0; i< baseStr.size();i++){
            ans.push_back(ds.findpar(baseStr[i]-'a')+'a');
        }
        return ans;
    }
};
int main(){
}