//String to Integer

#include<bits/stdc++.h>
using namespace std;
int from_first_index(string str){
    int s=str.size();
    if(s==0){
        return 0;
    }
    else if(s==1){
        return str[0]-48;
    }
    else{
        return (str[0]-48)*pow(10,str.size()-1)+from_first_index(str.substr(1,str.size()));
    }
    return 0;
}

int main(){
    string str="12";
    int a=from_first_index(str);
    cout<<a;
    return 0;
}