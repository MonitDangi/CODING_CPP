//Number of Ways for Stairs Climbing

#include<iostream>
using namespace std;
int max_ways(int n){
    if(n<0){
        return 0;
    }
    if(n==1||n==0){
        return 1;
    }
    return max_ways(n-1)+max_ways(n-2)+max_ways(n-3);
}

int main(){
    int n;
    cin>>n;
    n=max_ways(n);
    cout<<n;
}