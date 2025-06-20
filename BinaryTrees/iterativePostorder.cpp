// NLR


class Solution {
public:
 
  
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* frontNode=st.top();
            st.pop();
            ans.push_back(frontNode->val);
            if(frontNode->left){
                st.push(frontNode->left);
            }
            if(frontNode->right){
                st.push(frontNode->right);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};