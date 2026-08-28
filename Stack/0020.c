/*
 * Time complexity: O(n)
 * Space complexity: O(n)
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char* items;
    int top;
} Stack;

void push(Stack* stack, char item) {
    stack->top++;
    stack->items[stack->top] = item;
}

char pop(Stack* stack) {
    if (stack->top == -1) {
        return '\0';
    }
    char topItem = stack->items[stack->top];
    stack->top--;
    return topItem;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

bool isValid(char* s) {
    int len = strlen(s);
    if (len % 2 != 0) return false;
    
    Stack stack;
    stack.items = (char*) malloc(len * sizeof(char)); 
    stack.top = -1;

    for (int i = 0; i < len; i++) {
        char current = s[i];
        
        if (current == '(' || current == '[' || current == '{') {
            push(&stack, current);
        } else {
            if (isEmpty(&stack)) {
                free(stack.items);
                return false;
            }
            
            char topChar = pop(&stack);
            
            if ((current == ')' && topChar != '(') ||
                (current == ']' && topChar != '[') ||
                (current == '}' && topChar != '{')) {
                free(stack.items);
                return false;
            }
        }
    }

    bool result = isEmpty(&stack);
    free(stack.items);
    return result;
}