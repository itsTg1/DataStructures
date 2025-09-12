class Solution {
  public:
    Node* findCeil2(Node* root, int x, Node* result = NULL) {
    if(root == NULL) {
        return result;
    }

    if(root->data == x) {
        return root;
    }

    if(root->data > x) {
        if(result == NULL || root->data < result->data) {
            result = root;
        }
        return findCeil2(root->left, x, result);
    }
    else {
        return findCeil2(root->right, x, result);
    }
}

    int findCeil(Node* root, int x) {
        // code here
        if(root==NULL){
            return -1;
        }
        Node* result=findCeil2(root,x);
        if(result==NULL){
            return -1;
        }
        
        return result->data;
    }
};
