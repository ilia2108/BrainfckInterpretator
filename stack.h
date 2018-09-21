#ifndef BRAINF_CK_STACK_H
#define BRAINF_CK_STACK_H

typedef struct _stack
{
    int *data;
    int Length;
    int Capacity;

} Stack;

Stack* stack_create(void);
void stack_free(Stack *stack);
int push_back(Stack *stack, int elem);

int pop_back(Stack *stack);
//set stack->Top
int peek(Stack* stack);

#endif //BRAINF_CK_STACK_H
