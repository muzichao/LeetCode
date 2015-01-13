/**
 * Given a linked list, swap every two adjacent
 * nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list
 * as 2->1->4->3.
 *
 * Your algorithm should use only constant space.
 * You may not modify the values in the list,
 * only nodes itself can be changed.
 */

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

ListNode *CreatList(int *a, int n)
{
    ListNode *lR = NULL, *lHead = NULL;

    for (int i = 0; i < n; ++i)
    {
        if (NULL == lR)
        {
            lR = new ListNode(a[i]);
            lHead = lR;
        }
        else
        {
            lR->next = new ListNode(a[i]);
            lR = lR->next;
        }
    }

    return lHead;
}

void ShowList(ListNode *p)
{
    while (NULL != p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

ListNode *swapPairs(ListNode *head)
{
    if (NULL == head || NULL == head->next)
    {
        return head;
    }

    ListNode *lChange = head;
    head = head->next;
    ListNode *lSave = NULL;

    while (NULL != lChange && NULL != lChange->next)
    {
        // 指向当前节点的下下个节点
        lSave = lChange->next->next;

        // 当前节点的下个节点指向当前节点
        lChange->next->next = lChange;

        // 当前节点指向下下节点(下下节点之后无节点)
        if (NULL == lSave || NULL == lSave->next)
            lChange->next = lSave;
        else // 当前节点指向下下节点的下节点（下下节点之后有节点）
            lChange->next = lSave->next;

        lChange = lSave; // 当前节点的下下节点作为当前节点
    }
    return head;
}

int main()
{
    int iA[5] = {1, 8, 3, 4, 5};

    ListNode *lA = CreatList(iA, 5);

    ShowList(lA);

    ListNode *lB = swapPairs(lA);

    ShowList(lB);

    return 0;
}
