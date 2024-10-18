#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *ptr)
{
    if (ptr->r == ptr->size - 1)
        return 1;
    else
        return 0;
}

int isEmpty(struct queue *ptr)
{
    if (ptr->r == ptr->f)
        return 1;
    else
        return 0;
}

void enqueue(struct queue *ptr, int val)
{
    if (isFull(ptr))
        printf("the queue is full");
    else
    {
        ptr->r++;
        ptr->arr[ptr->r] = val;
    }
}

int dequeue(struct queue *ptr)
{
    int a = -1;
    if (isEmpty(ptr))
        printf("the que is empty");
    else
    {
        ptr->f++;
        a = ptr->arr[ptr->f];
    }
    return a;
}

int main()
{
    struct queue q;
    q.size = 100;
    q.f = q.r = 1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 22);

    printf("dequeueing elements\n");
    printf("element : %d\n", dequeue(&q));
    printf("element : %d\n", dequeue(&q));
    printf("element : %d\n", dequeue(&q));

    return 0;
}