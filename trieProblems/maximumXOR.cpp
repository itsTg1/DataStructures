class trieNode{
    public:
    trieNode* left;
    trieNode* right;
    trieNode(){
        this->right=NULL;
        this->left=NULL;
    }
};

class Solution {
    void insertBits(trieNode* root,int num){
        trieNode* prev=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(bit==1){
                if(prev->right==NULL){
                    prev->right=new trieNode();
                }
                prev=prev->right;
            }
            else{
                if(prev->left==NULL){
                    prev->left=new trieNode();
                }
                prev=prev->left;
            }
        }
    }

    int MaxXor(int num,trieNode* root){
        trieNode* prev=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(bit==1){
                if(prev->left!=NULL){
                    ans+=(1<<i);
                    prev=prev->left;
                }
                else{
                    prev=prev->right;
                }
            }
            else{
                if(prev->right!=NULL){
                    ans+=(1<<i);
                    prev=prev->right;
                }
                else{
                    prev=prev->left;
                }
            }
        }
        return ans;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        trieNode* root=new trieNode();
        for(auto it:nums){
            insertBits(root,it);
        }
        int ans=0;
        for(auto it:nums){
            ans=max(ans,MaxXor(it,root));
        }
        return ans;
    }
};