#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string ans="";
        
        int s1=s.size();
        vector<string>ans1;
        for(int i=0;i<numRows;i++){
            ans1.push_back(ans);
        }
        if(s1<=numRows||numRows==1){
            return s;
        }
        int left=0;
        while(left<s1){
            for(int i=0;i<numRows-1&&left<s1;i++){
                if(i%(numRows-1)==0){
                    for(int j=0;j<numRows&&left<s1;j++){
                        ans1[j].push_back(s[left++]);
                    }
                    continue;
                }
                if(left==s1){
                    break;
                }
                ans1[numRows-i-1].push_back(s[left++]);
            }
        }
        for(int i=0;i<numRows;i++){
            ans+=ans1[i];
        }
        return ans;
    }
};
int main(){
}