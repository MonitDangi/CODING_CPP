#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())return false;
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(char c:word1)mp1[c]++;
        for(char c:word2)mp2[c]++;
        if(mp1.size()!=mp2.size())return false;
        vector<int>v1;
        vector<int>v2;
        vector<char>c1;
        vector<char>c2;
        for(auto x:mp1){
            v1.push_back(x.second);
            c1.push_back(x.first);
        }
        for(auto x:mp2){
            v2.push_back(x.second);
            c2.push_back(x.first);
        }        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        sort(c1.begin(),c1.end());
        sort(c2.begin(),c2.end());
        if(v1==v2 && c1 == c2)return true;
        return false;
    }
};
int main(){
 
    return 0;
}