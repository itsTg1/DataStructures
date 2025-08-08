class Solution {
  public:
    static bool lexSort(int a,int b){
        string tem1=to_string(a);
        string tem2=to_string(b);
        return tem1>tem2;
    }
    static bool mycomp(int a,int b){
        string tem1=to_string(a);
        string tem2=to_string(b);
        string temp1=tem1+tem2;
        string temp2=tem2+tem1;
        return temp1>temp2;
    }
    string findLargest(vector<int> &arr) {
        // code here
        string ans="";
        // sort lexicographically
        sort(arr.begin(),arr.end(),lexSort);
        // sort on basis of combination 
        sort(arr.begin(),arr.end(),mycomp);
        for(auto it:arr){
            ans+=to_string(it);
        }
        if(ans[0]=='0'){
            return "0";
        }
        return ans;
    }
};