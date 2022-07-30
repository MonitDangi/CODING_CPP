//Print Keypad Approach
#include<bits/stdc++.h>
using namespace std;
void keypad(int n,string output){
    if(n==0){
        cout<<output<<endl;
        return;
    }
    int z=n%10;
    if(z==1||z==0){
        keypad(n/10,output);
    }
    else if(z==2){
        keypad(n/10,output+"a");
        keypad(n/10,output+"b");
        keypad(n/10,output+"c");
    }
    else if(z==3){
        keypad(n/10,output+"d");
        keypad(n/10,output+"e");
        keypad(n/10,output+"f");
    }
    else if(z==4){
        keypad(n/10,output+"g");
        keypad(n/10,output+"h");
        keypad(n/10,output+"i");
    }
    else if(z==5){
        keypad(n/10,output+"j");
        keypad(n/10,output+"k");
        keypad(n/10,output+"l");
    }
    else if(z==2){
        keypad(n/10,output+"m");
        keypad(n/10,output+"n");
        keypad(n/10,output+"o");
    }
    else if(z==7){
        keypad(n/10,output+"p");
        keypad(n/10,output+"q");
        keypad(n/10,output+"r");
        keypad(n/10,output+"s");
    }
    else if(z==8){
        keypad(n/10,output+"t");
        keypad(n/10,output+"u");
        keypad(n/10,output+"v");
    }
    else if(z==9){
        keypad(n/10,output+"w");
        keypad(n/10,output+"x");
        keypad(n/10,output+"y");
        keypad(n/10,output+"z");
    }
    
}

int main(){
    int n;
    string output="";
    cin>>n;
    keypad(n,output);
}