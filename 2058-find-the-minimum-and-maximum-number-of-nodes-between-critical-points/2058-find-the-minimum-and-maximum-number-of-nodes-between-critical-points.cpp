class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int>ans;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* agla = curr->next;

        int i = 1;

        while (agla != NULL) {
            if (curr->val < prev->val && curr->val < agla->val) {
                ans.push_back(i);
            }
            if (curr->val > prev->val && curr->val > agla->val) {
                ans.push_back(i);
            }
            prev = curr;
            curr = agla;
            agla = agla->next;
            i++;
        }

        vector<int> result = {-1, -1};
        if (ans.size() < 2)
            return result;
        int mini = INT_MAX;

        for (int i = 1; i < ans.size(); i++) {
            mini = min(mini, ans[i] - ans[i - 1]);
        }
        int maxi = ans.back() - ans.front();
        return {mini, maxi};
    }
};