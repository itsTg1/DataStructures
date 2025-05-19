class Solution {
public:
    vector<string> ans;
    void findSubsequence(vector<string>& words, vector<int>& groups,int curr,int prev,int len,vector<string> &temp){
        if(curr>=len){
            if(ans.size()<temp.size()){
                ans=temp;
            }
            return ;
        }
        if(prev==-1 || groups[curr]!=groups[prev]){
            temp.push_back(words[curr]);
            findSubsequence(words,groups,curr+1,curr,len,temp);
            temp.pop_back();
        }
        else{
            findSubsequence(words,groups,curr+1,prev,len,temp);
        }
    }
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<string> temp;
        findSubsequence(words,groups,0,-1,n,temp);
        return ans;
    }
};









// ---------------------------------------------------------------------------


class Solution {
public:
    vector<string> ans;
    bool checkhammingDistanceOne(string& s1, string& s2) {
        int diff = 0;

        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diff++;
            }

            if (diff > 1) {
                return false; // early exit
            }
        }

        return diff == 1;
    }
    void findSubsequence(vector<string>& words, vector<int>& groups, int curr,
                         int prev, int len, vector<string>& temp) {
        if (curr >= len) {
            if (ans.size() < temp.size()) {
                ans = temp;
            }
            return;
        }

        
        if (prev == -1 || (groups[curr] != groups[prev] && words[prev].length()==words[curr].length() &&
                           checkhammingDistanceOne(words[prev], words[curr]))) {
            temp.push_back(words[curr]);
            findSubsequence(words, groups, curr + 1, curr, len, temp);
            temp.pop_back();
        }

      
        findSubsequence(words, groups, curr + 1, prev, len, temp);
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        int n = words.size();
        vector<string> temp;
        findSubsequence(words, groups, 0, -1, n, temp);
        return ans;
    }
};