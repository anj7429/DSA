
#include <stdio.h>
#include <stdlib.h> 
#define max 6

struct stack {
    int item[max]; 
    int top;
};

void push(struct stack *pstk, int el) {
    if (pstk->top == max - 1) {
        printf("Stack overflow!\n");
    } else {
        pstk->top = pstk->top + 1;
        pstk->item[pstk->top] = el;
    }
}

int pop(struct stack *pstk) {
    if (pstk->top == -1) {
        printf("Stack underflow!\n");
        return -1; 
    } else {
        int temp = pstk->item[pstk->top];
        pstk->top = pstk->top - 1;
        return temp;
    }
}
void pushtest(struct stack *pstk,int el,int *pover){
	if(pstk->top==max-1){
		*pover=1;
	}
	else{
		pstk->top=pstk->top+1;
		pstk->item[pstk->top]=el;
	}
}
int poptest(struct stack *pstk,int *punder){
	int temp;
	if(pstk->top==-1){
		*punder=1;
	}
	else{
		temp=pstk->item[pstk->top];
		pstk->top=pstk->top-1;
		return temp;
	}
}

int main() {
    struct stack *stk = (struct stack *)malloc(sizeof(struct stack)); 
    if (stk == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    stk->top = -1; 
    int el, ch;
    char c; 

    do {
        printf("**** MENU *****\n");
        printf("Press 1 to push element in stack\n");
        printf("Press 2 to pop element from stack\n");
        printf("Press 3 to print top element of the stack\n");
        printf("Press the key to perform operation: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element you want to push in stack: ");
                scanf("%d", &el);
                push(stk, el);
                break;

            case 2:
                el = pop(stk); 
                if (el != -1) {
                    printf("\nPopped element from stack: %d\n", el);
                }
                break;

            case 3:
                if (stk->top != -1) { 
                    printf("Top element of stack is %d\n", stk->item[stk->top]);
                } else {
                    printf("Stack is empty!\n");
                }
                break;

            default:
                printf("\nInvalid input!\n");
        }

        printf("\nDo you want to continue? (Y/N): ");
        scanf(" %c", &c); 

    } while (c == 'y' || c == 'Y');

    free(stk);
    return 0;
}

