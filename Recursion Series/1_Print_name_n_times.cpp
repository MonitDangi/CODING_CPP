#include<bits/stdc++.h>
using namespace std;
void recur(int i,int n){
    if(i>n){
        return;
    }
    cout<<"Monit"<<endl;
    recur(i+1,n);
}
int main(){
    int n;
    cin>>n;

    recur(1,n);
    return 0;
}