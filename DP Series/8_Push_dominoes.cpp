#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<int> right(dominoes.size(),0),left(dominoes.size(),0);
        int prev = 0, val = 0; 
        for(int i=0;i<dominoes.size();i++){
            if(dominoes[i]=='R'){
                prev=1;
                val = 1;
            }
            else if(dominoes[i] == 'L'){
                prev= 0;
                val =0;
            }
            else if(dominoes[i] == '.' && val > 0){
                right[i]=val;
                val++;
            }
        }
        for(int i=dominoes.size()-1;i>=0;i--){
            if(dominoes[i]=='R'){
                prev=0;
                val = 0;
            }
            else if(dominoes[i] == 'L'){
                prev= 1;
                val =1;
            }
            else if(dominoes[i] == '.' && val > 0){
                left[i]=val;
                val++;
            }
        }
        for(int i=0;i<dominoes.size();i++){
            if(left[i]==0&&right[i]==0)continue;
            else if(left[i]>0&&right[i]==0)dominoes[i]='L';
            else if(left[i]==0&&right[i]>0)dominoes[i]='R';
            else if(left[i]<right[i])dominoes[i]='L';
            else if(right[i]<left[i])dominoes[i]='R';
        }
        return dominoes;
    }
};
int main(){
    return 0;
}