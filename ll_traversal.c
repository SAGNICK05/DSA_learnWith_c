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

    LL_traversal(head);
    // head = insertAtFirst(head, 24);
    // head = insertAtIndex(head, 42, 2);
    head = insertAtEnd(head, 25);
    LL_traversal(head);

    return 0;
}