#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

int top=-1;
char stack[40];

int push(char x){
    stack[++top]=x;
}

int pop(){
    return stack[top--];
}

int prior(char x){
    if(x=='(' || x=='#')
        return 1;
     else if(x=='+' || x=='-')
        return 2;
     else if(x=='*' || x=='/')
        return 3;
    else if(x=='^' || x=='$')
        return 4;
    return 0;
}


void main() {
    int i,j=0;
    char infix[30],postfix[30];
    printf("Enter the infix operation:");
    gets(infix);
    push('#');
    for(i=0;i<strlen(infix);i++){
        if(isalnum(infix[i]))
            postfix[j++]=infix[i];

        else if(infix[i]=='(')
            push(infix[i]);

        else if(infix[i]==')'){
            while(stack[top]!='(')
                postfix[j++]=pop();
                   pop();
        }
        else {
            while(prior(stack[top])>=prior(infix[i]))
                 postfix[j++]=pop();
                 push(infix[i]);
        }
    }
    while (stack[top] != '#') // Pop remaining operators
    postfix[j++] = pop();
    postfix[j] = '\0'; // Null-terminate the postfix expression
    printf("The postfix expression is:\n");
    puts(postfix);
}
