#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;      

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s){
    s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s){
    return (s->top == -1);
} 

// 포화 상태 검출 함수
int is_full(StackType* s){
    return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입함수
void push(StackType* s, element item){
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else{
        s->data[++(s->top)] = item; 
    }
}
// 삭제함수
element pop(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else{
        return s->data[(s->top)--];
    }
}
// 피크함수
element peek(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[s->top];
}

// ===== 스택 코드의 끝 ===== 
int prec(char op)
{
    switch (op) {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}

element* infix_to_postfix(char *s)
{
    int i, idx=0;
    char ch, top_op;
    int len = strlen(s);

    element* postfixarr=(element*)malloc(MAX_STACK_SIZE);
    StackType k;

    init_stack(&k);               // 스택 초기화 
    for (i = 0; i < len; i++) {
        ch = s[i];
        switch (ch) {
            case '+': 
            case '-': 
            case '*': 
            case '/': // 연산자 // 스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
                while (!is_empty(&k) && (prec(ch) <= prec(peek(&k))))
                postfixarr[idx++]=peek(&k);
                pop(&k);  //printf("%c", pop(&k)); 
                push(&k, ch);
                break;
            case '(':   // 왼쪽 괄호
                push(&k, ch);
                break;
            case ')':   // 오른쪽 괄호
                top_op = pop(&k); 
                while (top_op != '(') { // 왼쪽 괄호를 만날때까지 출력
                    postfixarr[idx++]=top_op;
                    top_op = pop(&k);
                }
                break;
            default:      // 피연산자
                postfixarr[idx++]=ch;
                //pop(&k); //printf("%c",pop(&k));
                break;
    }
}
    while (!is_empty(&k))  { // 스택에 저장된 연산자들 출력
        top_op=peek(&k);
        pop(&k);
        postfixarr[idx++]=top_op;
    }
    postfixarr[idx]='\n';
    return postfixarr;
}


int eval(char *s)
{
    int op1, op2, value, i = 0;
    int len = strlen(s);
    char ch, open_ch, top_op;
    StackType k;

    init_stack(&k);
    for (i = 0; i < len; i++) {
        ch = s[i];
        switch (ch) {
            case'(':
                push(&k, ch);
                break;
            case ')':
                if (is_empty(&k)) {
                    return -999;
                }
                else {
                    open_ch = pop(&k);
                    if (open_ch == '(' && ch != ')'){
                        return -999;
                    }
                }
                break;
        }
}
    if (!is_empty(&k)) {
        return -999;
    }
    else {
        s=infix_to_postfix(s);
        printf("%s",s);
        for (i = 0; i < len; i++) {
            ch = s[i]; //문자열 하나씩 순서대로 검사
            if (ch != '+' && ch != '-' && ch != '*' && ch != '/') { // 입력이 피연산자이면
                value = ch - '0'; //문자->정수로 바꿔서 value에 저장
                push(&k, value); 
            }
            else {   //연산자이면 피연산자를 스택에서 제거
                op2 = pop(&k); 
                op1 = pop(&k); 
                switch (ch) { //연산을 수행하고 스택에 저장 
                    case '+': push(&k, op1 + op2); break;
                    case '-': push(&k, op1 - op2); break;
                    case '*': push(&k, op1 * op2); break;
                    case '/': 
                        if(op2==0){
                            return -999;
                        }
                        else {
                            push(&k, op1 / op2);
                        }
                        break;
                }
            }
        }
    }
    return pop(&k);
}

int main(void) {
    char* exp = "3+2";
    int result;

    result = eval(exp);

    if (result == -999) {
        printf("Error\n");
        return 1;
    }
    else {
        printf("Result = %d\n", result);
        return 0;
    }
}
