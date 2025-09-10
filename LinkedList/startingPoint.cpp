
class Solution {
public:
    bool checkLoop(ListNode* head){
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
    ListNode* findStart(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                break;
            }
        }
        ListNode* start=head;
        while(start!=slow){
            slow=slow->next;
            start=start->next;
        }
        return slow;

    }
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        if(checkLoop(head)){
            return findStart(head);
        }
        return NULL;
    }
};