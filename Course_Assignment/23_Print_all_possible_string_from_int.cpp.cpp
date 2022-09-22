//Print All Possible String from int as per their number in alphabetical order

#include<bits/stdc++.h>
using namespace std;
void print_codes(string str,string output){
    if(str.size()==0){
        cout<<output<<endl;
        return;
    }
    int x=str[0]-'0';
    char c1=x+96;
    print_codes(str.substr(1),output+c1);
    if(str.size()>1){
        int y=str[1]-'0';
        if(x+y>=1&&x+y<=26){
            char c2=10*x+y+96;
            print_codes(str.substr(2),output+c2);
        }
    }
    return;
}
int main(){
    string str="26";
    print_codes(str,"");
    return 0;
}