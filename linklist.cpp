#include "linklist.h"
#include <stdio.h>
#include <stdlib.h>

void LinkListInit(LinkNode** head)
{
    if(head == NULL)
    {
        return;
    }
    if(*head == NULL)
    {
        return;
    }
    *head = NULL;
}

void LiskListPrint(LinkNode* head)
{
    LinkNode* cur = head;
    while(cur != NULL)
    {
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("\n");
}

LinkNode* CreateTreeNode(LinkType value)
{
    LinkNode* new_node = (LinkNode*)malloc(sizeof(LinkNode));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

LinkNode* LinkListPushBack(LinkNode** head,LinkType value)
{
    if(head == NULL)
    {
        return NULL;
    }
    LinkNode* new_node = CreateTreeNode(value);
    if(*head == NULL)
    {
        (*head) = new_node;
        return new_node;
    }
    LinkNode* cur = *head;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = new_node;
    return new_node;
}

void LinkListReversePrint(LinkNode* head)//逆序打印单链表.
{
    if(head == NULL)
    {
        return;
    }
    LinkListReversePrint(head->next);
    printf("%d ",head->data);
}

void LinkListInsertBefore(LinkNode** head, LinkNode* pos, LinkType value)//不允许遍历链表, 在 pos之前插入
{
    if(head == NULL)
    {
        return;
    }
    if(*head == NULL)
    {
        LinkListPushBack(head,value);
        return;
    }
    LinkNode* new_node = CreateTreeNode(pos->data);
    pos->data = value;
    new_node->next = pos->next;
    pos->next = new_node;
    return;
}

void DestoryLinkNode(LinkNode* to_delete)
{
    free(to_delete);
}

LinkNode* JosephCycle(LinkNode* head, size_t food)//约瑟夫环
{
    if(head == NULL)
    {
        return NULL;
    }
    LinkNode* cur = head;
    while(cur->next != cur)
    {
        size_t count = 1;
        while(count != food)
        {
            cur = cur->next;
            ++count;
        }
        printf("die : %d\n",cur->data);
        LinkNode* to_delete = cur->next;
        cur->data = to_delete->data;
        cur->next = to_delete->next;
        DestoryLinkNode(to_delete);
    }
    return cur;
}

void LinkListReverse(LinkNode** head)//单链表逆置
{
    if(head == NULL || *head == NULL)
    {
        return;
    }
    if((*head)->next == NULL)
    {
        return;
    }
    LinkNode* prev = *head;
    LinkNode* cur = (*head)->next;
    while(cur != NULL)
    {
        LinkNode* tail = cur->next;
        cur->next = (*head);
        prev->next = tail;
        (*head) = cur;
        cur = tail;
    }
    return;
}

void Swap(LinkType* a,LinkType* b)
{
    LinkType tmp = *a;
    *a = *b;
    *b = tmp;
}

void LinkListBubbleSort(LinkNode* head)//单链表的冒泡排序
{
    if(head == NULL)
    {
        return;
    }
    if(head->next == NULL)
    {
        return;
    }
    LinkNode* cur = head;
    LinkNode* tail = head;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
    for(; cur->next != NULL; cur = cur->next)
    {
        LinkNode* bound = head;
        for(; bound->next != tail;bound = bound->next)
        {
            if(bound->data > bound->next->data)
            {
                Swap(&bound->data,&bound->next->data);
            }
        }
        if(bound->data > tail->data)
        {
            Swap(&bound->data,&tail->data);
        }
        tail = bound;
    }
}

LinkNode* LinkListMerge(LinkNode* head1, LinkNode* head2)//将两个有序链表, 合并成一个有序链表
{
    if(head1 == NULL || head2 == NULL)
    {
        return NULL;
    }
    LinkNode* new_head = NULL;
    LinkNode* new_tail = NULL;
    LinkNode* cur1 = head1;
    LinkNode* cur2 = head2;
    if(cur1->data < cur2->data)
    {
        new_head = cur1;
        cur1 = cur1->next;
        new_tail = new_head;
    }
    else
    {
        new_head = cur2;
        cur2 = cur2->next;
        new_tail = new_head;
    }
    while(cur1 != NULL && cur2 != NULL)
    {
        if(cur1->data < cur2->data)
        {
            new_tail->next = cur1;
            cur1 = cur1->next;
        }
        else
        {
            new_tail->next = cur2;
            cur2 = cur2->next;
        }
        new_tail = new_tail->next;
    }
    while(cur1 != NULL && cur2 == NULL)
    {
        new_tail->next = cur1;
        new_tail = new_tail->next;
        cur1 = cur1->next;
    }
    while(cur1 == NULL && cur2 != NULL)
    {
        new_tail->next = cur2;
        new_tail = new_tail->next;
        cur2 = cur2->next;
    }
    return new_head;
}

LinkNode* FindMidNode(LinkNode* head)//找到链表中间的节点
{
    if(head == NULL)
    {
        return NULL;
    }
    if(head->next == NULL)
    {
        return NULL;
    }
    LinkNode* quick = head;
    LinkNode* slow = head;
    while(quick->next != NULL && quick->next->next != NULL)
    {
        quick = quick->next->next;
        slow = slow->next;
    }
    return slow;
}

LinkNode* FindLastKNode(LinkNode* head, size_t K)//找到倒数第 K 个节点.
{
    if(head == NULL)
    {
        return NULL;
    }
    if(K == 0)
    {
        return NULL;
    }
    LinkNode* cur = head;
    size_t count = 0;
    while(cur != NULL)
    {
        cur = cur->next;
        ++count;
    }
    if(K > count)
    {
        return NULL;
    }
    cur = head;
    size_t i = 0;
    for(; i < K - 1; ++i)
    {
        cur = cur->next;
    }
    LinkNode* slow = head;
    while(cur->next != NULL)
    {
        cur = cur->next;
        slow = slow->next;
    }
    return slow;
}

void EraseLastKNode(LinkNode** head, size_t K)//删除倒数第K个节点
{
    if(head == NULL || *head == NULL)
    {
        return;
    }
    LinkNode* find_node = FindLastKNode(*head,K);
    if(find_node != NULL)
    {
        if(find_node->next != NULL)
        {
            LinkNode* to_delete = find_node->next;
            find_node->data = to_delete->data;
            find_node->next = to_delete->next;
            DestoryLinkNode(to_delete);
            return;
        }
        else
        {
            LinkNode* cur = *head;
            while(cur->next != find_node)
            {
                cur = cur->next;
            }
            cur->next = NULL;
            DestoryLinkNode(find_node);
            return;
        }
    }
    return;
}

LinkNode* HasCycle(LinkNode* head)//判定单链表是否带环. 如果带环返回交点
{
    if(head == NULL)
    {
        return NULL;
    }
    if(head->next == NULL)
    {
        return NULL;
    }
    LinkNode* quick = head;
    LinkNode* slow = head;
    while(quick->next->next != NULL)
    {
        quick = quick->next->next;
        slow = slow->next;
        if(slow == quick)
        {
            return slow;
        }
    }
    return NULL;
}

size_t GetCycleLen(LinkNode* head)//如果链表带环, 求出环的长度
{
    if(head == NULL)
    {
        return 0;
    }
    LinkNode* point = HasCycle(head);
    if(point == NULL)
    {
        return 0;
    }
    LinkNode* cur = point->next;
    size_t count = 1;
    while(cur != point)
    {
        ++count;
        cur = cur->next;
    }
    return count;
}

LinkNode* GetCycleEntry(LinkNode* head)  
{  
    LinkNode* cur = HasCycle(head);  
    if (cur == NULL)  
    {//没有环  
        return NULL;  
    }  
    int len = GetCycleLen(head);
    LinkNode* cur1 = head;
    LinkNode* cur2 = head;
    while(len--)
    {
        cur1 = cur1->next;
    }
    while(cur1 != cur2)
    {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}

size_t LinkSize(LinkNode* head)
{
    if(head == NULL)
    {
        return 0;
    }
    size_t count = 0;
    LinkNode* cur = head;
    while(cur)
    {
        cur = cur->next;
        ++count;
    }
    return count;
}

LinkNode* HasCross(LinkNode* head1, LinkNode* head2)//判定两个链表是否相交, 并求出交点
{
    if(head1 == NULL || head2 == NULL)
    {
        return NULL;
    }
    size_t size1 = LinkSize(head1);
    size_t size2 = LinkSize(head2);
    size_t size = 0;
    LinkNode* cur1 = NULL;
    LinkNode* cur2 = NULL;
    if(size1 > size2)
    {
        size = size1 - size2;
        cur1 = head1;
        cur2 = head2;
    }
    else
    {
        size = size2 - size1;
        cur1 = head2;
        cur2 = head1;
    }
    while(size--)
    {
        cur1 = cur1->next;
    }
    while(cur1 != NULL && cur2 != NULL)
    {
        if(cur1 == cur2)
        {
            return cur1;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return NULL;
}
