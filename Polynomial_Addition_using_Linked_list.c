#include<stdio.h>
#include<stdlib.h>
struct polynode
{
    double coeff;
    int exp;
    struct polynode* link;
};
typedef struct polynode* polyptr;
polyptr insertend(polyptr first,double c,int e)
{
    polyptr p,temp;
    p=(polyptr)malloc(sizeof(struct polynode));
    p->coeff=c;
    p->exp=e;
    if(first==NULL)
    {
        p->link=NULL;
        first=p;
    }
    else
    {
        temp=first;
        p->link=NULL;
        while(temp->link!=NULL)
            temp=temp->link;
        temp->link=p;
    }
    return first;
}
polyptr readpoly(polyptr first)
{
    double c;
    int e;
    printf("Enter the polynomial:\n");
    scanf("%lf %d",&c,&e);
    while(c!=0)
    {
        first=insertend(first,c,e);
        scanf("%lf %d",&c,&e);
    }
    return first;
}
void writepoly(polyptr first)
{
    polyptr temp;
    temp=first;
    while(temp->link!=NULL)
    {
        printf("%.2lf.x^%d + ",temp->coeff,temp->exp);
		temp=temp->link;
    }
    printf("%.2lf.x^%d \n",temp->coeff,temp->exp);
}
polyptr addpoly(polyptr p1,polyptr p2)
{
    polyptr p3,t1,t2,x;
    t1=p1;
    t2=p2;
    p3=NULL;
    while(t1!=NULL&&t2!=NULL)
    {
        if(t1->exp>t2->exp)
        {
            p3=insertend(p3,t1->coeff,t1->exp);
            t1=t1->link;
        }
        else if(t1->exp<t2->exp)
        {
            p3=insertend(p3,t2->coeff,t2->exp);
            t2=t2->link;
        }
        else
        {
            p3=insertend(p3,t2->coeff+t1->coeff,t2->exp);
            t1=t1->link;
            t2=t2->link;
        }
    }
    while(t1!=NULL)
    {
        p3=insertend(p3,t1->coeff,t1->exp);
        t1=t1->link;
    }
    while(t2!=NULL)
    {
        p3=insertend(p3,t2->coeff,t2->exp);
        t2=t2->link;
    }
    return p3;
}
polyptr mulpoly(polyptr p1,polyptr p2)
{
    polyptr p4,temp,t1,t2;
    temp=NULL;
    double c;
    int e;
    t1=p1;
    p4=NULL;
    while(t1!=NULL)
    {
        t2=p2;
        temp=NULL;
        while(t2!=NULL)
        {
            c=t1->coeff*t2->coeff;
            e=t1->exp+t2->exp;
            temp=insertend(temp,c,e);
            t2=t2->link;
        }
        p4=addpoly(p4,temp);
        t1=t1->link;
    }
    return p4;
}
main()
{
    polyptr p1,p2,p3,p4;
    p1=NULL;
    p2=NULL;
    p1=readpoly(p1);
    p2=readpoly(p2);
    writepoly(p1);
    writepoly(p2);
    p3=addpoly(p1,p2);
    writepoly(p3);
    p4=mulpoly(p1,p2);
    writepoly(p4);
}
