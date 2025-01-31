#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Structure Declerations
typedef struct node
{ 
    char data;
    struct node* link;
}
STACK_NODE;

// prototype declerations
void insertData        (STACK_NODE** pStackTop);
void print             (STACK_NODE** pStackTop);

bool PUSH(STACK_NODE** pList, char dataIn);
bool POP(STACK_NODE** pList, char* dataOut);

int main()
{
    STACK_NODE* pStackTop;

    printf("Beginning Simple Stack Program\n\n");
    pStackTop = NULL;
    insertData (&pStackTop);
    print(&pStackTop);
    printf("\n\nEnd Simple Stack Program\n");
    return 0;
}