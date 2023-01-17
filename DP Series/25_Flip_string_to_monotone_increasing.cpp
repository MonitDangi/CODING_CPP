#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int zero = 0, one = 0;
        vector<int>zeroes, ones;
        for(int i = 0; i < n; i++){
            if(s[i] == '0')zero++;
            else one++;
            zeroes.push_back(zero);
            ones.push_back(one);
        }
        int ans = zero;
        for(int i = 0; i < n; i++){
            int changeToZero = ones[i] + zero-zeroes[i];
            ans = min(ans,changeToZero);
        }
        return ans;
    }
};
int main(){
}