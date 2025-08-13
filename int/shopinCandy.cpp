class Solution {
  public:
    static bool mycomp(int a,int b){
        return a>b;
    }
    void findMaxCandy(vector<int> &ans,vector<int> prices,int k,int n){
        sort(prices.begin(),prices.end(),mycomp);
        int cnt=0;
        int cost=0;
        for(int i=0;i<prices.size();i++){
            cost+=prices[i];
            cnt++;
            if(cnt>=n){
                break;
            }
            else if(cnt+k==n){
                break;
            }
            else if(cnt+k>n){
                break;
            }
            cnt=cnt+k;
        }
        ans.push_back(cost);
    }
    void findMinCandy(vector<int> &ans,vector<int> &prices,int k,int n){
        sort(prices.begin(),prices.end());
        int cnt=0;
        int cost=0;
        for(int i=0;i<prices.size();i++){
            cost+=prices[i];
            cnt++;
            if(cnt>=n){
                break;
            }
            else if(cnt+k==n){
                break;
            }
            else if(cnt+k>n){
                break;
            }
            cnt=cnt+k;
        }
        ans.push_back(cost);
    }
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        vector<int> ans;
        int n=prices.size();
        findMinCandy(ans,prices,k,n);
        findMaxCandy(ans,prices,k,n);
        return ans;
        
    }
};