///Q) Write a modular C program to perform the following operations using CSLL.\
a) Insert N data values at the front of the list.\
b) Display the CSLL.\
c) Insert 1 node at postion P in the exisitng CSLL.\
d) Delete 1 node from position Q in the existing CSLL.\
Finally, display the updated CSLL.\
Input Format\
First line is N- number of nodes for insert at front.\
Second line is N data values.\
Third line is position P and data to be present in the node.\
Fourth line is position Q.\
Constraints\
N >= 1.\
P and Q are positive values.\
Output Format\
Display the CSLL.\
Display CSLL after insertion.\
Display CSLL after deletion.\
Sample Input 0\
5\
457 123 650 213 666\
2 349\
4\
Sample Output 0\
Circular list is: 666 213 650 123 457\
Circular list after insertion is: 666 349 213 650 123 457\
Circular list after deletion is: 666 349 213 123 457\
Sample Input 1\
-2\
ample Output 1\
Invalid input\
Sample Input 2\
3\
11 22 33\
1 44\
5\
Sample Output 2\
Circular list is: 33 22 11\
Circular list after insertion is: 44 33 22 11\
Circular list after deletion is: 44 33 22 11\
Sample Input 3\
4\
10 20 30 40\
8 50\
1\
Sample Output 3\
Circular list is: 40 30 20 10\
Circular list after insertion is: 40 30 20 10 50\
Circular list after deletion is: 30 20 10 50

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node * getnode()
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=newnode;
    return newnode;
}
void display(struct node *tail)
{
    struct node *cur;
    if(tail==NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    cur=tail->next;
    do
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }while(cur!=tail->next);
}
struct node * add_pos(struct node *tail,int pos)
{
    struct node *newnode=getnode();
    if(tail==NULL)
    {
        tail=newnode;
        return tail;
    }
    if(pos<=1)
    {
        newnode->next=tail->next;
        tail->next=newnode;
        return tail;
    }
    struct node *cur=tail->next;
    int i;
    for(i=1;i<pos-1&&cur!=tail;i++)
    {
        cur=cur->next;
    }
    newnode->next=cur->next;
    cur->next=newnode;
    if(cur==tail)
    {
        tail=newnode;
    }
    return tail;
}
struct node * add_beg(struct node *tail)
{
    struct node *newnode=getnode();
    if(tail==NULL)
    {
        tail=newnode;
        return tail;
    }
    newnode->next=tail->next;
    tail->next=newnode;
    return tail;
}
struct node * delete_pos(struct node *tail,int pos)
{
    struct node *cur=tail->next,*pre=NULL;
    int i;
    if(tail==cur)
    {
        free(cur);
        tail=NULL;
        return tail;
    }
    if(pos<=1)
    {
        tail->next=cur->next;
        free(cur);
        return tail;
    }
    for(i=1;i<pos && cur!=tail;i++)
    {
        pre=cur;
        cur=cur->next;
    }
    pre->next=cur->next;
    if(cur==tail)
    {
        tail=pre;
    }
    free(cur);
    return tail;
}
int main()
{
    struct node *tail=NULL;
    int pos,n,m;
    scanf("%d",&n);
    if(n<=0)
    {
        printf("Invalid input\n");
        exit(0);
    }
    for(int i=0;i<n;i++)
    {
        tail=add_beg(tail);
    }
    printf("Circular list is: ");
    display(tail);
    printf("\n");
    scanf("%d",&pos);
    tail=add_pos(tail,pos);
    printf("\nCircular list after insertion is: ");
    display(tail);
    printf("\n");
    scanf("%d",&m);
    if(m<n)
      tail=delete_pos(tail,m);
    printf("\nCircular list after deletion is: ");
    display(tail);
    return 0;
}
