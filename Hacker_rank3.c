///Q)Write a modular C Program to perform the following operations using Circular Doubly Linked List.
///a) Insert at the front of the CDLL.
///b) Display the CDLL in forward direction.
///c) Display the CDLL in reverse direction.
///Input Format
///First line is N - number of nodes to be created in CDLL.
///Second line is N data values.
///Constraints
///N should be positive.
///Output Format
///Display CDLL in forward direction.
///Display CDLL in reverse direction.
///Sample Input 0
///5
///1 2 3 4 5
///Sample Output 0
///CDLL in forward direction is:
///5 4 3 2 1
///CDLL in reverse direction is:
///1 2 3 4 5
///Sample Input 1
///0
///Sample Output 1
///Invalid input
///Sample Input 2
///1
///555
///Sample Output 2
///CDLL in forward direction is:
///555
///CDLL in reverse direction is:
///555

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node * addbeg(struct node *);
void display(struct node *);
void display1(struct node *);
struct node * getnode();
int main()
{
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
        head=addbeg(head);
    }
    printf("CDLL in forward direction is:\n");
    display1(head);
    printf("\n");
    printf("\nCDLL in reverse direction is:\n");
    display(head);
}
struct node * addbeg(struct node *head)
{
    struct node *newnode=getnode();
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    newnode->next=head;
    newnode->prev=head->prev;
    head->prev=newnode;
    newnode->prev->next=newnode;
    head=newnode;
    return head;
}
struct node * getnode()
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=newnode;
    newnode->prev=newnode;
    return newnode;
}
void display(struct node *head)
{
    if(head==NULL)
        return 0;
    struct node *cur=head->prev;
    do
    {
        printf("%d ",cur->data);
        cur=cur->prev;
    }while(cur!=head->prev);
}
void display1(struct node *head)
{
    struct node *cur=head;
    if(head==NULL)
        return 0;
    do
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }while(cur!=head);
}
