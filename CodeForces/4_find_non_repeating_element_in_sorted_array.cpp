#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i = 0; i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    int low = 0, high = n-1;
    while(low<=high){
        if(low ==  high){
            cout<<v[low]<<endl;
            break;
        }
        int mid = low + (high-low)/2;
        if(mid % 2){
            if(v[mid]!=v[mid-1]){
                high = mid;
            }
            else low = mid+1;
        }
        else{
            if(v[mid]!=v[mid+1]){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
    }
}