/*11. Develop a menu driven program to evaluate postfix and prefix expressions using
stack.*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
void evaluate(char[]);
float compute(float, float, char);
struct stk
{
    float item[20];
    int top;
};
typedef struct stk STK;

void push(float c, STK *s)
{
    if (s->top == 19)
        printf("Stack full\n");
    else
        s->top++;
    s->item[s->top] = c;
}

float pop(STK *s)
{
    float c;
    if (s->top == -1)
        printf("Stack empty\n");
    else
        c = s->item[s->top];
    s->top--;
    return c;
}

int isoperand(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
    case ')':
    case '$':
    case '^':
        return 0;
    default:
        return 1;
    }
}

void evaluate1(char po[])
{
    STK s;
    char c;
    float op1, op2, res;
    int i = 0;
    s.top = -1;
    while ((c = po[i++]) != '\0')
    {
        if (isoperand(c))
            push(c - '0', &s);
        else
        {
            op2 = pop(&s);
            op1 = pop(&s);
            res = compute(op1, op2, c);
            push(res, &s);
        }
    }
    res = pop(&s);
    if (s.top != -1)
        printf("Invalid expression\n");
    else
        printf("Value of expression is:%f\n", res);
}

void evaluate2(char pre[])
{
    STK s;
    char c;
    float op1, op2, res;
    int i = 0;
    s.top = -1;
    i = strlen(pre) - 1;
    // printf("%d\n",i);
    while (i >= 0) // SCAN EXPRESSION
    {
        c = pre[i];
        if (isoperand(c))
            push(c - '0', &s);
        else
        {
            op1 = pop(&s);
            op2 = pop(&s);
            res = compute(op1, op2, c);
            push(res, &s);
        }
        i--;
    }
    res = pop(&s);
    if (s.top != -1)
        printf("Invalid Expression\n");
    else
        printf("Value of the expression is %f\n", res);
} // END EVALUATE

float compute(float op1, float op2, char opr)
{
    switch (opr)
    {
    case '+':
        return (op1 + op2);
    case '-':
        return (op1 - op2);
    case '*':
        return (op1 * op2);
    case '/':
        return (op1 / op2);
    case '^':
        return pow(op1, op2);
    case '$':
        return pow(op1, op2);
    default:
        printf("invalid expression");
    }
}

void main()
{
    char pos[30];
    int ch;
    for (;;)
    {
        printf("-----------------------------------------------------------------\nEnter the choice\n1.evalpost\n2.evalpre\n0.To exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("enter the Postfix Expression\n");
            scanf("%s", pos);
            evaluate1(pos);
            break;
        case 2:
            printf("enter the Prefix Expression\n");
            scanf("%s", pos);
            evaluate2(pos);
            break;
        default:
            printf("Enter the valid choice");
            break;
        case 0:
            exit(1);
        }
    }
}