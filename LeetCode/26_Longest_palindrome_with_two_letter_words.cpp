#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int ans = 0;

        for(int i = 0; i < words.size(); i++){
            if(mp[words[i]]){
                ans+= 4;
                mp[words[i]]--;
            }
            else{
                reverse(words[i].begin(),words[i].end());
                mp[words[i]]++;
            }
        }
        for(auto x:mp){
            if(x.second ==0)continue;
            string v = x.first;
            if(v[0]==v[1]){
                ans+=2;
                break;
            }

        }
        return ans;
    }
};
int main(){
    return 0;
}