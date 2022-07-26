//Return substring of a String

#include<bits/stdc++.h>
using namespace std;
int subs(string str,string *str2){
    if(str.size()==0){
        str2[0]="";
        return 1;
    }
    int n=subs(str.substr(1,str.size()),str2);
    for(int i=0;i<n;i++){
        str2[i+n]=str[0]+str2[i];
        }
    return 2*n;
}

int main(){
    string str="abc";
    string * str2=new string[100];
    int x=subs(str,str2);
    for(int i=0;i<x;i++){
        cout<<str2[i]<<endl;
    }
}