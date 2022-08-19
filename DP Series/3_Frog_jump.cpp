#include<bits/stdc++.h>
using namespace std;
int frogJump(int n, vector<int> &heights)
{
    if(n==1){
            return 0;
        }
        else if(n==2){
            return abs(heights[1]-heights[0]);
        }
    int p1=0;
    int p2=abs(heights[1]-heights[0]);
    for(int i=1;i<=n;i++){
        int n1=p1+abs(heights[i]-heights[i-1]);
        int n2=p2+abs(heights[i]-heights[i-2]);
        p2=p1;
        p1=min(n1,n2);
    }
    return p2;
}
int main(){
    int n;
    cin>>n;
    vector<int>heights(n);

    for(int i=0; i<n; i++)cin>>heights[i];
    cout<<frogJump(n,heights);
    return 0;
}