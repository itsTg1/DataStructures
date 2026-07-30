class Solution {
public:
    int findGcd(int a,int b){
        while(a!=0 && b!=0){
            if(a>b){
                a=a%b;
            }
            else{
                b=b%a;
            }
        }
        if(a==0){
            return b;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        long long sum=0;
        vector<int> prefixGcd;
        int max_ele=nums[0];
        prefixGcd.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            max_ele=max(max_ele,nums[i]);
            if(max_ele==nums[i]){
                prefixGcd.push_back(nums[i]);
            }
            else{
                int temp=findGcd(max_ele,nums[i]);
                prefixGcd.push_back(temp);
            }
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        
        int n=prefixGcd.size();
        for(int j=0;j<prefixGcd.size()/2;j++){
            if(j!=(n-j-1)){
                
                sum+=findGcd(prefixGcd[j],prefixGcd[n-j-1]);
            }
        }
        return sum;
    }
};