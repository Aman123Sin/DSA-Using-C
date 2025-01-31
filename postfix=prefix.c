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

void postfix_prefix(char postfix[], char prefix[])
{
    char s[20][20];           //Stack to hold the intermidiate prefix obtained.
    int top;                  //Points to topmost item.
    char Symbol;              //Symbol scanned from postfix expression.
    char temp[2];             //To convert symbol scanned from postfix expression.
    char *op1;                //Holds operand 1 obtained after popping.
    char *op2;                //Holds operand 2 obtained after popping.
    int i;                    //Index to scan each symbol from postfix.

    top=-1;                   //Stack is empty.
    for(i=0; i<strlen(postfix); i++)
    {
        Symbol=postfix[i];    //Obtain the next symbol.

        temp[0] = Symbol;     //Convert Symbol to string.
        temp[1] = '\0';
        
        switch(Symbol)
        {
            case '+':
            case '-':
            case '*':                //If the scanned symbol is an operator.
            case '/':
            case '^':
              op2 =pop(&top,s);         //Obtain the second operand.
              op1 =pop(&top,s);         //Obtain the first operand.

            /*Build the partial prefix expression: Op op1 op2*/
            strcpy(prefix,temp);      //Prefix operator.
            strcat(prefix, op1);      //Concatenate frist operand.
            strcat(prefix, op2);      //Concatenate Second operand.

            push(prefix, &top, s);    //Push partial prefix obtained.

            break;

            default:
              push(temp,&top,s);      //Push the operand on to stack

        }

    }
}

void main()
{
    char postfix[20];
    char prefix[20];

    printf("Enter the postfix expression\n");
    scanf("%s",postfix);
    
    postfix_prefix(postfix,prefix);

    printf("The prefix expression is %s\n",prefix);
}