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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        set<int>st;
        for(int i=0 ; i< n ; i++) st.insert(nums[i]);

        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            if(st.find(temp->val) != st.end()){
                //delete it
                if(prev == NULL){
                    head= head->next;
                    temp = head;
                    prev= NULL;
                }
                else{
                    prev->next = temp->next;
                    temp= temp->next;
                } 

            }
            else{
                prev= temp;
                temp= temp->next;
            }
        }
        return head;
    }
};