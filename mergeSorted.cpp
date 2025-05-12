// -----------------------------------------------------

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