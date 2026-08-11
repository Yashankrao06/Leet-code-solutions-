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
    ListNode* removeElements(ListNode* head, int val) {
        // Ek dummy node banaya jiska value 0 hai (value kuch bhi ho sakti hai)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* curr = dummy;
        
        // Jab tak aage nodes hain, check karo
        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                // Node ko bypass kar do (delete)
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp; // Memory free karne ke liye (optional in leetcode, but good practice)
            } else {
                // Aage move karo
                curr = curr->next;
            }
        }
        
        // Naya head return karo jo dummy ka next hai
        ListNode* newHead = dummy->next;
        delete dummy; // Dummy node ki memory free karo
        return newHead;
    }
};