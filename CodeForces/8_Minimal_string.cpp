#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int ind = 0;
    vector<int>arr(26,0);
    for(char c:s)arr[c-'a']++;
    stack<char>st;
    string ans;
    for(int i = 0; i<s.size(); i++){
        int ind = 25;
        for(int i = 0; i < 26; i++){
            if(arr[i]>0){
                ind = i;
                break;
            }
        }
        if(ind == s[i]-'a')ans.push_back(s[i]);
        else {
            st.push(s[i]);
        }
        arr[s[i]-'a']--;
    }
    while(st.size())ans.push_back(st.top()), st.pop();
    cout<<ans<<endl;
    return 0;
}