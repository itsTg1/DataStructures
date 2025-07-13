class Solution {
  public:
    bool checkAllCows(vector<int> &stalls,int k , int mid){
        int totalCows=1;
        int firstPos=stalls[0];
        for(int i=0;i<stalls.size();i++){
            if((stalls[i]-firstPos)>=mid){
                totalCows++;
                firstPos=stalls[i];
            }
            if(totalCows==k){
                return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        int ans=-1;
        sort(stalls.begin(),stalls.end());
        int s=0;
        int minPos=stalls[0];
        int maxPos=stalls[stalls.size()-1];
        int e=maxPos-minPos;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(checkAllCows(stalls,k,mid)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};