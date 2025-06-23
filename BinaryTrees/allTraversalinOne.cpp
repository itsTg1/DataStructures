void allTraversal(Node* root)
{

    vector<int> pre;
    vector<int> post;
    vector<int> inn;
    stack<pair<Node*, int> > s;
    s.push({root,1});

    while(!s.empty()){
        auto frontNode=s.top();

        s.pop();
        
        if(frontNode.second==1){
            pre.push_back(frontNode.first->data);
            frontNode.second++;
            s.push(frontNode);
            if(frontNode.first->left){
                s.push({frontNode.first->left,1});
            }
        }
        else if(frontNode.second==2){
            inn.push_back(frontNode.first->data);
            frontNode.second++;
            s.push(frontNode);
            if(frontNode.first->right){
                s.push({frontNode.first->right,1});
            }
        }
        else{
            post.push_back(frontNode.first->data);
        }
    }

    cout << "Preorder Traversal: ";
    for (int i = 0; i < pre.size(); i++) {
        cout << pre[i] << " ";
    }
    cout << "\n";

    // Printing Inorder
    cout << "Inorder Traversal: ";

    for (int i = 0; i < inn.size(); i++) {
        cout << inn[i] << " ";
    }
    cout << "\n";

    // Printing Postorder
    cout << "Postorder Traversal: ";

    for (int i = 0; i < post.size(); i++) {
        cout << post[i] << " ";
    }
    cout << "\n";
}