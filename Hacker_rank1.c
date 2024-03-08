///Q) Write a modular c program to create a SLL to store computer details by performing the following operations:
///Computer details: Company name, model, processor name, ram in GB, storage in GB.
///a) Create a SLL using insert at end operation.
///b) Display SLL.
///c) Insert a new computer details at specified position(position number starts from 1) and display updated SLL.
///d) Delete the first computer details and display the updated SLL.
///Input Format
///First line is N - number of computer details to store.
///Next N lines is computer details.
///Last but one line is position.
///Last line is computer details to insert at specified position.
///Constraints
///N>=1.
///If position is greater than count of nodes in the SLL, insert the computer details at the end of the list.
///Output Format
///Display SLL.
///Display SLL after insertion.
///Display SLL after deletion.

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char company[50];
    char model[50];
    char processor_n[50];
    int ram;
    int storage;
    struct node *next;
};
struct node * delete_begin(struct node *head);
struct node * add_node(struct node *,int);
struct node * add(struct node *,int);
struct node * getnode();
struct node * createlist(struct node *head,int n);
void display(struct node *);
int main() {
    int n,pos;
    struct node *head=NULL;
    scanf("%d",&n);
    if(n<=0)
    {
        printf("Invalid input");
    }
    else
    {
        head=createlist(head,n);
        printf("List is:\n");
        display(head);
        scanf("%d",&pos);
        head=add(head,pos);
        printf("\nList after insertion is:\n");
        display(head);
        head=delete_begin(head);
        printf("\nList after deletion is:\n");
        display(head);
    }
}
void display(struct node *head)
{
    struct node *cur=head;
    while(cur!=NULL)
    {
        printf("%s\t%s\t%s\t%d\t%d\n",cur->company,cur->model,cur->processor_n,cur->ram,cur->storage);
        cur=cur->next;
    }
}
struct node * getnode()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    scanf("%s%s%s%d%d",newnode->company,newnode->model,newnode->processor_n,&newnode->ram,&newnode->storage);
    newnode->next=NULL;
    return newnode;
}
struct node * add(struct node *head,int pos)
{
    struct node *newnode=getnode();
    int i;
    if(pos<=1 || head==NULL)
     {
         newnode->next=head;
         head=newnode;
         return head;
     }
    struct node *cur=head;
    for(i=1;i<pos-1 && cur->next!=NULL;i++)
      {
          cur= cur->next;
      }
      newnode->next=cur->next;
      cur->next=newnode;
      return head;
}
struct node * createlist(struct node *head,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        head=add_node(head,i);
    }
    return head;
}

struct node * add_node(struct node *head,int pos)
{
     int i;
     struct node *current=head,*newnode=getnode();
     if(pos<=0 || head==NULL)
     {
         newnode->next=head;
         head=newnode;
         return head;
     }
      for(i=0;i<pos-1 && current->next!=NULL;i++)
      {
          current= current->next;
      }
      newnode->next=current->next;
      current->next=newnode;
      return head;
}
struct node * delete_begin(struct node *head)
{
   struct node *current=head;
   head=head->next;
   free(current);
   return head;
}
