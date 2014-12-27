/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>
#include <time.h>

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
/*函数名：CreateSingleCircularLinkedList
/*功  能：创建带环的单链表
/*返回值：返回头指针
/************************************************************************/
ListNode *CreateSingleCircularLinkedList()
{
    ListNode *pNode = NULL;
    ListNode *pRoot = NULL;
    ListNode *pCircul = NULL;
    int iLength = 15000; // 链表长度

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

    // 查找需要连接成环的位置
    pCircul = pRoot;
    for (int i = 0; i < 10000; ++i)
    {
        pCircul = pCircul->next;
    }

    cout << "The value of the cross : " << pCircul->value << endl;

    // 让pNode指向尾结点
    while (pNode->next != NULL)
    {
        pNode = pNode->next;
    }

    pNode->next = pCircul; // 环封闭

    return pRoot;
}

/**
 * 链表中是否有环。
 * 使用一个指针一次走两个结点，一个指针一次走三个结点，
 * 如果有环，慢指针一定能追上快指针
 * @param  head 头结点
 * @return      true 或 false
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

/**
 * 检测是否有环。有环返回交点上的值，无环返回-1
 * 使用vector容器保存环上的结点，并依次查找，效率低
 * @param  head 头结点
 * @return      交点的值或-1
 */
int detectCycle(ListNode *head)
{
    ListNode *lTwo;
    ListNode *lThree;

    if (NULL == head || NULL == head->next)
        return -1;

    lTwo = head;
    lThree = head->next;

    // 如果有环，找到环中的一个结点。否则，结束
    while (NULL != lThree)
    {
        if (lTwo == lThree)
            lThree = NULL;
        else if (NULL != lThree->next && NULL != lThree->next->next && NULL != lThree->next->next->next)
        {
            lTwo = lTwo->next->next;
            lThree = lThree->next->next->next;
        }
        else
        {
            return -1;
        }
    }

    // 将环中的结点指针存储在vector容器中
    vector<ListNode *> lVecCircle;

    lVecCircle.push_back(lTwo);
    lThree = lTwo->next;

    while (lThree != lTwo)
    {
        lVecCircle.push_back(lThree);
        lThree = lThree->next;
    }

    // 从链表的头结点开始，在vector容器中查找是否属于环中结点
    // 找到的第一个环中结点就是交点
    lThree = head;

    vector<ListNode *>::iterator iter;
    while (1)
    {
        for (iter = lVecCircle.begin(); iter != lVecCircle.end(); iter++)
        {
            if (*iter == lThree)
                return lThree->value;
        }
        lThree = lThree->next;
    }

}

/**
 * 检测是否有环。有环返回交点上的值，无环返回-1
 * 使用set容器（平衡二叉树）保存环上的结点。查找效率高。
 * @param  head 头结点
 * @return      交点的值或-1
 */
int detectCycleOpt(ListNode *head)
{
    ListNode *lTwo;
    ListNode *lThree;

    if (NULL == head || NULL == head->next)
        return -1;

    lTwo = head;
    lThree = head->next;

    // 如果有环，找到环中的一个结点。否则，结束
    while (NULL != lThree)
    {
        if (lTwo == lThree)
            lThree = NULL;
        else if (NULL != lThree->next && NULL != lThree->next->next && NULL != lThree->next->next->next)
        {
            lTwo = lTwo->next->next;
            lThree = lThree->next->next->next;
        }
        else
        {
            return -1;
        }
    }

    // 将环中的结点指针存储在set容器中
    set<ListNode *> lSetCircle;

    lSetCircle.insert(lTwo);
    lThree = lTwo->next;

    while (lThree != lTwo)
    {
        lSetCircle.insert(lThree);
        lThree = lThree->next;
    }

    // 从链表的头结点开始，在set容器中查找是否属于环中结点
    // 找到的第一个环中结点就是交点
    lThree = head;

    while (lSetCircle.find(lThree) == lSetCircle.end())
    {
        lThree = lThree->next;
    }

    return lThree->value;
}

int main()
{
    ListNode *pRootOne;

    // 生成带环单链表One
    pRootOne = CreateSingleCircularLinkedList();

    clock_t startTime, endTime;
    startTime = clock();
    cout << hasCycle(pRootOne) << endl;
    endTime = clock();
    cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;

    startTime = clock();
    cout << detectCycle(pRootOne) << endl;
    endTime = clock();
    cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;

    startTime = clock();
    cout << detectCycleOpt(pRootOne) << endl;
    endTime = clock();
    cout << "Run time: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "S" << endl;

    return 0;
}
