/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool hasCycle(ListNode *head)
{
    ListNode *lTwo;
    ListNode *lThree;

    if (NULL == head || NULL == head->next)
        return false;

    lTwo = head;
    lThree = head->next;

    while (NULL != lThree)
    {
        if (lTwo == lThree)
            return true;
        else if (NULL != lThree->next && NULL != lThree->next->next && NULL != lThree->next->next->next)
        {
            lTwo = lTwo->next->next;
            lThree = lThree->next->next->next;
        }
        else
        {
            return false;
        }
    }
}
