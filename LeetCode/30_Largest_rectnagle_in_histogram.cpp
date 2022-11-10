#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int>st;
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);  
        vector<int>prev(h.size(),-1);
        vector<int>next(h.size(),h.size());
        st.push(0);
        for(int i=1;i<h.size();i++){
            while(st.size() && h[i]<=h[st.top()]){
                st.pop();
            }
            if(st.size() == 0)prev[i] = -1;

            else prev[i] = st.top();
            st.push(i);
        }
        while(st.size())st.pop();
        st.push(h.size()-1);
        for(int i = h.size()-2;i>=0;i--){
            while(st.size() && h[i]<=h[st.top()]){
                st.pop();
            }
            if(st.size() == 0)next[i] = h.size();

            else next[i] = st.top();
            st.push(i);
        }
        int ans = 0;
        for(int i=0;i<h.size();i++){
            int v = h[i]*(next[i]-prev[i]-1);
            ans = max(ans, v);
        }
        return ans;
    }
};
int main(){
 
    return 0;
}