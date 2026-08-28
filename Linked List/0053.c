/*
    * Time complexity:  O(n)
    * Space complexity: O(1)
*/

#include <stdlib.h>

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy = {0, head};
    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;
    int iter = n;

    while(fast->next != NULL) {
        if (iter == 0) slow = slow->next;
        else iter --;

        fast = fast->next;
    }

    struct ListNode* temp = slow->next;
    slow->next = temp->next;
    free(temp);

    return dummy.next;
}