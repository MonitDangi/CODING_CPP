//Merge Sort 


#include<iostream>
using namespace std;
void sort(int arr[],int start,int end){
    int mid=(end+start)/2;
    int n1=mid-start+1;
    int n2=end-mid;
    int *arr1=new int[n1];
    int *arr2=new int[n2];
    for(int i=0;i<n1;i++){
        arr1[i]=arr[i+start];
    }
    for(int i=0;i<n2;i++){
        arr2[i]=arr[mid+i+1];
    }
    int x=0,y=0,z=start;
    while(x<n1&&y<n2){
        if(arr1[x]<arr2[y]){
            arr[z++]=arr1[x++];
        }
        else{
            arr[z++]=arr2[y++];
        }
    }
    while(x<n1){
        arr[z++]=arr1[x++];
    }
    while(y<n2){
        arr[z++]=arr2[y++];
    }

}

void merge_sort(int arr[],int start,int n){
    if(n>start){
        int a=(start+n)/2;
        merge_sort(arr,start,a);
        merge_sort(arr,a+1,n);
        sort(arr,start,n);
    }
    return;
}
int main(){
    int arr[]={9,1,8,2,4,5,3,5,10,6};
    merge_sort(arr,0,9);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}