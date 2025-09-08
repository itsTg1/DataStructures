// leetcode- 142
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
        map<ListNode*,bool> mp;
        ListNode* temp=head;
        while(mp.find(temp)==mp.end()){
            mp[temp]=1;
            temp=temp->next;
        }
        return temp;
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

// ------------------------------------------------**-------------------------------

