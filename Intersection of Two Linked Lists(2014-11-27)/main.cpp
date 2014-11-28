#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>

using namespace std;

// 链表中的结点
struct ListNode
{
    int value;
    ListNode *next;

    ListNode (int val)
    {
        this->value = val;
        this->next = NULL;
    }
};

/************************************************************************/
/*函数名：CreateSingleLinkedList
/*功  能：创建无环单链表
/*返回值：返回头指针
/************************************************************************/
ListNode *CreateSingleLinkedList(int iLength)
{
    iLength = iLength < 0 ? 15 : iLength; // 链表长度
    ListNode *pNode = NULL;
    ListNode *pRoot = NULL;

    for (int i = 0; i < iLength; ++i)
    {
        // 如果链表为空则头部指向新的结点
        if (NULL == pRoot)
        {
            pRoot = new ListNode(rand());
            if (pRoot == NULL)
                cout << "error!" << endl;
        }
        else // 如果链表不为空则新的结点插入头部
        {
            pNode = new ListNode(rand());
            if (pNode == NULL)
                cout << "error!" << endl;

            pNode->next = pRoot;
            pRoot = pNode;
        }
    }

    return pRoot;
}

/************************************************************************/
/*函数名：CreateOverlappedSingleLinkedList
/*功  能：创建重叠的单链表
/*返回值：返回头指针
/************************************************************************/
ListNode *CreateOverlappedSingleLinkedList(ListNode *pOriginalRoot, int iLength)
{
    ListNode *pNode = NULL;
    ListNode *pRoot = NULL;
    iLength = iLength < 0 ? 5 : iLength;

    for (int i = 0; i < iLength; ++i)
    {
        // 如果链表为空则头部指向新的结点
        if (NULL == pRoot)
        {
            pRoot = new ListNode(rand());
            if (pRoot == NULL)
                cout << "error!" << endl;
        }
        else // 如果链表不为空则新的结点插入头部
        {
            pNode = new ListNode(rand());
            if (pNode == NULL)
                cout << "error!" << endl;

            pNode->next = pRoot;
            pRoot = pNode;
        }
    }

    // 原始单链表平移一定长度，作为重叠开始部份
    for (int i = 0; i < iLength; ++i)
    {
        pOriginalRoot = pOriginalRoot->next;
    }

    // 让pNode指向尾结点
    while (pNode->next != NULL)
    {
        pNode = pNode->next;
    }

    pNode->next = pOriginalRoot; // 连接

    return pRoot;
}

/************************************************************************/
/*函数名：ShowSingleLinkedList
/*功  能：显示单链表
/*返回值：无
/************************************************************************/
void ShowSingleLinkedList(ListNode *pRoot)
{
    ListNode *pNode;

    while (NULL != pRoot)
    {
        cout << pRoot->value << " ";
        pRoot = pRoot->next;
    }
    cout << endl << endl;
}

/**
 * 两个链表的交点
 * @param  headA 链表A的头结点
 * @param  headB 链表B的头结点
 * @return       交点
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (NULL == headA || NULL == headB)
        return NULL;

    ListNode *lNode = headA;

    // 将链表A中的结点指针存储在set容器中
    set<ListNode *> lSetCircle;

    while (lNode != NULL)
    {
        lSetCircle.insert(lNode);
        lNode = lNode->next;
    }

    // 从链表B的头结点开始，在set容器中查找是否属于环中结点
    // 找到的第一个环中结点就是交点
    lNode = headB;

    while (NULL != lNode && lSetCircle.find(lNode) == lSetCircle.end())
        lNode = lNode->next;

    return lNode;
}

/**
 * 两个链表的交点
 * @param  headA 链表A的头结点
 * @param  headB 链表B的头结点
 * @return       交点
 */
ListNode *getIntersectionNodeOpt(ListNode *headA, ListNode *headB)
{
    if (NULL == headA || NULL == headB)
        return NULL;

    // 计算链表A的长度
    ListNode *lNodeA = headA;
    int iLengthA = 0;

    while (NULL != lNodeA)
    {
        ++iLengthA;
        lNodeA = lNodeA->next;
    }

    // 计算链表B的长度
    ListNode *lNodeB = headB;
    int iLengthB = 0;
    while (NULL != lNodeB)
    {
        ++iLengthB;
        lNodeB = lNodeB->next;
    }

    // 先让较长链表走n个结点
    // 两个链表剩余结点个数相同
    int iLengthSub = 0;
    lNodeA = headA;
    lNodeB = headB;

    if (iLengthA > iLengthB)
    {
        iLengthSub = iLengthA - iLengthB;
        while (iLengthSub > 0)
        {
            lNodeA = lNodeA->next;
            iLengthSub--;
        }
    }
    else
    {
        iLengthSub = iLengthB - iLengthA;
        while (iLengthSub > 0)
        {
            lNodeB = lNodeB->next;
            iLengthSub--;
        }
    }

    // 两个链表同时走，第一个共同交点就是两个链表的交点
    while (NULL != lNodeA && NULL != lNodeB)
    {
        if (lNodeA == lNodeB)
            return lNodeA;
        else
        {
            lNodeA = lNodeA->next;
            lNodeB = lNodeB->next;
        }
    }

    return NULL;
}

/**
 * 两个链表的交点
 * @param  headA 链表A的头结点
 * @param  headB 链表B的头结点
 * @return       交点
 */
ListNode *getIntersectionNodeOpt2(ListNode *headA, ListNode *headB)
{
    if (NULL == headA || NULL == headB)
        return NULL;

    ListNode *lNodeA = headA;
    ListNode *lNodeB = headB;

    // 两个链表同时走，第一个共同交点就是两个链表的交点
    while (NULL != lNodeA && NULL != lNodeB)
    {
        if (lNodeA == lNodeB)
            return lNodeA;

        lNodeA = lNodeA->next;
        lNodeB = lNodeB->next;

        if (NULL == lNodeA && NULL != lNodeB)
            lNodeA = headB;

        if (NULL == lNodeB && NULL != lNodeA)
            lNodeB = headA;
    }

    return NULL;
}

int main()
{
    ListNode *pRootOne, *pRootTwo, *pIntersectionNode;

    // 生成带环单链表One
    pRootOne = CreateSingleLinkedList(4);
    pRootTwo = CreateOverlappedSingleLinkedList(pRootOne, 2);
    // pRootTwo = CreateSingleLinkedList(1);

    ShowSingleLinkedList(pRootOne);
    ShowSingleLinkedList(pRootTwo);

    pIntersectionNode = getIntersectionNodeOpt2(pRootOne, pRootTwo);

    if (NULL != pIntersectionNode)
        cout << pIntersectionNode->value << endl;
    else
        cout << "NULL" << endl;

    return 0;
}
