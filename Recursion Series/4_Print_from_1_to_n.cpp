#include<bits/stdc++.h>
using namespace std;
void recur(int i,int n){
    if(i<1){
        return;
    }
    recur(i-1,n);
    cout<<i<<" ";
}
int main(){
    return 0;
}