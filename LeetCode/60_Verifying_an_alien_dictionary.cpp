#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int>mp;
class Solution {
    
    static bool cmp(string&a, string &b){
        int n = min(a.size(), b.size());
        for(int i = 0; i < n;i++){
            if(mp[a[i]]< mp[b[i]])return true;
            else if(mp[a[i]]> mp[b[i]])return false;
        }
        if(a.size() <= b.size())return true;
        return false;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < 26; i++){
            mp[order[i]] = i+1;
        }
        vector<string>temp = words;
        
        sort(words.begin(), words.end(),cmp);
        return temp == words;
    }
};
int main(){
}