#include <stdio.h>
#include <stdlib.h>

// Creating a Structure
struct ListNode
{
    int val;
    struct ListNode *next;
};

void traversal(struct ListNode *ptr)
{ // Struct ListNode Type ka Pointer mtlb jo Pointer Struct ListNode ko Point karra he
    while (ptr != NULL)
    {
        printf("element: %d \n", ptr->val);
        ptr = ptr->next;
    }
}

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    // Guard against NULL inputs
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    struct ListNode *temp1 = list1;
    struct ListNode *temp2 = list2;
    struct ListNode *list3;
    list3 = NULL;
    struct ListNode *temp = list3;

    while (temp1 != NULL && temp2 != NULL)
    {

        struct ListNode *newListNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (temp1->val < temp2->val)
        {
            newListNode->val = temp1->val;
            temp1 = temp1->next;
        }
        else
        {
            newListNode->val = temp2->val;
            temp2 = temp2->next;
        }
        newListNode->next = NULL;

        if (list3 == NULL)
        {
            list3 = newListNode;
            temp = list3;
        }
        else
        {
            temp->next = newListNode;
            temp = newListNode;
        }
    }
    // Append remaining ListNodes
    if (temp1 != NULL)
        temp->next = temp1;
    if (temp2 != NULL)
        temp->next = temp2;
    traversal(list3);
    return list3;
}
int main(int argc, char const *argv[])
{
    struct ListNode *head, *second, *third, *fourth;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    second = (struct ListNode *)malloc(sizeof(struct ListNode));
    third = (struct ListNode *)malloc(sizeof(struct ListNode));
    fourth = (struct ListNode *)malloc(sizeof(struct ListNode));

    head->val = 2;
    head->next = second;
    second->val = 4;
    second->next = third;
    third->val = 5;
    third->next = fourth;
    fourth->val = 6;
    fourth->next = NULL;

    struct ListNode *head1, *second1, *third1, *fourth1;
    head1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    second1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    third1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    fourth1 = (struct ListNode *)malloc(sizeof(struct ListNode));

    head1->val = 1;
    head1->next = second1; // ✅
    second1->val = 4;
    second1->next = third1; // ✅
    third1->val = 6;
    third1->next = fourth1; // ✅
    fourth1->val = 7;
    fourth1->next = NULL;

    mergeTwoLists(head, head1);
    return 0;
}