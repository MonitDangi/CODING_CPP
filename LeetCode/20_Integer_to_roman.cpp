#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        vector<int> roman = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> code ={ "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        string res="";
        for(int i=12;i>=0;i--){
            while(num>=roman[i]){
                res.append(code[i]);
                num-=roman[i];
            }
        }
        return res;
    }
};
int main(){
    return 0;
}