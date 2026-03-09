class Solution {
public:
    int minOperations(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=i;
            }
            
        }
        int ans=0;
        string temp=s;
        sort(temp.begin(),temp.end());
      
        int i=0;
        while(i<s.length()){
            if(s[i]==temp[i]){
                i++;
            }
            else{
                if(i==0 && mp[temp[i]]!=s.length()-1){
                    int len=s.length()-1;
                    string temp1=s.substr(0,len);
                    sort(temp1.begin(),temp1.end());
                    s=temp1+s[len];
                    i++;
                }
                else if(i==0 && mp[temp[i]]==(s.length()-1)){
                    
                    char temp1=s[0];
                    string temp2=s.substr(1);
                    sort(temp2.begin(),temp2.end());
                    s=temp1+temp2;
                    
                    mp[temp[i]]=1;
                    if(mp[temp[i]]==s.length()-1){
                        return -1;
                    }
                }
                else{
                    string temp1=s.substr(i);
            
                    sort(temp1.begin(),temp1.end());
                    string temp2=s.substr(0,i);
            
                    s=temp2+temp1;
                    i++;
                }
                ans++;
               
            }
        }
        
        if(s!=temp){
            return -1;
        }
        return ans;
    }
};

// leetcode 3863