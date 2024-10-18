#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
        printf("stack overflow! Cannot push %d to stack\n", val);
    else
        ptr->arr[++(ptr->top)] = val;
}

int pop(struct stack *ptr)
{
    int val;
    if (isEmpty(ptr))
    {
        printf("stack underflow! Cannot pop");
        return -1;
    }
    else
    {
        val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("\nstack created successfully\n");

    int n;
    char ch;
    do
    {
        printf("enter stack elements : \n");
        scanf("%d", &n);
        push(s, n);
        printf("do you want to continue (Y/N)\n");
        ch = getch();
    } while (ch == 'y' || ch == 'Y');

    printf("elements present in stack\n");
    while (s->top != -1)
        printf("element : %d\n", pop(s));

    return 0;
}