#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;
};
void doubly_Traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *insert_At_Begain(struct Node *head, int data)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->pre = NULL;
    p->next = head;
    return p;
};

struct Node *insert_At_Index(struct Node *head, int data, int index)
{
    struct Node *r = head->next;
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *q = head;
    p->data = data;
    int i = 1;
    while (i != index - 1)
    {
        q = q->next;
        r = r->next;
        i++;
    }
    p->next = r;
    r->pre = p;
    q->next = p;
    p->pre = q;
    return head;
};
struct Node *insert_At_End(struct Node *head, int data)
{
    struct Node *q = head;
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = p;
    p->pre = q;
    p->next = NULL;
    return head;
};

struct Node *delete_At_Begain(struct Node *head)
{
    struct Node *q = head;
    head = head->next;
    free(q);
    return head;
};
struct Node *delete_At_Index(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    int i = 1;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
};

struct Node *delete_At_End(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
    return head;
};

int main()
{
    int d1, d2, n, d3;
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n4 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *n5 = (struct Node *)malloc(sizeof(struct Node));

    head->pre = NULL;
    head->data = 10;
    head->next = n2;

    n2->pre = head;
    n2->data = 20;
    n2->next = n3;

    n3->pre = n2;
    n3->data = 30;
    n3->next = n4;

    n4->pre = n3;
    n4->data = 40;
    n4->next = n5;

    n5->pre = n4;
    n5->data = 50;
    n5->next = NULL;

    doubly_Traverse(head);

    printf("\n\nEnter The data for the first Node:");
    scanf("%d", &d1);
    head = insert_At_Begain(head, d1);
    doubly_Traverse(head);

    printf("\n\nEnter the index :");
    scanf("%d", &n);
    printf("Enter the data for new Node:");
    scanf("%d", &d2);
    head = insert_At_Index(head, d2, n);
    doubly_Traverse(head);

    printf("\n\nEnter The data for the first Node:");
    scanf("%d", &d3);
    head = insert_At_End(head, d3);
    doubly_Traverse(head);

    printf("\n\nAfter Deleting First Node\n");
    head = delete_At_Begain(head);
    doubly_Traverse(head);

    int i;
    printf("\n\nEnter the Index:");
    scanf("%d", &i);
    printf("After Deleting Index Node:\n");
    head = delete_At_Index(head, i);
    doubly_Traverse(head);

    printf("\n\nAfter Deleting Last Node\n");
    head = delete_At_End(head);
    doubly_Traverse(head);
}