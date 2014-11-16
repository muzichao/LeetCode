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
 * 链表旋转
 * @param  head 头结点
 * @param  k    需要旋转的结点的个数
 * @return      新链表的头指针
 */
ListNode *rotateRight(ListNode *head, int k)
{
    // 如果链表为空或只有一个结点直接头结点
    if (NULL == head || NULL == head->next)
        return head;

    int iLength = 0;
    ListNode *lNode = head;

    // 计算链表结点个数，并让尾结点指向头结点
    while (NULL != lNode->next)
    {
        ++iLength;
        lNode = lNode->next;
    }
    lNode->next = head;
    ++iLength;

    // 计算需要断开循环链表的位置
    k = k % iLength;
    k = iLength - k + 1;

    iLength = 1;

    // 查找需要断开的位置
    while (iLength < k)
    {
        head = head->next;
        lNode = lNode->next;
        ++iLength;
    }

    // 断开环
    lNode->next = NULL;

    return head;
}

/**
 * 生成链表
 * @param  a 数组头指针
 * @param  n 数组个数
 * @return   链表头指针
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
 * @param p 链表头结点
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

int main()
{
    int iA[7] = {1, 2, 3, 4, 5, 6, 7};

    ListNode *lA = CreatList(iA, 7);
    ShowList(lA);

    ListNode *lC = rotateRight(lA, 8);
    ShowList(lC);

    return 0;
}
