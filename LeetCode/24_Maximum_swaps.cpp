#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumSwap(int num) {
        vector<int>v;

        while(num>0){
            v.push_back(num%10);
            num /= 10;
        }
        vector<int>sw(v.size(),-1);
        for(int i = v.size()-1;i>0;i--){
            int ind = i;
            bool b = false;
            for(int j = i-1; j >=0; j--){
                if(v[ind] < v[j] ){
                    ind = j;
                    sw[i] =  j;
                    b = true; 
                }
                else if(v[ind] == v[j] && b){
                    ind = j;
                    sw[i] =  j;
                }
            }
        }
        for(int i=v.size()-1;i>=0;i--)cout<<v[i]<<" ";
        for(int i = v.size()-1;i>=0;i--){
            if(sw[i]!=-1){
                swap(v[i],v[sw[i]]);
                break;
            }
        }
        for(int j = v.size()-1;j>=0;j--){
            num = num *10 + v[j];
        }
        return num;
    }
};
int main(){
    return 0;
}