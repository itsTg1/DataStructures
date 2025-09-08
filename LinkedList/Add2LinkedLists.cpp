
class Solution {
public:
    
    ListNode* addList(ListNode* l1,ListNode* l2){
        int carry=0;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        while(temp1!=NULL && temp2!=NULL){
            int val=temp1->val + temp2->val + carry;
            carry=val/10;
            int rem=val%10;
            ListNode* newNod=new ListNode(rem);
            tail->next=newNod;
            tail=tail->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL){
            int val=temp1->val + carry;
            carry=val/10;
            int rem=val%10;
            ListNode* newNod=new ListNode(rem);
            tail->next=newNod;
            tail=tail->next;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            int val=temp2->val + carry;
            carry=val/10;
            int rem=val%10;
            ListNode* newNod=new ListNode(rem);
            tail->next=newNod;
            tail=tail->next;
            temp2=temp2->next;
        }
        if(carry!=0){
            ListNode* newNod=new ListNode(carry);
            tail->next=newNod;
            tail=tail->next;
        }
        ListNode* toreturn=dummy->next;
        dummy->next=NULL;
        return toreturn;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        
        ListNode* newHead=addList(l1,l2);
        return newHead;
    }
};