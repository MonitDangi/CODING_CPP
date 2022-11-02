#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int count = 0;
        queue<string>rem;
        unordered_map<string,int>mp;
        for(auto x:bank)mp[x]++;
        rem.push(start);
        while(rem.size()){
            int size = rem.size();
            while(size--){
                string s = rem.front();
                if(s == end)return count;
                rem.pop();
                for(int i=0;i<8;i++){
                    char c = s[i];
                    s[i] = 'A';
                    if(mp[s]){
                        rem.push(s);
                        mp[s]--;
                    }
                    s[i] = 'C';
                    if(mp[s]){
                        rem.push(s);
                        mp[s]--;
                    }
                    s[i] = 'G';
                    if(mp[s]){
                        rem.push(s);
                        mp[s]--;
                    }
                    s[i] = 'T';
                    if(mp[s]){
                        rem.push(s);
                        mp[s]--;
                    }
                    s[i] = c;
                }
            }
            count++;
        }
        return -1;
    }
};
int main(){
    return 0;
}