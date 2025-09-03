class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()){
            return false;
        }
        map<char,int> mp1;
        map<char,int> mp2;
        for(int i=0;i<word1.length();i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }
        for(auto it:mp1){
            char ch=it.first;
            if(mp1[ch]==mp2[ch]){
                mp1.erase(ch);
                mp2.erase(ch);
            }
            else if(mp2.find(ch)==mp2.end()){
                return false;
            }
        }
        int cnt1=0;
        int cnt2=0;
        vector<char> ch1;
        vector<char> ch2;
        vector<int> freq1;
        vector<int> freq2;
        for(auto it:mp1){
            cnt1+=it.second;
            ch1.push_back(it.first);
            freq1.push_back(it.second);
        }
        for(auto it:mp2){
            cnt2+=it.second;
            ch2.push_back(it.first);
            freq2.push_back(it.second);
        }
        if(cnt1!=cnt2){
            return false;
        }
        if(ch1!=ch2){
            return false;
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        if(freq1!=freq2){
            return false;
        }
        return true;
    }
};