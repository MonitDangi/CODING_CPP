//Return Subsets of an Array

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets(int arr[],int size,vector<vector<int>>v){
    if(size==0){
        vector<int>v1;
        v1.push_back(0);
        v.push_back(v1);
        return v;
    }
    v=subsets(arr+1,size-1,v);
    int n=v.size();
    for(int i=0;i<n;i++){
        vector<int>v1=v[i];
        if(v1[0]==NULL){
            v1[0]=arr[0];
        }
        else{
            v1.insert(v1.begin(),arr[0]);
        }
        
        v.push_back(v1);
    }
    
    return v;
    
}
int main(){
    int arr[]={2,3,2,1};
    vector<vector<int>>v;
    int n=sizeof(arr)/sizeof(arr[0]);
    v=subsets(arr,n,v);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
}