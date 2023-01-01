#include<bits/stdc++.h>
using namespace std;
class Solution {
    int factorSum(int n){
        int num = 2;
        int ans = 0;
        while(n>1){
            if(n%num==0){
                ans+=num;
                n/=num;
            }
            else num++;
        }
        return ans;
    }
public:
    int smallestValue(int n) {
        while(true){
            int x = factorSum(n);
            if(x ==n )return x;
            n = x;
        }
        return 1;
    }
};
int main(){
}