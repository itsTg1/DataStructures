class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        mp[0]=-1;
        int i=0;
        int len=0;
        int prefSum=0;
        while(i<arr.size()){
            prefSum+=arr[i];
            int toFind=(prefSum);
            if(mp.find(toFind)!=mp.end()){
                len=max(len,i-mp[toFind]);
                
            }
            else if(mp.find(toFind)==mp.end()){
                mp[prefSum]=i;
                
            }
            i++;
            
        }
        return len;
    }
};


// ---------------------------------------------------------------


class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int i=0;
        
        int longest=0;
        int prefSum=0;
        
        unordered_map<int,int> mp;
        mp[0]=-1;
        while(i<arr.size()){
            prefSum+=arr[i];
            if(mp.find(prefSum-(k))!=mp.end()){
                longest=max(longest,i-mp[prefSum-(k)]);
            }
            if(mp.find(prefSum)==mp.end()){
                mp[prefSum]=i;
            }
            i++;
        }
        return longest;
    }
};