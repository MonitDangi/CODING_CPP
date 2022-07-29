//Return Keypad Approach

#include<bits/stdc++.h>
using namespace std;
int func(int n,string *p){
    if(n==0){
        p[0]=="";
        return 1;
    }
    int size=func(n/10,p);
    int rem=n%10;
    if(rem==0||rem==1){
        return size;
    }
    else if(rem==2){
        for(int i=1;i<4;i++){
            for(int j=0;j<size;j++){
                if(i==3){
                    p[j]=p[j]+"a";
                }
                else if(i==1){
                    p[size*i+j]=p[j]+"b";
                }
                else if(i==2){
                    p[size*i+j]=p[j]+"c";
                }
            }
        }
    }
    else if(rem==3){
        for(int i=1;i<4;i++){
            for(int j=0;j<size;j++){
                if(i==3){
                    p[j]=p[j]+"d";
                }
                else if(i==1){
                    p[size*i+j]=p[j]+"e";
                }
                else if(i==2){
                    p[size*i+j]=p[j]+"f";
                }
            }
        }
    }
    else if(rem==4){
        for(int i=1;i<4;i++){
            for(int j=0;j<size;j++){
                if(i==3){
                    p[j]=p[j]+"g";
                }
                else if(i==1){
                    p[size*i+j]=p[j]+"h";
                }
                else if(i==2){
                    p[size*i+j]=p[j]+"i";
                }
            }
        }
    }
    else if(rem==5){
        for(int i=1;i<4;i++){
            for(int j=0;j<size;j++){
                if(i==3){
                    p[j]=p[j]+"j";
                }
                else if(i==1){
                    p[size*i+j]=p[j]+"k";
                }
                else if(i==2){
                    p[size*i+j]=p[j]+"l";
                }
            }
        }
    }
    else if(rem==6){
        for(int i=1;i<4;i++){
            for(int j=0;j<size;j++){
                if(i==3){
                    p[j]=p[j]+"m";
                }
                else if(i==1){
                    p[size*i+j]=p[j]+"n";
                }
                else if(i==2){
                    p[size*i+j]=p[j]+"o";
                }
            }
        }
    }
    else if(rem==7){
        for(int i=1;i<=4;i++){
            for(int j=0;j<size;j++){
                if(i==4){
                    p[j]=p[j]+"p";
                }
                else if(i==1){
                    p[size*i+j]=p[j]+"q";
                }
                else if(i==2){
                    p[size*i+j]=p[j]+"r";
                }
                else if(i==3){
                    p[size*i+j]=p[j]+"s";
                }
            }
        }
    }
    else if(rem==8){
        for(int i=1;i<4;i++){
            for(int j=0;j<size;j++){
                if(i==3){
                    p[j]=p[j]+"t";
                }
                else if(i==1){
                    p[size*i+j]=p[j]+"u";
                }
                else if(i==2){
                    p[size*i+j]=p[j]+"v";
                }
            }
        }
    }
    else if(rem==9){
        for(int i=1;i<=4;i++){
            for(int j=0;j<size;j++){
                if(i==4){
                    p[j]=p[j]+"w";
                }
                else if(i==1){
                    p[size*i+j]=p[j]+"x";
                }
                else if(i==2){
                    p[size*i+j]=p[j]+"y";
                }
                else if(i==3){
                    p[size*i+j]=p[j]+"z";
                }
            }
        }
    }
    if(rem==7||rem==9){
        return (size)*(3+1);
    }
    return size*3;

}

int main(){
    int number=23;
    string * str=new string[100];

    int n=func(number,str);

    for(int i=0;i<n;i++){
        cout<<str[i]<<endl;
    }
}