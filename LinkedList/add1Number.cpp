

class Solution {
  public:
    Node* reverseList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node* temp=head;
        Node* prev=NULL;
        Node* curr=temp;
        while(curr->next!=NULL){
            Node* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        head=curr;
        curr->next=prev;
        return head;
    }
    Node* addOne(Node* head) {
        // Your Code here
        if(head==NULL){
            return NULL;
        }
        Node* reverse=reverseList(head);
        Node* tem=reverse;
        int carry=1;
        Node* prev=NULL;
        while(reverse!=NULL && carry!=0){
            int val=reverse->data+carry;
            carry=val/10;
            reverse->data=(val)%10;
            prev=reverse;
            reverse=reverse->next;
        }
        if(carry!=0){
            Node* newNod=new Node(carry);
            prev->next=newNod;
            
        }
        return reverseList(tem);
        
    }
};