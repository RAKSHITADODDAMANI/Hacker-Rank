/*Shrirish is student participating in coding competition held by KPIT company. He is given a problem statement “Candy Wending Machine”. A machine will request the selected coins to be inserted, they are 1re, 5rs, 10rs and 20rs coins only. When the value of a coin inserted is other than mentioned coins, those coins are returned by the machine.

If the sum of all coins is greater than or equal to 25rs but less than 34rs then fetch Mango Candy from machine, if the sum of all the coins is greater than or equal to 35rs but less than 49rs then fetch Strawberry Candy, if the sum of all the coins is greater than or equal to 50rs but less than 70rs fetch Pista Candy, otherwise display No candy.

Input Format

The first line contains n, the number of coins to be inserted in machine.

The second line contains n space-separated coins with given denominations.

Constraints

1<=n<=100

0<=i<=n

Coins must be either 1,5,10,20.

Output Format

Dislay the candy name.

Sample Input 0

4
5 10 5 20
Sample Output 0

Strawberry candy
Explanation 0

Sum off all coins will be 40, therefore Strawberry candy will be fetched from machine.

Sample Input 1

3
2 5 10
Sample Output 1

No candy
Explanation 1

Denomination 2 is returned by machine. Sum of coins will be 15, therefore No candy.

Sample Input 2

6
50 10 20 5 1 20
Sample Output 2

Pista candy*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int array[100];
    int N;
    int sum=0;
    scanf("%d",&N);
    if(N<=0)
        exit(0);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&array[i]);
    }
    for(int j=0;j<N;j++)
    {
        if(array[j]==1 || array[j]==5 || array[j]==10 || array[j]==20)
        {
           sum=sum+array[j];
        }
    }
    if(sum>=25 && sum<34)
        printf("Mango Candy \n");
    else if(sum>=35 && sum<49)
        printf("Strawberry Candy \n");
    else if(sum>=50 && sum<70)
        printf("Pista Candy \n");
    return 0;
}
