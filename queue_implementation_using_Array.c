#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10
int queue[MAXSIZE],rear=-1,front=0;

void insert()
{
    int n;
    if(rear==MAXSIZE-1)
    {
        printf("queue is OverFlow.");
    }
    else
    {
        printf("Enter Element:");
        scanf("%d",&n);
        rear++;
        queue[rear]=n;
    }
}

void delete()
{
    int n;
    if(front>rear)
    {
        printf("queue is Empty.");
    }
    else
    {
        n=queue[front];
        front++;
        printf("deleteed Element %d",n);
    }
}

void display()
{
    int i;
    if(front>rear)
    {
        printf("queue is Empty.");   
    }
    else
    {
        printf("Elements of queue :");
        for(i=rear; i>=front; i--)
        {
            printf("\t%d",queue[i]);
        }
    }
    
}

void main()
{
    int choice;
    do
    {
        printf("\n_______queue_______");
        printf("\n1.insert \n2.delete\n3.DISPLAY\n4.EXIT");
        printf("\n___________________");
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        default:
            printf("\nInvalid Choice.");
            break;
        }

    } while (choice!=4);
    
   
}