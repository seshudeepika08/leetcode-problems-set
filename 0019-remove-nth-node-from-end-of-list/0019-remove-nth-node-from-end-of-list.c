struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Dummy node
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;

    // Move fast n+1 steps
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move both pointers
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove node
    struct ListNode* temp = slow->next;
    slow->next = temp->next;

    free(temp);  // optional

    return dummy.next;
}