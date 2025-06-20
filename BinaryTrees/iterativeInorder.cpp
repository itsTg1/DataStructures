vector<int> inOrder(Node* root) {
        // code here
        // visited
        map<Node*,bool> mp;
        vector<int> ans;
        stack<Node*> st;
        st.push(root);
        mp[root]=0;
        while(!st.empty()){
            Node* frontNode=st.top();
            st.pop();
            if(mp[frontNode]==1){
                ans.push_back(frontNode->data);
            }
            if(frontNode->right && mp.find(frontNode->right)==mp.end()){
                mp[frontNode->right]=0;
                st.push(frontNode->right);
            }
            if(mp[frontNode]==0){
                mp[frontNode]=1;
                st.push(frontNode);
            }
            if(frontNode->left && mp.find(frontNode->left)==mp.end()){
                mp[frontNode->left]=0;
                st.push(frontNode->left);
            }
        }
        return ans;
    }