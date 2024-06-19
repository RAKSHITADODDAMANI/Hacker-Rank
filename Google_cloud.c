/*Google provides the Private Cloud services to the students of Willox University. Private Cloud has Virtual Machine software where students can install Operating Systems and work on their Projects. Google private cloud allocates resources needed as per the student’s request. A student fills up an online page and submits to Google private cloud service. The online page has 2 sections, one for student information and other section for resource requirements information. The Resource Requirements Information consists of: Operating system name, RAM required, Storage required, processor. Apply Problem Solving Framework to help the Google Private Cloud services to perform the following operations: Compute the Average RAM allocated for Windows10 Virtual machines. Display the student Details working on “Biohazard” project.

Input Format

N - First Line indicates number of students requests for Virtual Machine on Google Private Cloud.

Second line onwards - Details of student Information and Resources Requirements Information.

Name SRN Project_Name Semester Operating_System_Name RAM Storage Processor_Name

Constraints

N should be greater than 3.

Two different structures should be used to store the students information and Resource Requirements Information.

Output Format

Display the Average RAM allocated for Windows10 Virtual machines.

Display the students working on “Biohazard” project.

Sample Input 0

6
Amar 01FE16BCS001 Farming 6 Windows10 6 100 Corei3
Gaurav 01FE16BCS025 Biohazard 6 Windows7 2 50 DualCore
Vishal 01FE15BCS010 Earthquakes 7 ubuntu18 6 40 Corei3
Jimmy 01FE16BCS047 Biohazard 6 Windows10 4 50 Corei3
Dinesh 01FE16BCS401 Farming 5 Windows10 4 100 Corei5
Wilson 01FE16BCS050 Biohazard 6 Windows7 2 10 DualCore
Sample Output 0

Average RAM allocated for Windows10 Virtual machines:
4.67 gigabytes.

Student Details working on Biohazard project:
Gaurav 01FE16BCS025 Biohazard 6
Jimmy 01FE16BCS047 Biohazard 6
Wilson 01FE16BCS050 Biohazard 6
Sample Input 1

2
Sample Output 1

N should be greater than 3.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max 90
struct node{
    char name[max];
    char usn[12];
    char pro[max];
    int sem;
    char os[max];
    int ram;
    int stor;
    char proce[max];
    struct node *next;
};

struct node *getnode()
{
    struct node* newnode=(struct node *)malloc(sizeof(struct node));
    scanf("%s%s%s%d%s%d%d%s",newnode->name,newnode->usn,newnode->pro,&newnode->sem,newnode->os,&newnode->ram,&newnode->stor,newnode->proce);
    newnode->next=NULL;
    return newnode;
}
struct node *addnode(struct node *head)
{
    struct node* newnode=getnode();
    struct node* cur=head;
    if(head==NULL)
        return newnode;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=newnode;
    return head;

}
float avg(struct node *head)
{
    int arr[100];
    char n[max]="Windows10";
    float a=0;
    int s=0;
    int i=0;
    if(head==NULL)
        return 0;
    struct node* cur=head;
    while(cur!=NULL)
    {
        if(strcasecmp(cur->os,n)==0)
         {
            arr[i]=cur->ram;
            i++;
         }
         cur=cur->next;
    }
    for(int j=0;j<i;j++)
    {
       s=s+arr[j];
    }
    a=s/i;
    return (a);
}
void search(struct node *head,char p[])
{
    if(head==NULL)
        return 0;
    struct node* cur=head;
    while(cur!=NULL)
    {
        if(strcasecmp(cur->pro,p)==0)
         {
            printf("%s %s %s %d\n",cur->name,cur->usn,cur->pro,cur->sem);
         }
         cur=cur->next;
    }
}
int main()
{
    struct node* head=NULL;
    int N;
    float res;
    char g[max]="Biohazard";
    scanf("%d",&N);
    if(N<3)
    {
        printf("N should be greater than 3.\n");
        exit(0);
    }
    for(int i=0;i<N;i++)
    {
        head=addnode(head);
    }
    res=avg(head);
    printf("Average RAM allocated for Windows10 Virtual machines:\n%0.2f gigabytes.\n",res);
    printf("\nStudent Details working on Biohazard project:\n");
    search(head,g);
    return 0;
}
