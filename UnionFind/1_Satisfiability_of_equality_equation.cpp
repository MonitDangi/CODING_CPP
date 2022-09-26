#include<bits/stdc++.h>
using namespace std;
class Solution {
    int uf[26];
    int find(int x) {
        if(uf[x]==x){
            return uf[x] = x;
        }
        return uf[x] = find(uf[x]);
        
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; ++i) uf[i] = i;
        for (auto e : equations) {
            if (e[1] == '=') uf[find(e[0] - 'a')] = find(e[3] - 'a');
        }
        for (auto e : equations) {
            if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a')) return false;
        }
        return true;
    }
};

int main(){
    return 0;
}