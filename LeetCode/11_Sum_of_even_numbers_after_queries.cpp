#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int sum =0 ;
        for(int i=0; i<nums.size();i++){
            if(nums[i]%2==0)sum += nums[i];
        }
        for(int i=0; i<queries.size();i++){
            int x = queries[i][0], y = nums[queries[i][1]];
            if(x % 2 == 0 && y%2==0){
                sum += x;
            }
            else if(abs(x) % 2 == 1 &&abs(y)%2==1){
                sum += x;
                sum += y;
            }
            else if(y%2 == 0)sum -= y;
            ans.push_back(sum);
            nums[queries[i][1]] += queries[i][0];
        }
        return ans;
    }
};
int main(){
    return 0;
}