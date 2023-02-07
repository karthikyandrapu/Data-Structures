#include <stdio.h>
#include <stdlib.h>
#define max 10
int s[max];
int top=-1;
int stackempty()
{
    if (top ==-1)
        return 1;
    else
        return 0;
}
int stackfull()
{
    if(top==max-1)
        return 1;
    else
        return 0;
}
void push (int x)
{
    if (stackfull())
        printf("Stack is full \n");
    else
    {
        top++;
        s[top] = x;
    }
}
int pop()
{
    int x;
    if (stackempty())
    {
        printf(" stack is empty\n");
        return -1;
    }
    else
    {
        x=s[top];
        top--;
        return x;
    }
}

int stacktop()
{
    if (!stackempty())
        return s[top];
    return -1;
}
void main()
{
    int ch,x;
    while (1)
    {
        printf("1. push 2.pop 3.stacktop 4.exit \n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element:");
            scanf("%d", &x);
            push(x);
            printf("\n");
            break;
        case 2:
            x=pop();
            if (x!=-1)
                printf(" popped element is %d\n",x);
            printf("\n");
            break;
        case 3:
            x=stacktop();
            if (x!=-1)
                printf(" Top most element is %d\n",x);
            else
                printf("Stack is Empty\n");
            printf("\n");
            break;
        case 4:
            exit(0);
        }
    }
}
