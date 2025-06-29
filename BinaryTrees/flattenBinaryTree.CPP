// o(1)-Morris Travers.
class Solution {
  public:
    
    void flatten(Node *root) {
        // code here
        Node* curr=root;
        while(curr!=NULL){
            if(curr->left){
                Node* prev=curr->left;
                while(prev->right){
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
            
        }
       
    }
};


// O(n)

// User function Template for C++

class Solution {
  public:
    void preorder(Node *root,queue<Node*> &q){
        if(root==NULL){
            return ;
        }
        q.push(root);
        preorder(root->left,q);
        
        preorder(root->right,q);
    }
    void flatten(Node *root) {
        // code here
        queue<Node*> q;
       
        preorder(root,q);
        Node* curr=root;
        q.pop();
        while(!q.empty()){
            Node* front=q.front();
            q.pop();
            curr->right=front;
            curr->left=NULL;
            curr=curr->right;
        }
       
    }
};