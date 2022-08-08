//Print target subset sum

#include<bits/stdc++.h>
using namespace std;
void print_subsets(int arr[],int size,int target,vector<int>v){
    if(target==0){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    else if(size==0){
        return;
    }
    print_subsets(arr+1,size-1,target,v);
    v.push_back(arr[0]);
    print_subsets(arr+1,size-1,target-arr[0],v);
    return;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    vector<int>v;
    print_subsets(arr,9,9,v);
    return 0;
}