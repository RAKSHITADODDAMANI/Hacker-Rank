///Q)Write a modular C program to perform the following operations using CSLL.
///a) Insert N data values at the end of the list.
///b) Display the CSLL.
///c) Delete 1 node from end of the CSLL.
///d) Delete 1 node from front of the CSLL.
///Finally, display the updated CSLL.
///Input Format
///First line is N- number of nodes for insert at end.
///Second line is N data values.
///Constraints
///N >= 1.
///Output Format
///Display CSLL.
///Display updated CSLL.
///Sample Input 0
///7
///10 20 30 40 65 69 70
///Sample Output 0
///Circular list is: 10 20 30 40 65 69 70
///Final circular list is: 20 30 40 65 69
///Sample Input 1
///0
///Sample Output 1
///Invalid input
///Sample Input 2
///2
///54 6
///Sample Output 2
///Circular list is: 54 6
///Final circular list is: Empty.

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int e;
    struct node *next;
};
struct node * addnode(struct node * );
struct node * deletebeg(struct node *);
struct node * deleteend(struct node *);
struct node * getnode();
void display(struct node *);
int main() {
    struct node *head=NULL;
    int N,i;
    scanf("%d",&N);
    if(N<=0)
    {
        printf("Invalid input");
        exit(0);
    }
    for(i=0;i<N;i++)
    {
        head=addnode(head);
    }
    printf("Circular list is: ");
    display(head);
    head=deletebeg(head);
    head=deleteend(head);
    printf("\n");
    printf("\nFinal circular list is: ");
    display(head);
}
struct node * addnode(struct node *head )
{
    struct node * newnode=getnode(),*cur=head;
    if(head==NULL)
        head=newnode;
    else
    {
        newnode->next=head->next;
        cur->next=newnode;
        head=newnode;
    }
    return head;
}
struct node * getnode()
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&newnode->e);
    newnode->next=newnode;
    return newnode;
}
struct node * deletebeg(struct node *head)
{
    if(head==NULL)
        return NULL;
    else if(head->next==head)
    {
        free(head);
        return NULL;
    }
    else
    {
        struct node *cur=head->next;
        head->next=cur->next;
        free(cur);
        return head;
    }
}
struct node * deleteend(struct node *head)
{
    struct node *cur=head->next,*pre=NULL;
    if(head->next==head)
    {
        free(head);
        return NULL;
    }
    while(cur->next!=head->next)
    {
        pre=cur;
        cur=cur->next;
    }
    pre->next=cur->next;
    free(cur);
    head=pre;
    return head;
}
void display(struct node *head)
{
    struct node *cur;
    if(head==NULL)
        printf("Empty.");
    else
    {
        cur=head->next;
    do
    {
        printf("%d ",cur->e);
        cur=cur->next;
    }while(cur!=head->next);
    }
}
