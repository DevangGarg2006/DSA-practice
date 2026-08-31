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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* next = head->next->next;
        ListNode* curr = head->next;
        int i = 1;
        if (!head || !head->next || !head->next->next)
            return {-1, -1};

        vector<int> critical;

        while (next != NULL) {
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                critical.push_back(i);
            }
            prev = curr;
            curr = next;
            next = next->next;
            i++;
        }
         if (critical.size() < 2) return {-1, -1};
        int minGap = INT_MAX;
        for (int j = 1; j < critical.size(); j++) {
            minGap = min(minGap, critical[j] - critical[j-1]);
        }
        int maxGap = critical.back() - critical.front();

        return {minGap, maxGap};
    }
};