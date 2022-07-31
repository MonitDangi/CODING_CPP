//Check AB


#include<bits/stdc++.h>
using namespace std;
bool checkAB(string str,int end){
    if(str[0]!='a'){
        return false;
    }
    if(end<=0){
        return true;
    }
    if(str.size()-1==end){
        if(str[end]=='a'){
            return checkAB(str,end-1);
        }
        else if(str[end]=='b'){
            if(str[end-1]=='b'){
                return checkAB(str,end-2);
            }
        }
    }
    else if(str.size()>end&&end>=2){
        if(str[end]=='b'){
            if(str[end-1]!='b'||str[end-2]!='a'){
                return false;
            }
            else {
                return checkAB(str,end-3);
            }
        }
        return false;
    }
}
int main(){
    string str="ababa";
    bool b=checkAB(str,str.size()-1);
    if(b){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}