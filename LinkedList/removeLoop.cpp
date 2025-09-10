/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    bool isLoop(Node* head){
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
    }
    void removeLoop(Node* head) {
        // code here
        if(head==NULL){
            return ;
        }
        if(!isLoop(head)){
            return;
        }
        set<Node*> st;
        Node* temp=head;
        Node* prev=NULL;
        while(st.count(temp)==0){
            st.insert(temp);
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
    }
};