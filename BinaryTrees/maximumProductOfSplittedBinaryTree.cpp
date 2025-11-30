
class Solution {
public:
    set<pair<long long,long long>> temp;
    const long long mod = 1e9 + 7;
    long long totalSum = 0;

    long long calcSum(TreeNode *root) {
        if (root == NULL) return 0;

        long long sumRightSub = calcSum(root->right);
        long long sumLeftSub  = calcSum(root->left);

        long long sum = (long long)root->val + sumRightSub + sumLeftSub;
        if (totalSum != 0) {
          
            temp.insert({sumLeftSub, totalSum - sumLeftSub});
            temp.insert({sumRightSub, totalSum - sumRightSub});
        }

        return sum;
    }

    int maxProduct(TreeNode* root) {
        if (root == nullptr) return 0;
        totalSum = calcSum(root);
        calcSum(root);

        long long result = 0;
        for (auto it : temp) {
            long long a = it.first;
            long long b = it.second;
            long long prod = a * b;  

            if (prod > result) result = prod;
        }
        return (int)(result % mod);
    }
};
