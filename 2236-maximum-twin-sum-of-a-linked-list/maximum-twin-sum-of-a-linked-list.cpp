class Solution {
public:
    int maxSum = 0;
    ListNode* start; 
    void checkTwinSum(ListNode* curr) {
        if (curr == nullptr) {
            return;
        }
        checkTwinSum(curr->next);
        maxSum = max(maxSum, start->val + curr->val);
        start = start->next;
    }
    int pairSum(ListNode* head) {
        start = head; 
        checkTwinSum(head); 
        return maxSum;
    }
};