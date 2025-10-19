/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  vector<int> arr;
  void inorderBST(Node* root){
        if(root==NULL){
            return ;
        }
        inorderBST(root->left);
        arr.push_back(root->data);
        inorderBST(root->right);
    }
    int findMedian(Node* root) {
        // Code here
        if(root==NULL){
            return -1;
        }
        inorderBST(root);
        int n=arr.size();
        if(n%2==0){
            return arr[(n/2)-1];
        }
        return arr[((n+1)/2)-1];
        
    }
};