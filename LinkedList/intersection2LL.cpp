
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL){
            return NULL;
        }
        unordered_set<ListNode*> st;
        ListNode* temp=headA;
        while(temp!=NULL){
            st.insert(temp);
            temp=temp->next;
        }
        ListNode* tempB=headB;
        while(tempB!=NULL && st.count(tempB)==0){
            tempB=tempB->next;
        }
        return tempB;
    }
};