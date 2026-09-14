/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // dummy node
        int length = 1;
        if (!head || !head->next || k == 0)
            return head;

        ListNode* temp = head;
        while (temp->next!= NULL) {
            length++;
            temp = temp->next;
        }
        k = k % length;
        if (k == 0)
            return head;

        int move = length - k;
        temp->next = head; // amke it circular
        ListNode* newtail = head;
        for (int i = 1; i < move; i++) {
            newtail = newtail->next;
        }
        ListNode* newhead = newtail->next;
        newtail->next = NULL;
        return newhead;
    }
};