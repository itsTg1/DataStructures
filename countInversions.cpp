
class Solution {
    public:
      // Function to count inversions in the array.
      int cnt=0;
      void merge(vector<int> &nums,int s,int mid,int e){
          vector<int> temp;
          int l=s;
          int r=mid+1;
          
          while(l<=mid && r<=e){
              if(nums[l]<=nums[r]){
                  temp.push_back(nums[l]);
                  l++;
              }
              else if(nums[l]>nums[r]){
                  cnt+=(mid-l+1);
                  temp.push_back(nums[r]);
                  r++;
              }
          }
          while(l<=mid){
              temp.push_back(nums[l]);
              l++;
          }
          while(r<=e){
              temp.push_back(nums[r]);
              r++;
          }
          int id=0;
          for(int i=s;i<=e;i++){
              nums[i]=temp[id];
              id++;
          }
          
      }
      void mergesort(vector<int> &nums,int s,int e){
          if(s>=e){
              return ;
          }
          int mid=s+(e-s)/2;
          mergesort(nums,s,mid);
          mergesort(nums,mid+1,e);
          merge(nums,s,mid,e);
      }
      int inversionCount(vector<int> &nums) {
          // Your Code Here
          int n=nums.size();
          mergesort(nums,0,n-1);
          return cnt;
      }
  };