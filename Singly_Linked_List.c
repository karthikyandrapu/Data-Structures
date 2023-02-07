#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node 
{
  int data;
  struct node*link;
};
typedef struct node*nptr;

nptr insert_begin(nptr head, int x) 
{
  nptr p;
  p=(nptr)malloc(sizeof(struct node));
  p->data=x;
  if(head==NULL)
  {
    p->link=NULL;
    head=p;
  } 
  else
  {
    p->link=head;
    head=p;
  }
  return head;
}

nptr insert_end(nptr head,int x)
{
  nptr p,t;
  p=(nptr)malloc(sizeof(struct node));
  p->data=x;
  p->link=NULL;
  if(head==NULL)
  {
    head=p;
    return p;
  }
  else
  {
    t=head;
    while(t->link!=NULL)
	{
      t=t->link;
    }
    t->link=p;
  }
  return head;
}

nptr insert_pos(nptr head,int x,int pos)
{
  nptr p,t;
  int c=1;
  p=(nptr)malloc(sizeof(struct node));
  p->data=x;
  if(pos==1)
    head=insert_begin(head,x);
  else
  {
    t=head;
    while(t!=NULL&c<pos-1)
	{
      t=t->link;
      c++;
    }
    if(t==NULL)
	{
      printf("Insertion not possible\n");
      return NULL;
    }
    p->link=t->link;
    t->link=p;
  }
  return head;
}

nptr delete_begin(nptr head)
{
  nptr temp;
  if(head==NULL)
  {
    printf("Deletion is not possible\n");
  }
  else 
  {
    temp=head;
    head=head->link;
    printf("Deleted Element is %d\n",temp->data);
    free(temp);
  }
  return head;
}

nptr delete_end(nptr head)
{
  nptr temp,p;
  if(head==NULL)
  {
    printf("Deletion is not possible\n");
  }
  else
  {
    temp=head;
    while(temp->link!=NULL)
	{
      p=temp;
      temp=temp->link;
    }
    p->link=NULL;
    printf("Deleted Element is %d\n",temp->data);
    free(temp);
  }
  return head;
}

nptr delete_pos(nptr head,int pos)
{
  nptr p,t,temp;
  int c=1;
  if(pos==1)
    head=delete_begin(head);
  else
  {
    t=head;
    while(t!=NULL&c<=pos-1)
	{
      p=t;
      t=t->link;
      c++;
    }
    if(t==NULL)
	{
      printf("deletion not possible\n");
      return NULL;
    }
    p->link=t->link;
    t->link=NULL;
    printf("deleted element is %d\n",t->data);
    free(t);
  }
  return head;
}

void traverse(nptr head)
{
  nptr temp;
  if(head==NULL)
    printf("List is Empty\n");
  else
  {
    temp=head;
    while(temp->link!=NULL)
	{
      printf("%d->",temp->data);
      temp=temp->link;
    }
    printf("%d->NULL\n",temp->data);
  }
}

void search(nptr head,int x)
{
  nptr temp=head;
  int i=1;
  bool flag=false;
  if(head==NULL)
  {
    printf("List is empty\n");
  }
  else
  {
    while(temp!=NULL)
	{
      if(temp->data==x)
	  {
        flag=true;
        break;
      }
      i++;
      temp=temp->link;
    }
  }
  if (flag)
    printf("Element is present at postion %d\n",i);
  else
    printf("Element is not found\n");
}

void main()
{
  nptr head=NULL;
  int x,pos,ch;
  while (1)
  {
    printf("1.Insert Begin\n2.Insert end\n3.Insert pos\n4.Delete begin\n5.Delete end \n6.Delete pos \n7.Traverse\n8.Search\n9.Exit\n\n");
    printf("Enter Choice:");
    scanf("%d",&ch);
    switch (ch)
	{
    case 1:
      printf("Enter Element:");
      scanf("%d",&x);
      head=insert_begin(head,x);
      printf("\n");
      break;
    case 2:
      printf("Enter Element:");
      scanf("%d",&x);
      head=insert_end(head,x);
      printf("\n");
      break;
    case 3:
      printf("Enter the position to insert:");
      scanf("%d",&pos);
      printf("Enter Element:");
      scanf("%d",&x);
      head=insert_pos(head,x,pos);
      printf("\n");
      break;
    case 4:
      head=delete_begin(head);
      printf("\n");
      break;
    case 5:
      head=delete_end(head);
      printf("\n");
      break;
    case 6:
      printf("Enter the position to delete:");
      scanf("%d",&pos);
      head=delete_pos(head,pos);
      printf("\n");
      break;
    case 7:
      traverse(head);
      printf("\n");
      break;
    case 8:
      printf("Enter the element to be searched:");
      scanf("%d",&x);
      search(head,x);
      printf("\n");
      break;
    case 9:
      exit(0);
    }
  }
}
