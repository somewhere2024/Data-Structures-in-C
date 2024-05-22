#include "MYSTL.h"

/* ����ջ */
stack* stack_create()
{
    stack* stack = (struct stack*)malloc(sizeof(struct stack));
    /* �ȼ�д����
    stack *s =  (stack*)malloc(sizeof(stack)); */
    if (stack == NULL)
        return NULL;
    /* ��ʼ�� */
    stack->length = 0;
    stack->top = NULL;
    return stack;
}

/* ��ջ */
stack* stack_push(stack* stack, void* data)
{
    /* ����һ���ڵ� */
    stack_node* node = (struct stack_node*)malloc(sizeof(struct stack_node));
    if (node == NULL) 
        return NULL;
    node->data = data;

    /* ���� */
    node->next = stack->top;
    stack->top = node;

    stack->length++;
    return stack;
}


/* ��ջ */
void* stack_pop(stack* stack)
{
    /* ��ʱ����ջ��Ԫ�� */
    stack_node* current = stack->top;
    if (current == NULL) return NULL;
    void* data = current->data;
    stack->top = stack->top->next;

    free(current);
    stack->length--;
    return data;
}

/* ���ջ������Ԫ�أ��������ջ���� */
void stack_empty(stack* stack)
{
    int length = stack->length;
    stack_node* current, * next;
    current = stack->top;
    /* ����ջ�ĸ߶�ȷ��ɾ���ڵ�Ĵ��� */
    while (length--)
    {
        next = current->next;
        free(current);
        current = next;
    }

    stack->length = 0;
    stack->top = NULL;
}

/* ���ջ������Ԫ�ز�ɾ��ջ */
void stack_release(stack* stack)
{
    stack_empty(stack);
    free(stack);
}