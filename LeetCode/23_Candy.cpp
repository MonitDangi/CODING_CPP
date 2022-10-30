#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>inc(ratings.size(),1);
        vector<int>dec(ratings.size(),1);
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i-1]){
                inc[i] = inc[i-1]+1;
            }
        }
        for(int i = ratings.size()-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                dec[i] = dec[i+1]+1;
            }
        }
        int ans = 0;
        for(int i=0;i<ratings.size();i++){
            ans += max(inc[i],dec[i]);
        }
        return ans;

    }
};
int main(){
    return 0;
}