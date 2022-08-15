#include<bits/stdc++.h>
using namespace std;
void recur(int n){
    if(n<1){
        return;
    }
    cout<<n<<" ";
    recur(n-1);
}
int main(){
    int n;
    cin>>n;
    recur(n);
    return 0;
}