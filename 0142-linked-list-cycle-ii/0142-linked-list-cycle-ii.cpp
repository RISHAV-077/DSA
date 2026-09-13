class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(fast == NULL || fast->next == NULL)
            return NULL;
        ListNode* p = head;
        while(p != slow){
            p = p->next;
            slow = slow->next;
        }

        return p;
    }
};