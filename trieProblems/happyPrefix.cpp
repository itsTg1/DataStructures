class trieNode{
    public:
    char data;
    trieNode* children[26];
    bool isTerminal;
    trieNode(char d){
        this->data=d;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        this->isTerminal=false;
    }
};

class Solution {
    void insert(trieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return ;
        }
        trieNode* child;
        char d=word[0];
        if(root->children[d-'a']==NULL){
            child=new trieNode(d);
            root->children[d-'a']=child;
        }
        else{
            child=root->children[d-'a'];
        }
        insert(child,word.substr(1));
    }
    bool search(trieNode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        char d=word[0];
        if(root->children[d-'a']==NULL){
            return false;
        }
        
        trieNode* child=root->children[d-'a'];
        return search(child,word.substr(1));
        
    }
public:
    string longestPrefix(string &s) {
        vector<string> st;
        trieNode* prefix=new trieNode('\0');
        trieNode* suffix=new trieNode('\0');
        st.push_back("");
        for(int i=1;i<=s.length()-1;i++){
            insert(prefix,s.substr(0,i));
        }
        int n=s.length();
        for(int i=1;i<=s.length()-1;i++){
            insert(suffix,s.substr(n-i,i));
        }
        for(int i=1;i<=s.length()-1;i++){
            if(search(suffix,s.substr(0,i)) && search(prefix,s.substr(0,i))){
                st.push_back(s.substr(0,i));
            }
        }
        for(auto it:st){
            cout<<it<<",";
        }
        return st.back();
    }
};