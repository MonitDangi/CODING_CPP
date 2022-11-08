#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        int count = 0;
        stack<char>st;
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='(')st.push(s[i]);
            else if(s[i]=='*')count++;
            else {
                if(count == 0 && st.size() == 0){
                    return false;
                }
                else if(st.size())st.pop();
                else{
                    count--;
                }
            }
        }
        if(st.size() && count < st.size())return false;

        count = 0;
        while(st.size())st.pop();
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i]==')')st.push(s[i]);
            else if(s[i]=='*')count++;
            else {
                if(count == 0 && st.size() == 0){
                    return false;
                }
                else if(st.size())st.pop();
                else{
                    count--;
                }
            }
        }
        if(st.size() && count < st.size())return false;
        return true;
    }
};
int main(){
 
    return 0;
}