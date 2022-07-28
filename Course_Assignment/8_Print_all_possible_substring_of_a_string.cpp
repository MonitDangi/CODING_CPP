///Print Substring of a String

#include<bits/stdc++.h>
using namespace std;
void substring(string str,string output){
    if(str.size() == 0){
        cout<<output<<endl;
        return;
    }
    substring(str.substr(1),output);
    substring(str.substr(1),output+str[0]);
    return;
}

int main(){
    string str;
    string output="";
    cin>>str;
    substring(str,output);
    cout<<"\nCompleted";
}