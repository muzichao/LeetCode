/**
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain
 * a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *lR = NULL, *lHead = NULL;
    int flag = 0; // 进位标志

    while (NULL != l1 && NULL != l2)
    {
        int iSum = l1->val + l2->val + flag;
        if (iSum > 9)
        {
            iSum -= 10;
            flag = 1;
        }
        else
        {
            flag = 0;
        }

        if (NULL == lR) // 链表为空时的处理
        {
            lR = new ListNode(iSum);
            lHead = lR;
        }
        else // 此时 lR 已非指向头结点
        {
            lR->next = new ListNode(iSum);
            lR = lR->next;
        }

        l1 = l1->next;
        l2 = l2->next;
    }

    // 可能链表1的位数比链表2的位数多
    while (NULL != l1)
    {
        int iSum = l1->val + flag;
        if (iSum > 9)
        {
            iSum -= 10;
            flag = 1;
        }
        else
        {
            flag = 0;
        }

        lR->next = new ListNode(iSum);
        lR = lR->next;
        l1 = l1->next;
    }

    // 可能链表2的位数比链表1的位数多
    while (NULL != l2)
    {
        int iSum = l2->val + flag;
        if (iSum > 9)
        {
            iSum -= 10;
            flag = 1;
        }
        else
        {
            flag = 0;
        }

        lR->next = new ListNode(iSum);
        lR = lR->next;
        l2 = l2->next;
    }

    // 可能存在最高位相加后还有进位
    if (1 == flag)
    {
        lR->next = new ListNode(1);
    }

    return lHead;
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
    int iA[2] = {1, 8};
    int iB[1] = {0};

    ListNode *lA = CreatList(iA, 2);
    ListNode *lB = CreatList(iB, 1);

    ListNode *lC = addTwoNumbers(lA, lB);

    ShowList(lA);
    ShowList(lB);
    ShowList(lC);

    return 0;
}
