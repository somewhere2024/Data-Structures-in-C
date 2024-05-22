#include"MYSTL.h"


/*�����ڵ�*/
list_node* creatnode(int value)
{
    list_node* newnode = (list_node*)malloc(sizeof(list_node));
    if (newnode == NULL) return NULL;
    newnode->value = value;
    newnode->prev = newnode->next = NULL;
    return newnode;
}
/* �������� */
list* list_create(void)
{
    list* list = (struct list*)malloc(sizeof(struct list));
    if (list == NULL) return NULL;
    list->head = list->tail = NULL;   //��ʼ������ 
    list->length = 0;
    return list;
}

/* ����һ�������� */
list_iter* list_get_iterator(list* list, int direction)
{
    list_iter* iter = (list_iter*)malloc(sizeof(list_iter));
    if (iter == NULL) return NULL;
    if (direction == LIST_START_HEAD)  //�жϷ���
        iter->next = list->head;
    else
        iter->next = list->tail;
    iter->direction = direction;
    return iter;
}

/* �ͷŵ������ڴ� */
void list_release_iterator(list_iter* iter)
{
    free(iter);
}

/* ����������һ���ڵ�ֵ */
void* list_next(list_iter* iter)
{
    list_node* current = iter->next;
    if (current == NULL) return NULL;

    /* �жϵ��������򣬲���������`next`ָ��ָ����һ���ڵ㡣 */
    if (iter->direction == LIST_START_HEAD)
        iter->next = current->next;
    else
        iter->next = current->prev;

    return current->value;
}

/* ���һ���ڵ�������ͷ�� */
list* list_add_node_head(list* list, void* value)
{
    /* �½�һ������ڵ� */
    list_node* node = (list_node*)malloc(sizeof(list_node));
    if (node == NULL) return NULL;
    node->value = value;
    /* �������Ϊ�� */
    if (list->length == 0) {
        list->head = list->tail = node;
        node->prev = node->next = NULL;
    }
    else {
        node->prev = NULL;  //�����½ڵ�
        node->next = list->head;
        list->head->prev = node;  //��������
        list->head = node;
    }
    list->length++;
    return list;
}

/* ���һ���ڵ�������β�� */
list* list_add_node_tail(list* list, void* value)
{
    /* �½�һ������ڵ� */
    list_node* node = (list_node*)malloc(sizeof(list_node));
    if (node == NULL) return NULL;
    node->value = value;
    if (list->length == 0) {
        list->head = list->tail = node;
        node->prev = node->next = NULL;
    }
    else {
        node->prev = list->tail;
        node->next = NULL;
        list->tail->next = node;
        list->tail = node;
    }
    list->length++;
    return list;
}


/* ɾ��һ���ڵ� */
void list_del_node(list* list, list_node* node)
{
    /* �жϸýڵ��Ƿ���ֱ��ǰ�� */
    if (node->prev)
        node->prev->next = node->next;
    else
        list->head = node->next;

    /* �жϸýڵ��Ƿ���ֱ�Ӻ�� */
    if (node->next)
        node->next->prev = node->prev;
    else
        list->tail = node->prev;

    /* �ͷŸýڵ� */
    free(node);
    list->length--;
}

/* ��ȡͷ��Ԫ�� */
void* list_get_value_head(list* list)
{
    if (list->head == NULL) return NULL;
    void* value = list->head->value;   //��ʱ����һ��������������
    list_del_node(list, list->head);   //ɾ���ýڵ�
    return value;
}

/* ��ȡβ��Ԫ�� */
void* list_get_value_tail(list* list)
{
    if (list->tail == NULL) return NULL;
    void* value = list->tail->value;
    list_del_node(list, list->tail);
    return value;
}
/* ������������еĽڵ㵫�ǲ�ɾ�������� */
void list_empty(list* list)
{
    unsigned long length;
    list_node* current, * next;
    current = list->head;
    length = list->length;
    while (length--)
    {
        next = current->next;
        free(current);
        current = next;
    }
    list->head = list->tail = NULL;
    list->length = 0;
}

/* �ͷ��������� */
void list_release(list* list)
{
    list_empty(list);
    free(list);
}
