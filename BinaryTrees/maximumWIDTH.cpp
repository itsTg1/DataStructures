class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        typedef unsigned long long int ll;
        if (!root) return 0;
        
        ll ans = 0;
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            ll l=q.front().second;
            ll r=q.back().second;

            while (size--) {
                auto temp = q.front();
                q.pop();
                TreeNode* node = temp.first;
                ll idx = temp.second;

             

                if (node->left)
                    q.push({node->left, 2 * idx + 1});
                if (node->right)
                    q.push({node->right, 2 * idx + 2});
            }
            ans = max(ans, r-l + 1);
        }
        return ans;
    }
};