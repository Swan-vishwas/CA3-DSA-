class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        // Calculate the length of the linked list
        int len = 1;
        ListNode* tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        // Reduce unnecessary rotations
        k = k % len;

        if (k == 0) {
            return head;
        }

        // Connect the last node to the first node
        tail->next = head;

        // Find the new tail
        int steps = len - k;
        ListNode* newTail = head;

        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        // Update the new head
        ListNode* newHead = newTail->next;

        // Break the circular linked list
        newTail->next = NULL;

        return newHead;
    }
};
