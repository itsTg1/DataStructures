
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr, int s, int mid, int e) {
    vector<int> temp;

    int left = s;
    int right = mid + 1;

    while(left <= mid && right <= e) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else if(arr[right]<arr[left]) {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= e) {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = s; i <= e; i++) {
        arr[i] = temp[i - s];
    }
}
void mergeSort(vector<int> &arr,int s,int e){
    if(s<e){
        int mid=s+(e-s)/2;
        mergeSort(arr,s,mid);
        mergeSort(arr,mid+1,e);
        merge(arr,s,mid,e);
    }
}
int main(){
    vector<int> arr={73,12,3,13,89,32};
    int s=0;
    int e=arr.size()-1;
    mergeSort(arr,s,e);
    for(auto it:arr){
        cout<<it<<",";
    }
}