class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char d) {
            this->data = d;
            for(int i=0; i<26 ; i++) {
                    children[i] = NULL;
            }
            childCount = 0;
            this->isTerminal = false;
    }
};
class Solution {
void insertWord(TrieNode* root, string word) {
        //cout << "Inserting " << word << endl;
//base case
        if(word.length() == 0) {
                root->isTerminal = true;
                return;
        }
        
        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;
        //present
        if(root->children[index] != NULL) {
                child = root->children[index];
        }
        else {
                //not present
                child = new TrieNode(ch);
                root->childCount++;
                root->children[index] = child;
        }

        //recursion sambhal lega
        insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
                return root->isTerminal;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;

        //present
        if(root->children[index] != NULL) {
                child = root->children[index];
        }
        else{
                return false;
        }
        //rec call
        return searchWord(child, word.substr(1));

} 
void findLCP(TrieNode* root, string &ans) {
        if(root->isTerminal){
            return ;
        }
        if(root->childCount==1){
            for(int i=0;i<25;i++){
                if(root->children[i]){
                    ans+=root->children[i]->data;
                    findLCP(root->children[i],ans);
                }
            }
        }

}
public:
string longestCommonPrefix(vector<string>& strs) {
    string ans="";
    TrieNode* root = new TrieNode('-');
    //insert strings
    for(int i=0; i<strs.size(); i++) {
        insertWord(root, strs[i]);
    }
    findLCP(root,ans);
    return ans;
}
};