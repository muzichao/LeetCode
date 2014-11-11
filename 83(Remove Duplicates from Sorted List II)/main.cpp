/**
 * Given a sorted linked list, delete all nodes that have
 * duplicate numbers, leaving only distinct numbers from
 * the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
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

ListNode *RemoveDuplicates(ListNode *head)
{
    if (NULL == head || NULL == head->next)
        return head;

    ListNode *lRight = head;
    ListNode *lLeft = head;
    head = NULL;
    int iDuplicate = 0; // 标记值出现次数

    ListNode *p = NULL; // 用来标记新链表的最后一个结点

    // 用lLeft和lRight查找一个满足要求的结点
    while (NULL != lRight)
    {
        if (lLeft->val == lRight->val)
        {
            iDuplicate++;
            lRight = lRight->next;
        }
        else if (iDuplicate > 1)
        {
            lLeft = lRight;
            iDuplicate = 0;
        }
        else
        {
            if (NULL == head)
            {
                head = lLeft;
                p = lLeft;
            }
            else
            {
                p->next = lLeft;
                p = p->next;
            }
            p->next = NULL;
            iDuplicate = 0;
            lLeft = lRight;
        }
    }

    if (NULL == lLeft ->next)
    {
        if (NULL == head)
        {
            head = lLeft;
        }
        else
        {
            p->next = lLeft;
        }
    }

    return head;
}

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

int main()
{
    // int iA[20] = {0, 1, 1, 1, 2, 2, 2, 4, 4, 5, 5, 7, 7, 8, 8, 9, 10, 10, 11, 11};
    int iA[3] = {1, 1, 2};

    ListNode *lA = CreatList(iA, 3);
    ShowList(lA);

    ListNode *lC = RemoveDuplicates(lA);
    ShowList(lC);

    return 0;
}
