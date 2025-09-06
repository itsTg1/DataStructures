
class Solution {
public:
    ListNode* insertAtTail2(ListNode* tail,ListNode* temp,ListNode* head){
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
    ListNode* insertAtTail(ListNode* tail,ListNode* temp){
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* tail1 = NULL;
        ListNode* head1 = NULL;
        ListNode* tail2 = NULL;
        ListNode* head2 = NULL;
        int cnt1 = 0;
        int cnt2 = 0;
        int idx=1;
        ListNode* temp = head;
        while (temp != NULL) {
            ListNode* nex = temp->next;
            if ((idx) % 2 == 0) {
                if (cnt1 == 0) {
                    tail1 = insertAtTail2(tail1, temp, head1);
                    head1 = tail1;
                    cnt1++;
                } else {
                    tail1 = insertAtTail(tail1, temp);
                }

            } else {
                if (cnt2 == 0) {
                    tail2 = insertAtTail2(tail2, temp, head2);
                    head2 = tail2;
                    cnt2++;
                } else {
                    tail2 = insertAtTail(tail2, temp);
                }
            }
            temp = nex;
            idx++;
        }
        tail2->next = head1;
        return head2;
    }
};