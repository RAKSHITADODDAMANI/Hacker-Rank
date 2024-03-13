///Q) A company conducts interviews in two different colleges to select the brilliant students for the Software Engineer job. They have the list of students who appeared for an interview in two different lists. But the HR of the company demands to make it a single list after the interview is completed in both the colleges. Apply problem solving framework and write a modular c program to merge the two lists of students. Also display the selected students of both the colleges for the job who have scored more than 70 points out of 100 during the interview process.
///Input Format
///First line is number of nodes in list 1(m) and list 2 (n).
///Next m lines- student details in list 1(student name, college/university name, points).
///Next n lines- student details in list 2.
///Constraints
///m and n >= 0
///Output Format
///Merged single Singly Linked List.
///Sample Input 0
///2 2
///amar kletech 75
///kumar kletech 100
///ritesh kleit 89
///sudedh kleit 99
///Sample Output 0

///Joined list is:
///amar kletech 75
///kumar kletech 100
///ritesh kleit 89
///sudedh kleit 99

///Students with more than 70 points:
///amar kletech 75
///kumar kletech 100
///ritesh kleit 89
///sudedh kleit 99
///Sample Input 1

///0 0
///Sample Output 1

///Empty List
///Submissions: 185
///Max Score: 50
///Difficulty: Medium
///Rate This Challenge:




#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char name[50];
    char clg[50];
    int marks;
    struct node *next;
};
struct node * getnode()
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    scanf("%s",new->name);
    scanf("%s",new->clg);
    scanf("%d",&new->marks);
    new->next=NULL;
    return new;
}
struct node * add(struct node *head)
{
    struct node *cur=head,*new=getnode();
    if(head==NULL)
    {
        head=new;
        return head;
    }
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=new;
    return head;
}
void display(struct node *head)
{
    struct node *cur=head;
    printf("Joined list is:\n");
    while(cur!=NULL)
    {
        printf("%s %s %d\n",cur->name,cur->clg,cur->marks);
        cur=cur->next;
    }
}
void display_marks(struct node *head)
{
   struct node *cur=head;
    if(head!=NULL)
        printf("\nStudents with more than 70 points:\n");
    while(cur!=NULL)
    {
        if(cur->marks>70)
        {
            printf("%s %s %d\n",cur->name,cur->clg,cur->marks);
        }
        cur=cur->next;
    }
}
struct node * merge(struct node *head1,struct node *head2,int m)
{
    struct node *cur1=head1,*cur2=head2;
    while(cur1->next!=NULL)
    {
        cur1=cur1->next;
    }
    for(int i=0;i<m;i++)
    {
        cur1->next=cur2;
        cur1=cur1->next;
        cur2=cur2->next;
    }
    return head1;
}
int main()
{
    struct node *head1=NULL,*head2=NULL;
    int n,m,i;
    scanf("%d%d",&n,&m);
    if(n==0 || m==0)
    {
        printf("Empty List");
        exit(0);
    }
    for(i=0;i<n;i++)
    {
         head1=add(head1);
    }
    for(i=0;i<m;i++)
    {
         head2=add(head2);
    }

    head1=merge(head1,head2,m);
    display(head1);
    display_marks(head1);
}
