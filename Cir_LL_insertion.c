#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LL_traversal(struct Node *head)
{
    struct Node *ptr = head;
    printf("the elements are:\n");
    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next != head)
        p = p->next;
    // at this point p points to the last node
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main()
{

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 25;
    third->next = fourth;

    fourth->data = 50;
    fourth->next = head;

    head = insertAtFirst(head, 80);
    LL_traversal(head);
    return 0;
}