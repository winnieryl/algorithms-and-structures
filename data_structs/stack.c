#include <stdio.h>
#include <stdlib.h>

#define NAME_LENGTH 20

typedef struct stackNode{
    void *value;
    struct stackNode *next;
} stackNode;

typedef struct stack{
    stackNode *top;
    void (*free)(void *ptr);
    unsigned long size;
} stack;


typedef struct person{
   int id;
   char name[NAME_LENGTH]; 
} person;

#define stackTop(s) ((s)->top)
#define stackSize(s) ((s)->size)

#define stackSetFreeMethod(s, m) ((s)->free = (m))
#define stackGetFreeMethod(s) ((s)->free)


stack *stackCreate(void);
stack *stackPush(stack *stack, void *value);
stackNode *stackPop(stack *stack);
void stackClear(stack *stack);


stack *stackCreate(void)
{
    stack *stack;
    if ((stack = (struct stack *) malloc(sizeof(struct stack))) == NULL)
    {
        printf("stack create error\n");
        return NULL;
    }
    stack->top = NULL;
    stack->free = NULL;
    stack->size = 0;
    return stack;
}

stack *stackPush(stack *stack, void *value)
{
    stackNode *node;
    if ((node = (struct stackNode *) malloc(sizeof(struct stackNode))) == NULL)
    {
        printf("stack push error\n");
        return stack;
    }
    node->value = value;
    node->next = (stack->size == 0) ? NULL : stack->top;
    stack->top = node;
    stack->size++;
    return stack;
}

stackNode *stackPop(stack *stack)
{
    stackNode *node;
    node = stack->top;
    if (stack->size != 0)
    {
        stack->top = node->next;
        stack->size--;
    }
    return node;

}

void stackClear(stack *stack)
{
    unsigned long size;
    stackNode *current, *next;

    current = stack->top;
    size = stack->size;
    while(size--)
    {
        next = current->next;
        if(stack->free) stack->free(current->value);
        free(current);
        current = next;
    }
    free(stack);
}


int main()
{
    int i,j;
    stack* stack = stackCreate();
    for(i=0;i<100;i++)
    {
        person* person = (struct person*)malloc(sizeof(struct person));
        person->id = i;
        sprintf(person->name, "person:%d", i);
        stackPush(stack, (void *)person);
    }
    while(stack->size)
    {
        stackNode *node = stackPop(stack);
        person *person = (struct person*)node->value;
        printf("pop value:id:%d, name:%s\n", person->id, person->name);
    }


    return 0;
}




