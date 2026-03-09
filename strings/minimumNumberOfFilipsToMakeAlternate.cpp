class Solution {
public:
    int minFlips(string s) {
        string temp=s+s;
    
        string temp1=temp;
        string temp2=temp;
     
        for(int i=0;i<temp.length();i++){
            if(i%2==0){
                temp1[i]='0';
                temp2[i]='1';
            }
            else{
                temp1[i]='1';
                temp2[i]='0';
            }
        }
  
        int i=0;
        int j=0;
        int cnt1=0;
        int cnt2=0;
        int ans=INT_MAX;
        while(j<temp.length()){
            if(temp[j]!=temp1[j]){
                cnt1++;
            }
            if(temp[j]!=temp2[j]){
                cnt2++;
            }
            while((j-i+1)==s.length()){
                ans=min({ans,cnt1,cnt2});
                if(temp[i]!=temp1[i]){
                    cnt1--;
                }
                if(temp[i]!=temp2[i]){
                    cnt2--;
                }
                i++;
            }
   
                
            
            j++;
        }
        return ans;
    }
};