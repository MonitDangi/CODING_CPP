#include<iostream>
#include<vector>
using namespace std;
bool find(long long a, long long b, vector<long long>&val){
    if(a > b)return false;
    if(a==b){
        val.push_back(a);
        return true;
    }
    val.push_back(a);
    if(find(a*10+1,b,val))return true;
    if(find(a*2,b,val))return true;
    val.pop_back();
    return false;
}
int main(){
    long long a,b;
    cin>>a>>b;
    vector<long long>val;
    bool ans = find(a,b,val);
    if(ans){
        cout<<"YES"<<endl;
        cout<<val.size()<<endl;
        for(long long i:val)cout<<i<<" ";
        cout<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}