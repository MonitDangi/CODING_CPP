#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int a) {
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>>rem;
        for(int i = 0; i < rocks.size(); i++){
            rem.push(capacity[i]-rocks[i]);
        }
        while(rem.size()){
            if(rem.top() == 0){
                ans++;
                rem.pop();
            }
            else{
                if(rem.top()>a)break;
                else{
                    ans++;
                    a -= rem.top();
                    rem.pop();
                }
            }
        }
        return ans;
    }
};
int main(){
}