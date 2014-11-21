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

/**
 * 创建链表
 * @param  a 数组头指针
 * @param  n 数组元素个数
 * @return   生成链表头结点
 */
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

/**
 * 显示链表
 * @param p 待显示链表的头结点
 */
void ShowList(ListNode *p)
{
    while (NULL != p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

/**
 * 合并两个有序链表，保持链表依然有序
 * @param  l1 第一个链表头结点
 * @param  l2 第二个链表头结点
 * @return    输出链表头结点
 */
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (NULL == l1)
        return l2;

    if (NULL == l2)
        return l1;

    ListNode *lNewHead = NULL; // 指向新的头结点
    ListNode *lNewEnd = NULL; // 指向新链表的尾结点
    ListNode *lMinNode = NULL; // lMinNode 指向较小结点

    // 合并等长部份
    while (NULL != l1 && NULL != l2)
    {
        // 找到较小结点
        if (l1->val <= l2->val)
        {
            lMinNode = l1;
            l1 = l1->next;
        }
        else
        {
            lMinNode = l2;
            l2 = l2->next;
        }

        // 如果头结点为空，则指向头结点，否则指向尾结点
        if (NULL == lNewHead)
        {
            lNewHead = lMinNode;
            lNewEnd = lMinNode;
        }
        else
        {
            lNewEnd->next = lMinNode;
            lNewEnd = lNewEnd->next;
        }
    }

    // 添加不等长部份
    if (NULL != l1)
        lNewEnd->next = l1;
    else
        lNewEnd->next = l2;

    return lNewHead;
}

int main()
{
    int iA[6] = {1, 3, 4, 7, 8, 10};
    ListNode *lA = CreatList(iA, 6);
    ShowList(lA);

    int iB[4] = {2, 5, 9, 15};
    ListNode *lB = CreatList(iB, 4);
    ShowList(lB);

    ListNode *lC = mergeTwoLists(lA, lB);
    ShowList(lC);

    return 0;
}
