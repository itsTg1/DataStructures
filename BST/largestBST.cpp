/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    void inorder(Node* root,vector<int> &arr){
        if(root==NULL){
            return ;
        }
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
    int findInorder(Node* root){
        if(root==NULL){
            return 0;
        }
        vector<int> arr;
        inorder(root,arr);
        vector<int> temp=arr;
        sort(arr.begin(),arr.end());
        if(arr==temp){
            for(int i=1;i<temp.size();i++){
                if(temp[i]==temp[i-1]){
                    return 0;
                }
            }
            return arr.size();
        }
        return 0;
    }
    int largestBst(Node *root) {
        // Your code here
        if(root==NULL){
            return 0;
        }
        return max(findInorder(root),max(largestBst(root->left),largestBst(root->right)));
        
        
        
    }
};


// ----------------------------------------------------------------------------------------------------




class Solution {
  public:
    class info {
      public:
        int min_ele;
        int max_ele;
        int size;
        bool validBst;
        
        info() {
            min_ele = INT_MAX;
            max_ele = INT_MIN;
            size = 0;
            validBst = true;
        }
        
        info(int min_ele, int max_ele, int size, bool validBst) {
            this->min_ele = min_ele;
            this->max_ele = max_ele;
            this->size = size;
            this->validBst = validBst;
        }
    };

    int maxsize = 0;

    info findMaxbst(Node* root) {
        if (root == NULL) {
            return info(INT_MAX, INT_MIN, 0, true);
        }
        
        info leftans = findMaxbst(root->left);
        info rightans = findMaxbst(root->right);
        
        info curr;
        curr.size = leftans.size + rightans.size + 1;
        curr.min_ele = min(root->data, leftans.min_ele);
        curr.max_ele = max(root->data, rightans.max_ele);
        
        if (leftans.validBst && rightans.validBst &&
            root->data > leftans.max_ele && root->data < rightans.min_ele) {
            curr.validBst = true;
            maxsize = max(maxsize, curr.size);
        } else {
            curr.validBst = false;
        }
        
        return curr;
    }

    int largestBst(Node *root) {
       
        findMaxbst(root);
        return maxsize;
    }
};
