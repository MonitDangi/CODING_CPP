#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
int main(){
    int n,d;
    cin>>n>>d;
    vector<vector<int>>arr;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end());
    deque<int>dq;
    long long ans = 0;
    long long sum = 0;
    for(int i = 0; i < n;i++){
        dq.push_back(i);
        sum += arr[i][1];
        while(arr[i][0] - arr[dq.front()][0] >= d){
            sum -= arr[dq.front()][1];
            dq.pop_front();
        }
        ans = max(ans,sum);
    }
    cout<<ans;
    return 0;
}