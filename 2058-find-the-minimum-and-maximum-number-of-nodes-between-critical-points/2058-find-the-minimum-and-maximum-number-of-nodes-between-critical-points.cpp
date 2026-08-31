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

        int first=-1;
        int previ=-1;
        int minGap=INT_MAX;

        while (next != NULL) {
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                if(first==-1){
                    first=i;
                }
                else{
                    minGap=min(minGap,i-previ);
                }
                previ=i;
            }
            prev = curr;
            curr = next;
            next = next->next;
            i++;
        }
         
        if (first == -1 || previ == first) return {-1, -1};

        int maxGap = previ - first;
        return {minGap, maxGap};
    }
};