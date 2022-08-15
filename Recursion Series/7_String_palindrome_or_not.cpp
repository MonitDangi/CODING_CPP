#include<bits/stdc++.h>
using namespace std;

bool palindrome(string s, int left,int right){
    if(left>=right)return true;
    if(s[left]!=s[right])return false;
    return palindrome(s,left+1,right-1);
}
int main(){
    string s;
    cin>>s;
    if(palindrome(s,0,s.size()-1))cout<<"Yes";
    else cout<<"No"<<endl;
    return 0;
}