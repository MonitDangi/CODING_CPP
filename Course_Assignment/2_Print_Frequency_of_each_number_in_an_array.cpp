//Print Frequency of each number in an array

#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[10]={1,2,3,4,5,1,2,3,3,4};
    int z=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<z;i++){
        int count=1;
        if(arr[i]==arr[0]&&i!=0){
                continue;
            }
        for(int j=i+1;j<z;j++){
            if(arr[i]==arr[j]){
                count++;
                arr[j]=arr[0];
            }
        }
        cout<<arr[i]<<" : "<<count<<endl;
    }


    unordered_map<int,int>mp;
    for(int i=0;i<z;i++)
    {
        mp[arr[i]]++;   
    }
    for(auto x:mp)
        cout<<x.first<<" "<<x.second<<endl;
    return 0;
}