//Quick Sort

#include<iostream>
using namespace std;

int partition(int arr[],int start,int end){
    int pivot=arr[start];
    int count=0;
    for(int i=start+1;i<=end;i++){
        if(arr[i]<pivot){
            count++;
        }
    }
    int temp=arr[start];
    arr[start]=arr[start+count];
    arr[start+count]=temp;
    int y=start,z=end;
    int x=start+count;
    while(y<x&&z>x){
        if(arr[y]>arr[x]&&arr[z]<arr[x]){
            int temp=arr[y];
            arr[y]=arr[z];
            arr[z]=temp;
            y++;
            z--;
        }
        else if(arr[y]<arr[x]&&arr[z]<arr[x]){
            y++;
        }
        else if(arr[y]>arr[x]&&arr[z]>arr[x]){
            z++;
        }
        else if(arr[y]<arr[x]&&arr[z]>arr[x]){
            z--;
            y++;
        }
        
    }
    return x;
}

void quick_sort(int arr[],int start,int end){
    if(end>start){
        int p=partition(arr,start,end);
        quick_sort(arr,start,p-1);
        quick_sort(arr,p+1,end);
    }
    else{
        return;
    }
}
int main(){
    int arr[]={1,9,1,1,6,7,5,3,8,10};
    quick_sort(arr,0,9);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// int t=arr[start];
//         arr[start]=arr[start+p];
//         arr[start+p]=t;
//         int a=start,b=end;
//         while(a<p&&b>p){
//             if(arr[a]>arr[p]&&arr[b]<arr[p]){
//                 int temp=arr[a];
//                 arr[a]=arr[b];
//                 arr[b]=arr[a];
//             }
//             else if(arr[a]<arr[p]&&arr[b]>arr[p]){
//                 a++;
//                 b--;
//             }
//             else if(arr[a]>arr[p]&&arr[b]>arr[p]){
//                 b--;
//             }
//             else{
//                 a--;
//             }
//         }