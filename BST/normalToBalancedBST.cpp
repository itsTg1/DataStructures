// gfg

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
    Node* createBst(int s,int e){
          if(s>e){
              return NULL;
          }
          int mid=(s+e)/2;
          Node* newNode=new Node(arr[mid]);
          newNode->left=createBst(s,mid-1);
          newNode->right=createBst(mid+1,e);
          return newNode;
          
    }
    Node* balanceBST(Node* root) {
        // Code here
        if(root==NULL){
            return root;
        }
        inorderBST(root);
        
        return createBst(0,arr.size()-1);
        
    }
};