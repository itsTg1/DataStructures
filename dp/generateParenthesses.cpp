class Solution {
public:
    void generate(vector<string>& ans, int n,string temp,int openCnt,int closeCnt) {
        if(temp.length()==2*n){
            ans.push_back(temp);
            return ;
        }
        if(openCnt<n){
            temp.push_back('(');
            generate(ans,n,temp,openCnt+1,closeCnt);
            temp.pop_back();
        }
        if(closeCnt<openCnt){
            temp.push_back(')');
            generate(ans,n,temp,openCnt,closeCnt+1);
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        generate(ans, n,temp,0,0);
        return ans;
    }
};