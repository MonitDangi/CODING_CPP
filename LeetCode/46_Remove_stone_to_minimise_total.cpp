#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>rem;
        for(auto x:piles)rem.push(x);
        int temp;
        while(k--){
            temp = rem.top();
            temp = (1+temp)/2;
            rem.pop();
            rem.push(temp);
        }
        int ans = 0;
        while(rem.size()){
            ans += rem.top();
            rem.pop();
        }
        return ans;
    }
};
int main(){
}