#include<bits/stdc++.h>
using namespace std;
long long int houseRobber(vector<int>& v1)
{
    if(v1.size()==1){
        return v1[0];
    }
    else if(v1.size()==1){
        return max(v1[0],v1[1]);
    }
    int n=v1.size();
    vector<long long> h1;
    vector<long long> h2;
    for(int i=0;i<n;i++){
        h1.push_back(v1[i]);
        h2.push_back(v1[i]);
    }
    h1[1]=max(h1[0],h1[1]);
    h2[0]=0;
    for(int i=2;i<n;i++){
        h1[i] =max(h1[i]+h1[i-2],h1[i-1]);
        h2[i] =max(h2[i]+h2[i-2],h2[i-1]);
    }
    return max(h1[n-2],h2[n-1]);
}
int main(){
    int n;
    cin>>n;
    vector<int>house(n);
    for(int i=0;i<n;i++)cin>>house[i];
    cout<<houseRobber(house);
    return 0;
}