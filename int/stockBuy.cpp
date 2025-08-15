// https://www.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1

class Solution {
  public:
    int stockBuySell(vector<int> &arr) {
        // code here
        int profit=0;
        for(int i=1;i<arr.size();i++){
           if(arr[i]>arr[i-1]){
               profit+=(arr[i]-arr[i-1]);
           }
        }
        
        return profit;
    }
};

// approach -2

// leetcode- 121

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minim=prices[0];
        int ans=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minim){
                minim=prices[i];
                continue;
            }
            else{
                int curr=prices[i]-minim;
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};