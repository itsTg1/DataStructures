class Solution {
  public:
    void binarysearch(vector<int> &ans,vector<int> &arr){
        for(int i=0;i<arr.size();i++){
            int s=i+1;
            int e=arr.size()-1;
            int result=-1;
            while(s<=e){
                int mid=s+(e-s)/2;
                if(arr[ans[mid]]<arr[i]){
                    result=ans[mid];
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
            ans[i]=result;
        }
    }
    vector<int> findSuffixArr(vector<int> &arr,int n){
        vector<int> ans(n);
        ans[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            if(arr[ans[i+1]]<arr[i]){
                ans[i]=ans[i+1];
            }
            else{
                ans[i]=i;
            }
            
        }
        binarysearch(ans,arr);
        return ans;
        
    }
    
    vector<int> farMin(vector<int>& arr) {
        // code here
        vector<int> minIdx;
        int n=arr.size();
        vector<int> ans=findSuffixArr(arr,n);
        return ans;
        
    }
};


// --------------------------------IF PRINT NUMBER FARTHEST SMALLEST NUM

class Solution {
  public:
    void binarysearch(vector<int> &ans,vector<int> &arr){
        for(int i=0;i<arr.size();i++){
            int s=i+1;
            int e=arr.size()-1;
            int result=-1;
            while(s<=e){
                int mid=s+(e-s)/2;
                if(ans[mid]<arr[i]){
                    result=ans[mid];
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
            ans[i]=result;
        }
    }
    vector<int> findSuffixArr(vector<int> &arr,int n){
        vector<int> ans(n);
        ans[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            ans[i]=min(ans[i+1],arr[i]);
        }
        binarysearch(ans,arr);
        return ans;
        
    }
    
    vector<int> farMin(vector<int>& arr) {
        // code here
        vector<int> minIdx;
        int n=arr.size();
        vector<int> ans=findSuffixArr(arr,n);
        return ans;
        
    }
};