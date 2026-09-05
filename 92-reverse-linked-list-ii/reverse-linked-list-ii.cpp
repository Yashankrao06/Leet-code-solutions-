class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Step 2: 'prev' pointer ko us node tak le jao jo 'left' se theek pehle hai
        ListNode* prev = dummy;
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }
        
        // 'curr' wo node hai jahan se reversal shuru hoga
        ListNode* curr = prev->next;
        
        // Step 3: Connections ko swap karke reverse karo
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = curr->next;      // temp wo node hai jise aage lana hai
            curr->next = temp->next;          // curr ko aage wale node se jodo
            temp->next = prev->next;          // temp ko sublist ke sabse aage rakho
            prev->next = temp;                // prev ab naye aage wale node (temp) ko point karega
        }
        
        // Naya head return karo (dummy ke aage wala)
        ListNode* newHead = dummy->next;
        delete dummy; // Memory leak se bachne ke liye dummy hata do
        return newHead;
    }
};