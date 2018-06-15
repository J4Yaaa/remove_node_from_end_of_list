#include "linklist.h"
#include <iostream>
using namespace std;

LinkNode *removeNthFromEnd(LinkNode *head, int n) {
    if(head == NULL)
    {
        return NULL;
    }
    LinkNode* fast = head;
    LinkNode* slow = head;
    int count = n;
    while(fast != NULL && count--)
    {
        fast = fast->next;
    }
    if(fast == NULL && count == 0)
    {
        if(head->next == NULL)
        {
            delete head;
            return NULL;
        }
        LinkNode* to_delete = head->next;
        head->data = to_delete->data;
        head->next = to_delete->next;
        delete to_delete;
        return head;
    }
    else if(fast == NULL && count > 0)
    {
        return head;
    }
    LinkNode* prev = NULL;
    while(fast != NULL)
    {
        prev = slow;
        fast = fast->next;
        slow = slow->next;

    }
    prev->next = slow->next;
    delete slow;
    return head;

}

int main()
{
    LinkNode* head;
    LinkListInit(&head);
    LinkListPushBack(&head,1);
    LinkListPushBack(&head,2);
    LinkListPushBack(&head,3);
    LinkListPushBack(&head,4);
    LinkListPushBack(&head,5);
    LiskListPrint(head);
    removeNthFromEnd(head,5);
    LiskListPrint(head);
    return 0;
}
