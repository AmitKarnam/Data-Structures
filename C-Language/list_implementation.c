//This code is to demonstrate lists similar to Python3 using Arrays concept. P.S: I haven't demonstrated Linked lists feature in this program
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void add();
void insert();
void del();
void find();
void dis();

int a,b[20], n, p, e, f, i, pos;

int main()
{
    int ch;
    char g = 'y';
    do{
        printf("\n Main Menu");
        printf("\n 1.Create \n 2.Delete \n 3.Search \n 4.Insert \n 5.Display\n 6.Exit \n");
        printf("\n Enter your Choice");
        scanf("%d", &ch);

        switch(ch)
        {
        case 1:
        add();
        break;

        case 2:
        del();
        break;

        case 3:
        find();
        break;

        case 4:
        insert();
        break;

        case 5:
        dis();
        break;

        case 6:
        return 0;
        break;

        default:
        printf("\n Enter the correct choice:");
        }
        printf("\n Do u want to continue?");
        scanf("\n%c", &g);
            }while(g == 'y' || g== 'Y');
}

void add()
{
printf("\n Enter the number of nodes");
scanf("%d", &n);
for(i=0;i<n;i++)
{
printf("\n Enter the %d Element:",i+1);
scanf("%d", &b[i]);
}

}

void del()
{
printf("\n Enter the position u want to delete: ");
scanf("%d", &pos);
if(pos>=n)
{
printf("\n Invalid Location");
}
else
{
for(i=pos+1;i<n;i++)
{
b[i-1]=b[i];
}
n--;
}
printf("\n The Elements after deletion");
for(i=0;i<n;i++)
{
printf("\t%d", b[i]);
}
}


void find()
{
int x=0;
printf("\n Enter the Element to be searched:");
scanf("%d", &e);

for(i=0;i<n;i++)
{
if(b[i]==e)
{
x=1;
printf("Value is in the %d Position", i);
break;
}
}
if(x==0)
{
printf("Value %d is not in the list::", e);
}
}


void insert()
{
printf("\n Enter the position u need to insert: ");
scanf("%d", &pos);

if(pos>=n)
{
printf("\n invalid Location::");
}
else
{
    for(int i=10-1; i>pos-1; i--)
    {
    b[i+1]=b[i];
    }
    printf("\n Enter the element to insert: ");
    scanf("%d",&p);
    b[pos]=p;
    n++;
}
printf("\n The list after insertion::\n");
dis();
}


void dis()
{
printf("\n The Elements of The list ADT are:");
for(i=0;i<n;i++)
{
printf("\n\n%d", b[i]);
}
}

//Code is working!
