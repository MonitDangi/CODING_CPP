#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        int temp;
        for(auto & it: queries){
            int a = it[0], b = it[1];
            temp = 1;
            while(a!=b){
                temp++;
                if(a > b){
                   a/=2;
                }
                else{
                    b/=2;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
int main(){
}