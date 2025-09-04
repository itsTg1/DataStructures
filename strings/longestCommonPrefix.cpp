// User function template for C++
class Solution {
  public:
    static bool mycomp(string a,string b){
        return a.length()<b.length();
    }
    string longestCommonPrefix(vector<string> arr) {
        // your code here
        sort(arr.begin(),arr.end(),mycomp);
        string toFind=arr[0];
        while(toFind.length()>0){
            bool ans=true;
            for(int i=1;i<arr.size();i++){
                if(arr[i].find(toFind)!=0){
                    ans=false;
                    break;
                }
            }
            if(ans==false){
                toFind=toFind.substr(0,toFind.length()-1);
            }
            else{
                return toFind;
            }
        }
        return "";
        
    }
};