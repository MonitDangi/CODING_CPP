#include<bits/stdc++.h>
using namespace std;
class Solution {
    int mod = 1e9+7;
public:
    int numTilings(int n) {
        if(n<3)return n;
        vector<long long>v = {1,1,2};
        long long temp;
        for(int i = 3; i<=n;i++){
            temp = (2* v[i-1] + v[i-3])%mod;
            v.push_back(temp);
        }
        return v[n];
    }
};
int main(){
}