/**
 * Remove Duplicates from Sorted List
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 */

ListNode *deleteDuplicates(ListNode *head)
{
    if (NULL == head)
        return head;

    ListNode *p = head;

    while (NULL != p->next)
    {
        if (p->next->val != p->val)
            p = p->next;
        else
            p->next = p->next->next;
    }

    return head;
}
