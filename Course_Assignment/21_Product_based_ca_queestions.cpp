#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<bool>prime(3572,true);
    for(int i=2;i<=3572;i++){
        if(prime[i]){
            int mul=2;
            while(i*mul<=3572){
                prime[i*mul]=false;
                mul++;
            }
        }
    }
    vector<int>nums;
    for(int i=2;i<=3572;i++){
        if(prime[i])nums.push_back(i);
    }
    for(int i=0;i<n;i++){
        cout<<nums[v[i]-1]*nums[v[i]-1]+1<<endl;
    }
    return 0;
}