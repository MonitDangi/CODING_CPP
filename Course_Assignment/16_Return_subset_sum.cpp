// Return target subset sum

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets_sum(int arr[],int size,int target,vector<vector<int>>v){
    if(target==0){
        vector<int>v1;
        v.push_back(v1);
        return v;
    }
    if(size==0||target<0){
        return v;
    }
    vector<vector<int>> v1;
    vector<vector<int>> v2;
    int n=arr[0];
    v1=subsets_sum(arr+1,size-1,target-n,v1);//for Successful
    if(v1.size()!=0){
        for(int i=0;i<v1.size();i++){
            v1[i].insert(v1[i].begin(),n);
        }
    }
    v2=subsets_sum(arr+1,size-1,target,v2);//Unsuccessful
    for(int i=0;i<v1.size();i++){
        v.push_back(v1[i]);
    }
    for(int i=0;i<v2.size();i++){
        v.push_back(v2[i]);
    }
    return v;
}
int main(){
    int arr[]={2,3,2,1};
    vector<vector<int>>v;
    v=subsets_sum(arr,4,3,v);
    for(int i=0;i<v.size();i++){
        int k=v[i].size();
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}