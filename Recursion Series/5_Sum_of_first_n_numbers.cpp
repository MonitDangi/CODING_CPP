#include<bits/stdc++.h>
using namespace std;
void recur(int n,int &sum){
    if(n<1){
        return;
    }
    sum+=n;
    recur(n-1,sum);
}
int main(){
    int n;
    cin>>n;
    int sum=0;
    recur(n,sum);
    cout<<sum<<endl;
    return 0;
}