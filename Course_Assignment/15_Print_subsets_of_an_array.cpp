//Print Subsets of an array

#include<bits/stdc++.h>
using namespace std;

void print_subsets(int arr[],int size,vector<int>v){
    if(size==0){
        for(int i=0;i<v.size();i++){
            cout<<v[i];
        }
        cout<<""<<endl;
        return;
    }
    print_subsets(arr+1,size-1,v);
    v.push_back(arr[0]);
    print_subsets(arr+1,size-1,v);
}

int main(){
    int arr[]={1,2,3};
    vector<int>v;
    print_subsets(arr,3,v);
    return 0;
}