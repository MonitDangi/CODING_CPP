#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool isValid(string s){
        if(s.size() == 0 ||s.size() > 3 || stoi(s)>255 )return false;
        if(s.size()>1 && s[0]=='0')return false;
        return true;
    }
    void find(string &s, int ind, vector<string>&ans,string ip,int count){
        if(count == 4){
            if(ind != s.size())return;
            ans.push_back(ip);
            return;
        }
        if(ind >= s.size()){
            return;
        }
        if(ip.size())ip.push_back('.');
        string temp;
        for(int i = ind; i < ind+3 && i < s.size();i++){
            temp.push_back(s[i]);
            if(isValid(temp)){
                find(s,i+1,ans,ip+temp,count+1);
            }
            else {
                return;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        find(s,0,ans,"",0);
        return ans;
    }
};
int main(){
    return 0;
}