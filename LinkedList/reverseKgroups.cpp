 class Solution {
public:
 ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1) {
            return head;
        }
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;  // Tracks the node before the group
        ListNode* curr = head;

        while (true) {
            // Check if there are at least k nodes ahead
            ListNode* check = curr;
            int count = 0;
            while (check != nullptr && count < k) {
                check = check->next;
                count++;
            }
            if (count < k) {
                break; // Less than k nodes, don't reverse
            }
            
            // Reverse k nodes
            ListNode* tail = curr;
            ListNode* prevNode = nullptr;
            for (int i = 0; i < k; ++i) {
                ListNode* nex = curr->next;
                curr->next = prevNode;
                prevNode = curr;
                curr = nex;
            }
            
            // Connect reversed part with previous and next parts
            prev->next = prevNode;
            tail->next = curr;
            
            // Move prev to the tail for the next group
            prev = tail;
        }
        
        head = dummy->next;
        delete dummy; // Clean up dummy node
        return head;
    }
};