//Binary Search
#include<bits/stdc++.h>
using namespace std;
int search(int arr[],int start,int end,int target){
    if(start==end&&arr[start]!=target){
        return -1;
    }
    int n=(start+end)/2;
    if(arr[n]==target){
        return n;
    }
    else if(arr[n]>target){
        return search(arr,start,n-1,target);
    }
    return search(arr,n+1,end,target);
}
int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int n;
    cin>>n;
    int x=search(arr,0,9,n);
    cout<<x;
}