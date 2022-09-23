#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int concatenatedBinary(int n) { 
        long long ans =0, length =0 , mod =1e9+7;
        for(int i=1;i<=n;i++){
            if((i&i-1)==0){
                length++;
                cout<<i<<endl;
            }
            ans  = ((ans << length)+i)%mod;
        }
        return ans;
    }
};
int main(){
    return 0;
}