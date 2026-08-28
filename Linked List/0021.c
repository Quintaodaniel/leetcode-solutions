/*
 * Time complexity: O(m + n)
 * Space complexity: O(1)
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL && list2 == NULL) return NULL;

    struct ListNode dummy = {0, NULL};
    struct ListNode* list3 = &dummy;
    struct ListNode* l1 = list1;
    struct ListNode* l2 = list2;

    while(l1 != NULL && l2 != NULL) {
        list3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        list3 = list3->next;

        if (l1->val <= l2->val) {
            list3->val = l1->val;
            l1 = l1->next;
        } else { 
            list3->val = l2->val;
            l2 = l2->next;
        }

        list3->next = NULL;
    }

    while(l1 != NULL) {
        list3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        list3 = list3->next;

        list3->val = l1->val;
        list3->next = NULL;
        l1 = l1->next;
    }

    while(l2 != NULL) {
        list3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        list3 = list3->next;

        list3->val = l2->val;
        list3->next = NULL;
        l2 = l2->next;
    }

    return dummy.next;
}