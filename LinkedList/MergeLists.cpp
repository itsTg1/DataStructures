
class Solution {
  public:
    
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        if(head1==NULL){
            return head2;
        }
        if (head2==NULL){
            return head1;
        }
        Node* dummy=new Node(-1);
        Node* tail=dummy;
        Node* temp1=head1;
        Node* temp2=head2;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->data<=temp2->data){
                Node* newNod=new Node(temp1->data);
                tail->next=newNod;
                tail=newNod;
                temp1=temp1->next;
            }
            else{
                Node* newNod=new Node(temp2->data);
                tail->next=newNod;
                tail=newNod;
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL){
            Node* newNod=new Node(temp1->data);
            tail->next=newNod;
            tail=newNod;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            Node* newNod=new Node(temp2->data);
            tail->next=newNod;
            tail=newNod;
            temp2=temp2->next;
        }
        return dummy->next;
    }
};