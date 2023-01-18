#include<bits/stdc++.h>
using namespace std;
vector<int> func(vector<int>&arr){
    vector<int>left(arr.size(),-1);
    vector<int>right(arr.size(), arr.size());
    stack<int>st;
    for(int i = 0; i < arr.size(); i++){
        while(st.size() && arr[st.top()] >= arr[i])st.pop();
        if(st.size() == 0)left[i] = -1;
        else left[i] = st.top();
        st.push(i);
    }
    while(st.size())st.pop();
    for(int i = arr.size()-1; i >= 0; i--){
        while(st.size() && arr[st.top()] >= arr[i])st.pop();
        if(st.size() == 0)right[i] = arr.size();
        else right[i] = st.top();
        st.push(i);
    }
    vector<int>ans(arr.size(),-1);
    int val = -1;
    for(int i = 0; i < arr.size(); i++){
        int ind = right[i]-left[i]-2;
        ans[ind] = max(ans[ind],arr[i]);
    }
    for(int i =  arr.size()-1; i >=0;i--){
        if(ans[i] == -1)ans[i] = val;
        else val = ans[i];
        if(i < ans.size()-1)ans[i]= max(ans[i], ans[i+1]);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    vector<int>ans = func(arr);
    for(int i : ans)cout<<i<<" ";
    return 0;
}