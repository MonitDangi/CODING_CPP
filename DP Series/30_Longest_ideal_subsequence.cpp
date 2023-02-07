#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int>freq(26, 0);
        vector<int>seq(26,0);
        for(int i = 0; i < s.size(); i++){
            int ind = s[i]-'a';
            int x = 1;
            for(int j = 0; j < 26; j++){
                int diff = abs(ind-j);
                if(diff > k)continue;
                else {
                    x = max(x, 1+seq[j]);
                }
            }
            freq[ind]++;
            seq[ind] = x;
        }
        int ans = 1;
        for(int i: seq)ans=max(ans,i);
        return ans;
    }
};
int main(){
    return 0;
}