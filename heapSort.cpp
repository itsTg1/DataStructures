#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[],int i,int size){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<size && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<size && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,largest,size);
    }
    else{
        return ;
    }
}

int main() {
    int arr[]={1,4,24,5,6,3,28};
    int n=sizeof(arr)/sizeof(int);
    //build heap
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,i,n);
    }
    //heap sort 
    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,0,i);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
}
