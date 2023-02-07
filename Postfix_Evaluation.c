#include<stdio.h>
#include<string.h>
#include<math.h>
#define max 15
int s[max],top=-1;
void push(int x)
{
 top++;
 s[top]=x;
}
 int pop()
{
 int x;
 x=s[top];
 top--;
 return x;
}
int operation(char c,int a,int b)
{
 if(c=='+')return a+b;
if(c=='-')return a-b;
if(c=='*')return a*b;
if(c=='/')return a/b;
if(c=='^')return pow(a,b);
}
void main()
{
 char exp[20],ch;
 int op1,op2,res,i=0;
 printf("Enter postfix exp:");
gets(exp);
while(exp[i]!='\0')
{ 
 if(isalnum(exp[i]))
 {
  push((exp[i])-'0');
 }
 else
 {
  op1=pop();
  op2=pop();
  res=operation(exp[i],op2,op1);
  push(res);
 }
i++;
}
res=pop();
printf("result=%d",res);
}
