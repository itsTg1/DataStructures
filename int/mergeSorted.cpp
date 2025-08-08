// -----------------------------------------------------
// two pointer approach


class Solution {
public:
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=0;
        while(i>=0 && j<n){
            if(nums1[i]>=nums2[j]){
                swap(nums1[i],nums2[j]);
                i--;
                j++;
            }
            else{
                break;
            }
        }
        
        sort(nums1.begin(),nums1.begin()+m);
        sort(nums2.begin(),nums2.end());
        int k=m;
        for(int i=0;i<nums2.size();i++){
            nums1[k]=(nums2[i]);
            k++;
        }
    }
};




// shell sort or gap algo.

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n=a.size()+b.size();
        int a1=a.size();
        
        int gap=(n/2)+(n%2);
        while(gap>0){
        int left=0;
        int right=left+gap;
        while(right<n){
            if(left>=a1){
                if(b[left-a1]>b[right-a1]){
                    swap(b[left-a1],b[right-a1]);
                }
            }
            else if(left<a1 && right>=a1){
                if(a[left]>b[right-a1]){
                    swap(a[left],b[right-a1]);
                }
            }
            else if(right<a1){
                if(a[left]>a[right]){
                    swap(a[left],a[right]);
                }
            }
            left++;
            right++;
        }
        if(gap==1){
            break;
        }
        gap=(gap/2)+(gap%2);
        }
      
    }
};




// approach - 3

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int i=a.size()-1;
        int j=0;
        while(i>=0 && j<b.size()){
            if(a[i]==b[j]){
                i--;
                j++;
            }
            else if(a[i]<b[j]){
                j++;
            }
            else if(a[i]>b[j]){
                swap(a[i],b[j]);
                i--;
                j++;
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
    }
};