#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "stack.h"
int i = 0;


int AnalyzeChar(char c, char arr[]){
    int ErrorState = 0;

}

int Parse(){
    // почитать про машину тьюринга почитать про тьюринг полноту +
    /// строчка с кодом тоже нужна
    // стек хранящий индекс открывающей скобки (по строчке с кодом)
    int size = 0;
    int capacity = 1;
    char *str = malloc(sizeof(char));
    int arr[30000];
    memset(arr, 0, 30000* sizeof(int));
    int c;
    int ErrorState = 0;
    int gotoClosing = 0;
    Stack *stack = stack_create();
    //int t = getc(stdin);
    while((c = getc(stdin)) != EOF){
        size++;
        if(size>=capacity){
            capacity*=2;
            str = realloc(str, capacity* sizeof(char));
        }
        str[size-1] = (char)c;
    }
    for(int j = 0; j<size;j++){
        switch(str[j]){
            case '.':
                if(!gotoClosing) {
                    printf("%d ", arr[i]);
                 //   fflush(stdout);
                }
                break;
            case ',':
                if(!gotoClosing) {
                    scanf("%d", &arr[i]);
                }
                break;
            case '+':
                if(!gotoClosing) {
                    arr[i]++;
                }
                break;
            case '-':
                if(!gotoClosing) {
                    arr[i]--;
                }
                break;
            case '>':
                if(!gotoClosing) {
                    i++;
                }
                break;
            case '<':
                if(!gotoClosing) {
                    i--;
                }
                break;
            case '[':
                if(arr[i] == 0) {
                    gotoClosing = 1;
                }
                else {
                    push_back(stack, j);
                }
                break;
            case ']':
                if(arr[i] != 0){
                    j = peek(stack) - 1;
                    continue;
                } else{
                    pop_back(stack);
                    gotoClosing = 0;
                }
               break;
            case '\n':
                break;
            default:
                ErrorState = -1;
                goto end;

        }
    }
    end:
    free(str);
    return  ErrorState;

}

int main() {
    printf("%d", Parse());

}