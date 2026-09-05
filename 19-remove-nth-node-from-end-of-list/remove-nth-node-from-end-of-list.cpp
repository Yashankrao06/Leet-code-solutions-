class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        if (count == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        temp = head;
        for (int i = 0; i < count - n - 1; i++) {
            temp = temp->next;
        }
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        return head;
    }
};