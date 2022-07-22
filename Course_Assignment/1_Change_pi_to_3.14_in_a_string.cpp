//Change pi to 3.14 in a String


#include<bits/stdc++.h>
using namespace std;
string check(string a){
    int size=a.size();
    if(size==0||size==1){
        return a;
    }
    else if(a[0]=='p'&&a[1]=='i'){
        return "3.14"+check(a.substr(2,size));
    }
    else{
        return a.substr(0,1)+check(a.substr(1,size));
    }
}
int main(){
    string a;
    cin>>a;
    a=check(a);
    cout<<a;
}