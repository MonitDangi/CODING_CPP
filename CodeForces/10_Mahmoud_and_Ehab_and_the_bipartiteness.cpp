#include<bits/stdc++.h>
#define int long long
using namespace std;
void isBipartite(vector<int>&color, vector<int>adj[], int i){
    int c;
    if(color[i] == -1){
        color[i] = 1;
        c = 1;
    }
    else c = color[i];
    for(auto x:adj[i]){
        if(color[x] == -1){
            color[x] = 1 - c;
            isBipartite(color, adj,x);
        }
    }
}
int32_t main(){
    int n;
    cin>>n;
    vector<int>adj[n];
    for(int i=1;i < n; i++){
        int a, b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    vector<int>color(n,-1);
    isBipartite(color,adj,0);
    vector<int>color1;
    for(int i = 0; i < n; i++){
        if(color[i])color1.push_back(i);
    }
    int s = n - color1.size();
    int ans = 0;
    for(auto it: color1){
        int cnt = 0;
        for(auto x: adj[it]){
            if(color[x] == 0)cnt++;
        }
        ans += (s-cnt);
    }
    cout<<ans<<endl;
    return 0;
}