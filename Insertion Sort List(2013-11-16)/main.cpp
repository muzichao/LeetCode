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

ListNode *insertionSortList(ListNode *head)
{
    if (NULL == head || NULL == head->next)
        return head;

    ListNode *pNowNode = head->next; // 从第二个结点开始插入
    head->next = NULL; // 链表置为只有一个结点
    ListNode *pNode = NULL;

    while (NULL != pNowNode)
    {
        pNode = head;

        // 如果插入头结点位置
        if (pNowNode->val < head->val)
        {
            head = pNowNode;
            pNowNode = pNowNode->next;
            head->next = pNode;
        }
        else
        {
            while (NULL != pNode->next)
            {
                // pNowNode 插入 pNode 和 pNode->Next 之间
                if (pNowNode->val < pNode->next->val)
                {
                    ListNode *pNodeNext = pNode->next;
                    pNode->next = pNowNode;
                    pNowNode = pNowNode->next;
                    pNode->next->next = pNodeNext;
                    break;
                }
                else
                    pNode = pNode->next;
            }
            // 插入新链表的尾结点
            if (NULL == pNode->next)
            {
                pNode->next = pNowNode;
                pNowNode = pNowNode->next;
                pNode->next->next = NULL; // 新链表的尾置为空
            }
        }
    }

    return head;
}

int main()
{
    int iA[10] = {10, 4, 2, 7, 9, 1, 8, 5, 6, 3};
    // int iA[3] = {1, 1, 2};

    ListNode *lA = CreatList(iA, 10);
    ShowList(lA);

    ListNode *lC = insertionSortList(lA);
    ShowList(lC);

    return 0;
}
