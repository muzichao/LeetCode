ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (NULL == head)
        return head;

    ListNode *p = head;

    // 计算结点个数
    int iListNum = 0;
    while (NULL != p)
    {
        ++iListNum;
        p = p->next;
    }

    // 如果删除的是头结点，直接另头结点指向第二个结点
    if (n == iListNum)
    {
        head = head->next;
        return head;
    }

    p = head;
    iListNum = iListNum - n;

    // 查找需要删除的结点前面的结点
    int iCout = 1;
    while (iCout < iListNum)
    {
        p = p->next;
        ++iCout;
    }

    // 结点修正
    if (NULL != p->next)
        p->next = p->next->next;
    else
        p = NULL;

    return head;
}
