#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10
int queue[MAXSIZE],rear=-1,front=-1;

void insert()
{
    int n;
    if((rear+1)%MAXSIZE==front)
    {
        printf("queue is OverFlow.");
    }
    else
    {
        printf("Enter Element:");
        scanf("%d",&n);
        if(rear==-1 && front==-1)
        {
            rear=0;
            front=0;
            queue[rear]=n;
        }
        else
        {
            rear=(rear+1)%MAXSIZE;
            queue[rear]=n;
        }
        
    }
}

void delete()
{
    int n;
    if(front==-1 && rear==-1)
    {
        printf("queue is Empty.");
    }
    else
    {
        if(rear==front)
        {
            rear=-1;
            front=-1;
            
        }
        else
        {
            n=queue[front];
            front=(front+1)%MAXSIZE;
            printf("deleteed Element %d",n);
        }
        
    }
}

void display()
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("queue is Empty.");   
    }
    else
    {
        printf("Elements of queue :");
        for(i=front; i!=rear; i=(i+1)%MAXSIZE)
        {
            printf("\t%d",queue[i]);
        }
        printf("\t%d",queue[i]);

    }
    
}

void main()
{
    int choice;
    do
    {
        printf("\n_______Circular Queue_______");
        printf("\n1.insert \n2.delete\n3.DISPLAY\n4.EXIT");
        printf("\n____________________________");
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