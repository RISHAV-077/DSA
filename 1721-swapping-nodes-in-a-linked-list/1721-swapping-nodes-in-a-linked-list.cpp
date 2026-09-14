class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int length = 0;
        ListNode* tail = head;
        while (tail != NULL) {
            tail = tail->next;
            length++;
        }
        ListNode* start = head;
        for (int i = 1; i < k; i++) {
            start = start->next;
        }
        int pos = length - k + 1;
        ListNode* end = head;
        for (int i = 1; i < pos; i++) {
            end = end->next;
        }
        swap(start->val, end->val);

        return head;
    }
};