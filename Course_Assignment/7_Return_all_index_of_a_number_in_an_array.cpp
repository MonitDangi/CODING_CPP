//Return All index of a number in array

#include<bits/stdc++.h>
using namespace std;
vector<int> all_index(int arr[],vector<int>v,int size,int num){
    if(size==0){
        return v;
    }
    v=all_index(arr,v,size-1,num);
    if(arr[size-1]==num){
        v.push_back(size-1);
    }
    return v;
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr[i]=a;
    }
    int num;
    cin>>num;
    vector<int>v;
    v=all_index(arr,v,n,num);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    
}