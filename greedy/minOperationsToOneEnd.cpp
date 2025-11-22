class Solution {
public:
    int maxOperations(string s) {
       int ans=0;
       int last1=s.length();
       for(int i=s.length()-2;i>=0;i--){
        if(s[i+1]=='1'){
            last1=i+1;
        }
        else if(s[i]=='0' && s[i+1]=='0'){
            continue;
        }
        else if(s[i]=='1' && s[i+1]=='0'){
            
            s=s.substr(0,i)+s.substr(i+1,last1-i-1)+'1'+s.substr(last1);
            last1=last1-1;
            cout<<s<<endl;
        }
       }
       return ans;
    }
};