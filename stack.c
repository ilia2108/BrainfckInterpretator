#include "stack.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

Stack* stack_create(void) {
    Stack *res = malloc(sizeof(Stack));
    memset(res, 0, sizeof(Stack));
    return res;
}
void stack_free(Stack *stack) {
    free(stack->data);
    free(stack);
}
int push_back(Stack *stack, int elem) {

    if(++stack->Length > stack->Capacity){
        stack->Capacity = stack->Length*2;
        stack->data = realloc(stack->data, stack->Capacity* sizeof(Stack*));
    }
    stack->data[stack->Length-1] = elem;

    return stack->Length;
}

int pop_back(Stack *stack) {
    if(stack->Length) {
        if(stack->Length*4 < stack->Capacity) {
            stack->Capacity = stack->Length*2;
            stack->data = realloc(stack->data, stack->Capacity*sizeof(Stack*));
        }
        return stack->data[--stack->Length];
    }
    return -1;
}

int peek(Stack* stack){
    if(stack->Length)
        return stack->data[stack->Length-1];
    return -1;
}
