#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int s,int mid,int e){
    vector<int> temp(e-s+1);
    int i=s;
    int j=mid+1;
    int idx=0;
    while(i<=mid && j<=e){
        if(arr[i]<arr[j]){
            temp[idx]=arr[i];
            idx++;
            i++;
        }
        else if(arr[j]<arr[i]){
            temp[idx]=arr[j];
            j++;
            idx++;
        }
    }
    while(i<=mid){
        temp[idx]=arr[i];
        i++;
    }
    while(j<=e){
        temp[idx]=arr[j];
        j++;
    }
    int id=s;
    for(auto it:temp){
        arr[id]=it;
        id++;
    }

}
void mergeSort(vector<int> &arr,int s,int e){
    if(s>=e){
        return ;
    }
    int mid=s+(e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);
}
void insertionSort(vector<int> &arr){
    for(int i=1;i<arr.size();i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;  
        }
        arr[j+1]=temp;
    }
}


int main() {
    vector<int> arr={8,1,3,10,6};
    int e=arr.size()-1;
    insertionSort(arr);
    for(auto it:arr){
        cout<<it<<",";
    }

}
