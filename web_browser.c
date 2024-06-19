/*Simulate the forward and back button of the web browser using DLL. The buttons should perform the following operations:

a) The forward button should move the webpage to next webpage.

b) The back button should move the webpage to previous webpage.

c) At any point, after moving certain webpages forward or back, web browser should be able to display current webpage information.

d) The web browser should display one webpage information at a time.

Input Format

First line is N - number of webpages visited in the web browser.

Second line onwards is webpage details (website name, copyright, year of last update)

Last but one line is movement of webpages K times in forward direction from first webpage.

Last line is movement of webpages from current webpage back L times.

Constraints

N is positive.

K, L < N

Output Format

Display the first webpage information visited.

Display webpage information after K movements from first webpage.

Display the webpage after L movements back from current webpage.

Sample Input 0

5
www.google.com Google 2023
www.facebook.com Meta 2023
www.gmail.com Google 2023
www.instagram.com Meta 2022
www.youtube.com Google 2022
4
2
Sample Output 0

www.google.com Google 2023

www.youtube.com Google 2022

www.gmail.com Google 2023
Sample Input 1

5
www.google.com Google 2023
www.facebook.com Meta 2023
www.gmail.com Google 2023
www.instagram.com Meta 2022
www.youtube.com Google 2022
3
1
Sample Output 1

www.google.com Google 2023

www.instagram.com Meta 2022

www.gmail.com Google 2023
Sample Input 2

3
www.google.com Google 2023
www.instagram.com Meta 2022
www.ytmusic.com Goolge 2022
1
1
Sample Output 2

www.google.com Google 2023

www.instagram.com Meta 2022

www.google.com Google 2023*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    char web[90];
    char cw[50];
    int year;
    struct node *next,*prev;
};
struct node * getnode()
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    scanf("%s%s%d",newnode->web,newnode->cw,&newnode->year);
    newnode->next=newnode->prev=NULL;
    return newnode;
}

struct node* addnode(struct node * head)
{
    struct node *newnode=getnode();
    struct node *cur=head;
    if(head==NULL)
        return newnode;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=newnode;
    newnode->prev=cur;
    newnode->next=NULL;
    return head;
}
void search(struct node *head,int f,int b)
{
    struct node *cur=head,*p=NULL;
    if(head==NULL)
       return 0;
    printf("%s  %s  %d\n",cur->web,cur->cw,cur->year);
    for(int i=0;i<f&& cur->next!=NULL;i++)
    {
        cur=cur->next;
    }
    printf("%s  %s  %d\n",cur->web,cur->cw,cur->year);
    p=cur->prev;
    cur=p;

    for(int i=0;i<b&& cur->prev!=NULL;i++)
    {
        cur=cur->prev;
    }
    printf("%s  %s  %d\n",cur->web,cur->cw,cur->year);

}
int main()
{
    struct node* head=NULL;
    int N,m,o;
    scanf("%d",&N);
    if(N<0)
        exit(0);
    for(int i=0;i<N;i++)
    {
        head=addnode(head);
    }
    scanf("%d%d",&m,&o);
    if(m<N && o<N)
      search(head,m,o);
    return 0;
}
