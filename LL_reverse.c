#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void LL_traversal(struct Node *ptr)
{
    printf("the elements are:\n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *inserAtFirst(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;

    return newNode;
}

struct Node *reverse(struct Node *head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = head->data;
    ptr->next = NULL;
    struct Node *p = head->next;
    while (p != NULL)
    {
        ptr = inserAtFirst(ptr, p->data);
        p = p->next;
    }
    return ptr;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // alloted in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 18;
    third->next = fourth;

    fourth->data = 63;
    fourth->next = NULL;

    printf("before ");
    LL_traversal(head);
    head = reverse(head);
    printf("after ");
    LL_traversal(head);

    return 0;
}