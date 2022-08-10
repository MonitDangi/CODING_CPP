//Return All Possible String from int as per their number in alphabetical order

#include<bits/stdc++.h>
using namespace std;
vector<string> codes(string str,vector<string>v,string output){
    if(str.size()==0){
        v.push_back(output);
        return v;
    }
    int x=str[0]-'0';
    char c=x+96;
    vector<string>v1;
    v1=codes(str.substr(1),v1,output+c);
    vector<string>v2;
    if(str.size()>1){
        int y=str[1]-'0';
        char d=y+96;
        int z=10*x+y;
        char c1=z+96;
        if(z>=1&&z<=26){
            v2=codes(str.substr(2),v2,output+c1);
        }
    }
    for(int i=0;i<v1.size();i++){
        string o=v1[i];
        v.push_back(o);
    }
    for(int i=0;i<v2.size();i++){
        string o=v2[i];
        v.push_back(o);
    }
    return v;
}
int main(){
    string str="26";
    vector<string>v;

    v=codes(str,v,"");
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}