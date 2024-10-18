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

struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    int i;
    struct Node *p = head;
    struct Node *q = head->next;
    for (i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node *deleteAtEnd(struct Node *head)
{
    int i;
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// deleting a node with given value (first instance)
struct Node *deleteAtIndex(struct Node *head, int index, int value)
{
    int i;
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
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

    // linking first and second node
    head->data = 7;
    head->next = second;

    // linking second and third node
    second->data = 11;
    second->next = third;

    // linking third and fourth node
    third->data = 18;
    third->next = fourth;

    // Terminating list at the third node
    fourth->data = 63;
    fourth->next = NULL;
    printf("elements before deleting\n");
    LL_traversal(head);

    printf("elements efter deleting\n");
    // head = deleteFirst(head);
    // head = deleteAtIndex(head, 2);
    head = deleteAtEnd(head);
    LL_traversal(head);

    return 0;
}