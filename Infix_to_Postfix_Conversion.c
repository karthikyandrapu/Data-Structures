#include<stdio.h>
#define size 15
char s[size];
int top;
void push(char x)
{
    top++;
    s[top]=x;
}
char pop()
{
    char x;
    x=s[top];
    top--;
    return x;
}
int icp(char x)
{
    if(x=='^')return 4;
    if(x=='*'||x=='/')return 3;
    if(x=='+'||x=='-')return 2;
}
int isp(char x)
{
    if(x=='^')return 4;
    if(x=='*'||x=='/')return 3;
    if(x=='+'||x=='-')return 2;
    if(x=='(')return 1;
    if(x=='#')return 0;
}
int isoperator(char x)
{
    if(x=='^'||x=='*'||x=='/'||x=='+'||x=='-')
        return 1;
    else
        return 0;
}
void main()
{
    char exp[50],ch;
    int i=0;
    top=-1,
    printf("Enter infix exp:");
    gets(exp);
    push('#');
    while(exp[i]!='\0')
    {
        if(isalnum(exp[i]))
            putchar(exp[i]);
        else if(exp[i]=='(')
            push(exp[i]);
        else if(isoperator(exp[i]))
        {
            while(isp(s[top])>=icp(exp[i]))
            {
                ch=pop();
                putchar(ch);
            }
            push(exp[i]);
        }
        else
        {
            while(s[top]!='(')
            {
                ch=pop();
                putchar(ch);
            }
            ch=pop();
        }
        i++;
    }
    while(s[top]!='#')
    {
        ch=pop();
        putchar(ch);
    }
}
