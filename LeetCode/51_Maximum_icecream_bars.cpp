#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        for(int i = 0; i < costs.size(); i++){
            if(costs[i] > coins)break;
            else{
                ans++;
                coins -= costs[i];
            }
        }
        return ans;
    }
};
int main(){
}