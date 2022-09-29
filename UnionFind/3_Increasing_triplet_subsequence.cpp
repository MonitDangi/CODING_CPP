#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num1 = INT_MAX;
        int num2 = INT_MAX;
        for(int x:nums){
            if(x<=num1){
                num1 = x;
            }
            else if(x<=num2)num2 = x;
            else{
                return true;
            }
        }
        return false;
    }
};
int main(){
    return 0;
}