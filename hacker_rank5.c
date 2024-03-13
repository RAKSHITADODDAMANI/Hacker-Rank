///Q) Write a modular C program to check an infix expression has balanced brackets. Balanced brackets represents that an infix expression should have an appropriate opening and closing bracket.
///An open '(' bracket should have an appropriate close ')' in its place.
///Similarly, an open '{' bracket should have an appropriate close '}' in its place.
///Also an open '[' bracket should have an appropriate close ']' in its place.
///Input Format
///Input is an infix expression in the form of string.
///Constraints
///Stack size shoud be minimum 1 and maximum length of an expression.
///Output Format
///Print message as Valid expression or Invalid expression.
///Sample Input 0
///({a+b-c})
///Sample Output 0
///Valid expression.
///Sample Input 1
///if(a>b){printf("a\n");}
///Sample Output 1
///Valid expression.
///Sample Input 2
///(((1+2+3+4/5))
///Sample Output 2
///Invalid expression.

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct stack
{
    char e[50];
    int top;
};
void init(struct stack *);
void push(struct stack *,char );
char  pop(struct stack *);
int isEmpty(struct stack *s);
int peak(struct stack *s);
void display(struct stack *s);
int size(struct stack *s);
main()
{
    struct stack s;
    int ch,si,i;
    init(&s);
    char c;
    char eq[50];
    gets(eq);
    for(i=0;eq[i]!='/0' && i<strlen(eq);i++)
    {
    if(eq[i]=='('||eq[i]=='{'||eq[i]=='[')
    {
        push(&s,eq[i]);
    }
    else if(eq[i]==')'||eq[i]=='}'||eq[i]==']')
    {
        c=pop(&s);
        if(eq[i]=='(' && c!=')')
        {
            printf("Invalid expression.\n");
        }
        else if(eq[i]=='{' && c!='}')
        {
            printf("Invalid expression.\n");
        }
        else if(eq[i]=='[' && c!=']')
        {
            printf("Invalid expression.\n");
        }
    }
    }
    ch=isEmpty(&s);
    if(ch==1)
    {
        printf("Valid expression.\n");
    }
    else
    {
        printf("Invalid expression.\n");
    }

}
void init(struct stack *s)
{
    s->top=-1;
}
void push(struct stack *s,char c)
{
    if(isFull(s))
    {
        return 0;
    }
    else
    {
        s->top++;
        s->e[s->top]=c;
    }
}
char  pop(struct stack *s)
{
    char ele;
    if(isEmpty(&s))
    {
        return 0;
    }
    else
    {
        ele=s->e[s->top];
        s->top--;
        return ele;
    }
}
int isEmpty(struct stack *s)
{
    if(s->top==-1)
    {
        return 1;
    }
    else
        return 0;
}
int isFull(struct stack *s)
{
    int si=size(&s);
    si--;
    if(s->top==si)
    {
        return 1;
    }
    else
        return 0;
}
int size(struct stack *s)
{
    int i=(s->top+1);
    return i;
}
