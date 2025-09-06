// Time Complexity: O(n)

// Space Complexity: O(1)

class Solution {
  public:
    
    Node* insertAtTail2(Node* tail,Node* temp,Node* head){
        if(head==NULL && tail==NULL){
            temp->next=NULL;
            head=temp;
            tail=temp;
            return temp;
        }
        tail->next=temp;
        temp->next=NULL;
        tail=temp;
        return tail;
        
    }
    Node* insertAtTail(Node* tail,Node* temp){
        if(tail==NULL){
            temp->next=NULL;
            tail=temp;
            return tail;
        }
        tail->next=temp;
        temp->next=NULL;
        tail=temp;
        return tail;
        
    }
    Node* divide(Node* head) {
        // code here
        if(head==NULL){
            return NULL;
        }
        Node* tail1=NULL;
        Node* head1=NULL;
        Node* tail2=NULL;
        Node* head2=NULL;
        int cnt1=0;
        int cnt2=0;
        Node* temp=head;
        while(temp!=NULL){
            Node* nex=temp->next;
            if((temp->data)%2==0){
                if(cnt1==0){
                    tail1=insertAtTail2(tail1,temp,head1);
                    head1=tail1;
                    cnt1++;
                }
                else{
                    tail1=insertAtTail(tail1,temp);
                }
                
            }
            else{
                if(cnt2==0){
                    tail2=insertAtTail2(tail2,temp,head2);
                    head2=tail2;
                    cnt2++;
                }
                else{
                   tail2=insertAtTail2(tail2,temp,head2); 
                }
                
            }
            temp=nex;
        }
        tail1->next=head2;
        return head1;
    }
};