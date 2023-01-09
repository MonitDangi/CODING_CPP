#include<bits/stdc++.h>
using namespace std;
class Solution {
    int find(int l, int h, int k, int curr){
        int m = l + (h-l)/2;
        if(h-l == 0)return curr;
        if(m < k){
            return find(m+1,h,k,1-curr);
        }
        return find(l, m, k, curr);
    }
public:
    int kthGrammar(int n, int k) {
        int l = 1, h = pow(2,n-1);
        int ans = find(l,h,k,0);
        return ans;
    }
};
int main(){
}