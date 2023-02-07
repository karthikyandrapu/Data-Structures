#include<stdio.h>
#include<stdlib.h>
#define size 20
int cq[size];
int rear=0;
int front=0;
int cqempty()
{
    if(front==rear)
        return -1;
    else
        return 0;
}
int cqfull()
{
    rear=(rear+1)%size;
    if(front==rear)
    {
        if(rear=0)
            rear=size-1;
        else
            rear=rear-1;
        return 1;
    }
    else
        return 0;
}
void push(int x)
{
    if(cqfull())
        printf("queue is full\n");
    else
        cq[rear]=x;
}
int pop()
{
    int x;
    if(cqempty())
    {
        printf("queue is empty\n");
        return -1;
    }
    else
    {
        front=(front+1)%size;
        x=cq[front];
        return x;
    }
}
void display()
{
    int i;
    printf("Elements in queue are:");
    if(cqempty())
        printf("queue is empty\n");
    else if(front<rear)
    {
        for(i=front+1; i<=rear; i++)
            printf("%d ",cq[i]);
    }
    else
    {
        for(i=front+1; i<=size-1; i++)
            printf("%d  ",cq[i]);
        for(i=0; i<=rear; i++)
            printf("%d ",cq[i]);
    }
    printf("\n");
}
int main()
{
    int ch,x;
    while(1)
    {
        printf("1.Insertion  2.Deletion 3.Display 4.Exit\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter element:");
            scanf("%d",&x);
            push(x);
            printf("\n");
            break;
        case 2:
            x=pop();
            if(x!=-1)
                printf("popped element is %d\n",x);
            printf("\n");
            break;
        case 3:
            display();
            printf("\n");
            break;
        case 4:
            exit(0);
        }
    }
}
