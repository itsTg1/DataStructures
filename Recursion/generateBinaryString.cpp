// User function Template for C++

class Solution {
  public:
    void generateBinary(int num,string &temp,int idx,set<string> &ans){
        if(idx>=num){
            
            ans.insert(temp);
            return ;
        }
        if(idx==0){
            temp.push_back('0');
            generateBinary(num,temp,idx+1,ans);
            temp.pop_back();
            temp.push_back('1');
            generateBinary(num,temp,idx+1,ans);
            temp.pop_back();
        }
        if(temp.back()=='1'){
            temp.push_back('0');
            generateBinary(num,temp,idx+1,ans);
            temp.pop_back();
        }
        else{
            temp.push_back('1');
            generateBinary(num,temp,idx+1,ans);
            temp.pop_back();
            temp.push_back('0');
            generateBinary(num,temp,idx+1,ans);
            temp.pop_back();
        }
    }
    vector<string> generateBinaryStrings(int num) {
        // Write your code
        set<string> ans;
        string temp="";
        generateBinary(num,temp,0,ans);
        vector<string> result;
        for(auto it:ans){
            result.push_back(it);
        }
        return result;
    }
};