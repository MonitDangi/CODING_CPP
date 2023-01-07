#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin(),gas.end(),0)<accumulate(cost.begin(),cost.end(),0))return -1;
        int rem_fuel =0;
        int ans = 0;
        for(int i=0;i<gas.size();i++){
            rem_fuel += gas[i]-cost[i];
            if(rem_fuel<0){
                rem_fuel=0;
                ans = i+1;
            }
        }
        return ans;
    }
};
int main(){
}