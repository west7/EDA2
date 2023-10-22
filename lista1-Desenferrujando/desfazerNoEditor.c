#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node{
    char str[MAX_SIZE];
    struct Node *next;
}Node;

typedef struct Stack{
    Node *top;
}Stack;

void startStack(Stack *s){
    s->top == NULL;
}

int insert(Stack *s, char *str){
    Node *n  = malloc(sizeof(Node));
    if(n == NULL){
        printf("Erro de alocação\n");
        return -1;
    }
    strcpy(n->str, str);
    n->next = s->top;
    s->top = n;
    return 1;
}

const char* pop(Stack *s){
    if(s->top == NULL) return "NULL";
    char *frase = strdup(s->top->str);

    Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    return frase;
}

int main(){
    
    Stack *s = malloc(sizeof(Stack));
    if(s == NULL){
        printf("Error to create Stack");
        return -1;
    }
    startStack(s);

    char action[20];
    while(scanf("%s", action) != EOF) {
        if(strcmp(action, "inserir") == 0){
            char str[MAX_SIZE];
            scanf("%[^\n]", str);
            insert(s, str);
        }else if(strcmp(action, "desfazer") == 0){
            printf("%s\n", pop(s));
        }
    }

    return 0;
}