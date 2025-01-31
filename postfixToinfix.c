#include<stdio.h>
#include<string.h>
void push(char item[], int*top, char s[][20])
{
    *top=*top+1;               //Point top to next location.
    strcpy(s[*top],item);
}
char *pop(int *top, char s[][20])
{
    char *item;
    item = s[*top];            //Access the top most item.
    *top= *top-1;              //Update the to pointer.
    return item;               //Return item to the calling function.
}

void postfix_infix(char postfix[], char infix[])
{
    char s[20][20];
    int top;
    char symbol;
    char temp[2];
    char *op1;
    char *op2;
    int i;
    top=-1;
    for(i=0; i<strlen(postfix); i++)
    {
        symbol =postfix[i];

        temp[0]='\0';

        switch (symbol)
        {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
               op2=pop(&top,s);
               op1=pop(&top,s);

               strcpy(infix,"(");
               strcat(infix, op1);
               strcat(infix, temp);
               strcat(infix, op2);
               strcat(infix, ")");

               push(infix,&top,s);

               break;
            
            default:
                  push(temp,&top,s);
               
        }
    }
}

void main()
{
    char postfix[20];
    char infix[20];

    printf("Enter the postfix expression\n");
    scanf("%s",postfix);

    postfix_infix(postfix,infix);

    printf("The infix expression is %s",infix);
}