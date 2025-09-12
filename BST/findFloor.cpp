// Function to search a node in BST.
class Solution {

  public:
  Node* findFloor(Node* root, int x, Node* result = NULL) {
    if(root == NULL) {
        return result;
    }

    if(root->data == x) {
        return root;
    }

    if(root->data > x) {
        
        return findFloor(root->left, x, result);
    }
    else {
        // update result only if value of root is greater than result bcz we have to find nearest
        if(result == NULL || root->data > result->data) {
            result = root;
        }
        return findFloor(root->right, x, result);
    }
}
    int floor(Node* root, int x) {
        // Code here
        if(root==NULL){
            return -1;
        }
        Node* result=findFloor(root,x);
        if(result==NULL){
            return -1;
        }
        return result->data;
    }
};