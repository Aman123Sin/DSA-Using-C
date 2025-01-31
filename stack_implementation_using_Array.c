#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10
int stack[MAXSIZE],top=-1;

void push()
{
    int n;
    if(top==MAXSIZE-1)
    {
        printf("Stack is OverFlow.");
    }
    else
    {
        printf("Enter Element:");
        scanf("%d",&n);
        top++;
        stack[top]=n;
    }
}

void pop()
{
    int n;
    if(top==-1)
    {
        printf("Stack is Empty.");
    }
    else
    {
        n=stack[top];
        top--;
        printf("Poped Element %d",n);
    }
}

void display()
{
    int i;
    if (top==-1)
    {
        printf("Stack is Empty.");   
    }
    else
    {
        printf("Elements of Stack :");
        for(i=top; i>=0; i--)
        {
            printf("\n%d",stack[i]);
        }
    }
    
}

void main()
{
    int choice;
    do
    {
        printf("\n_______STACK_______");
        printf("\n1.PUSH \n2.POP\n3.DISPLAY\n4.EXIT");
        printf("\n___________________");
        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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