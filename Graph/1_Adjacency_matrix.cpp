#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int arr[n+1][n+1];
    // Graph
    for(int i =0; i < m; i++){
        int i1,i2;
        cin>>i1>>i2;
        arr[i1][i2] = 1;
        arr[i2][i1] = 1;
    }
    return 0;
}