class Solution {
public:
    int getlen(ListNode* head){
        if(head==NULL){
            return 0;
        }
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* getReverseLis(ListNode* head, int k,int len) {
        if(head==NULL || head->next==NULL || k==1){
            return head;
        }
        if(k>len){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* nex=NULL;
        ListNode* curr=head;
        int count=0;
        while(curr!=NULL && count<k){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
            count++;
            len--;
        }
        head->next=getReverseLis(curr,k,len);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==1){
            return head;
        }
        int len=getlen(head);
        return getReverseLis(head,k,len);
    }
};