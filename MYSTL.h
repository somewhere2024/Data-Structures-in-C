#pragma once

#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include <stdarg.h>

#define MINCAP 10//Vector����С��������
#define MIN_map_cap 10
#define MAX_SIZE 100
#define maxsize 5 //������е�������� 

typedef enum {
	INT_TYPE,
	FLOAT_TYPE,
	CHAR_TYPE
} DataType;

/*
C����_vector
*/
typedef struct vector
{
	void* date;//ָ���Զ���Ԫ������
	int len;//��ǰԪ�ظ���
	int cap;//����������
	int type;//����ռ���ֽڸ���
}Vector;
//�������
void capacity(Vector* vec);
//��������
void* Vector_at(const Vector* vec, int i);// �����±�Ϊi��Ԫ�ص�ָ��
void* Vector_front(const Vector* vec);//��������ͷָ�룬ָ���һ��Ԫ��
void* Vector_back(const Vector* vec);//��������βָ�룬ָ���������һ��Ԫ��
void* Vector_find(const Vector* vec, const void* x);//�������ݣ������ҵ���ָ�룬û�з���NULL
//���뺯��
void Vector_push_back(Vector* vec, void* x);
void Vector_insert_nfront(Vector* vec, const void* p, const int n, const void* x);//������ָ��Ԫ��pǰ����n����ͬ��Ԫ��x
void Vector_insert_front(Vector* vec, const void* p, const void* x);// ������ָ��Ԫ��pǰ����һ��Ԫ��x
void Vector_insert(Vector* vec, const void* p, const void* p1, const void* p2);// ������ָ��Ԫ��pǰ������һ����ͬ����������ָ��[p1,p2)�����
//�жϺ���
bool Vector_empty(const Vector* vec);//���vector���Ƿ�Ϊ�գ���Ϊ�� O(1)
//���ش�С����
int Vector_lenth(const Vector* vec);//�������鳤��
int Vector_capacity(const Vector* vec);//������������
//��ʼ������
void Vector_initial(Vector* vec,int type,unsigned int len);
//ɾ������
void Vector_del_back(Vector* vec);//ɾ�����������һ��Ԫ��
void Vector_del_p(Vector* vec, const void* p1, const void* p2);//ɾ��ָ�������ڵ�����
void Vector_del_int(Vector* vec, const int left, const int right);//ɾ�������ڵ�����
void Vector_clear(Vector* vec);//���vector�����飬�ͷ��ڴ�


/*
C����ʵ��map
*/
typedef struct map
{
	void* value;
	void* key;//��ֵ
	unsigned int len;//map�Ĵ�С
	unsigned int value_size;//���������ֽ���
	unsigned int key_size;
	unsigned int cap;//ʵ������Ĵ�С
}Map;
void Map_capacity(Map* map);//�������
void Map_init(Map* map ,int cap ,int value_size,int key_size);//��ʼ��
void Map_insert(Map* map,void* key, void* value);//����key��Ԫ��
void Map_insert_arr(Map* map, void* key, void* value, size_t arr_len);//��������key��Ԫ��
void Map_print(Map* map);
void* Map_at(Map* map, void* key);//ͨ��key���Ҳ�����Ԫ��
void Map_clear(Map* map);
void Map_remove(Map* map, void* key);
bool Map_find(Map* map, void* key);//�����key��Ӧ��value



//��ʵ��stack
typedef struct stack_node {
	struct stack_node* next;
	void* data;
}stack_node;

typedef struct stack {
	struct stack_node* top;
	/* ��ʾջ�ĸ߶� */
	int length;
}stack;

/* ����ջ */
stack* stack_create();
/* ��ջ */
stack* stack_push(stack* stack, void* data);
/* ��ջ */
void* stack_pop(stack* stack);
/* ���ջ������Ԫ�أ��������ջ���� */
void stack_empty(stack* stack);
/* ���ջ������Ԫ�ز�ɾ��ջ */
void stack_release(stack* stack);


//ʵ��˫��list

#define LIST_START_HEAD 0   //�ӱ�ͷ����β����
#define LIST_START_TAIL 1  //�ӱ�β����ͷ����
/* ����ڵ� */
typedef struct list_node
{
	struct list_node* prev;   //ǰ���ڵ�
	struct list_node* next;   //��̽ڵ�
	void* value;    //ֵ
} list_node;

/* ���� */
typedef struct list
{
	unsigned long length;    //����
	list_node* head;   //��ͷ
	list_node* tail;    //��β
} list;

/* �������ṹ */
typedef struct list_iter
{
	list_node* next;  //��һ���ڵ�
	int direction;    //����
}list_iter;

/*�����ڵ�*/
list_node* creatnode(int data);
/* �������� */
list* list_create(void);
/* ����һ�������� */
list_iter* list_get_iterator(list* list, int direction);
/* ����������һ���ڵ�ֵ */
void* list_next(list_iter* iter);
/* �ͷŵ������ڴ� */
void list_release_iterator(list_iter* iter);
/* ���һ���ڵ�������ͷ�� */
list* list_add_node_head(list* list, void* value);
/* ���һ���ڵ�������β�� */
list* list_add_node_tail(list* list, void* value);
/* ɾ��һ���ڵ� */
void list_del_node(list* list, list_node* node);
/* ��ȡͷ��Ԫ�� */
void* list_get_value_head(list* list);
/* ��ȡβ��Ԫ�� */
void* list_get_value_tail(list* list);
/* ������������еĽڵ㵫�ǲ�ɾ�������� */
void list_empty(list* list);
/* �ͷ��������� */
void list_release(list* list);



	//ͼ
#define MAX_VERTICES 100
// ���嶥��ṹ��
typedef struct Vertex
{
	void* data;      // �洢���������
	bool visited;    // ���ʱ��,�����ظ�����ͬһ���ڵ� 
} Vertex;
// ����߽ṹ��
typedef struct Edge
{
	int start;       // �ߵ���ʼ��������
	int end;         // �ߵ���ֹ��������
} Edge;
// ����ͼ�ṹ��
typedef struct Graph
{
	int numVertices;           // ��������
	int numEdges;              // ������
	Vertex* vertices[MAX_VERTICES];  // ��������
	Edge* edges[MAX_VERTICES];       // ������
	int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];  // �ڽӾ����ж��Ƿ��бߣ� 
} Graph;

// �����¶���
Vertex* createVertex(void* data);
// �����±�
Edge* createEdge(int start, int end);
// ����ͼ
Graph* createGraph();
// ��Ӷ���
void addVertex(Graph* graph, void* data);
// ��ӱ�
void addEdge(Graph* graph, int start, int end);
// �������������DFS��
void dfs(Graph* graph, int vertexIndex, void (*print)(void*));
// �������������BFS��
void bfs(Graph* graph, int start, void (*print)(void*));
// ��ӡ����
void printInt(void* data);
// ��ӡ������
void printFloat(void* data);
// ��ӡ�ַ�
void printChar(void* data);



	//������
	// ����������ڵ�
	// ����������ڵ�
typedef struct TreeNode
{
	void* data; // ��������ָ��
	struct TreeNode* left; // ������ָ��
	struct TreeNode* right; // ������ָ��
} TreeNode;
// �����½ڵ�
TreeNode* createNode(void* data);
// ����ڵ�
void insert(TreeNode** root, void* data, int (*compare)(const void*, const void*));
// �������:��->��->�� 
void preOrder(TreeNode* root, void (*visit)(void*));
// �������:��->��->�� 
void inOrder(TreeNode* root, void (*visit)(void*));
// �������:��->��->�� 
void postOrder(TreeNode* root, void (*visit)(void*));
// ���ҽڵ�
TreeNode* search(TreeNode* root, void* key, int (*compare)(const void*, const void*));
// �ȽϺ���������
int compareInt(const void* a, const void* b);
// �ȽϺ�����������
int compareFloat(const void* a, const void* b);
// �ȽϺ������ַ���
int compareChar(const void* a, const void* b);
// ���ʺ�������ӡ��������
void tree_printInt(void* data);
// ���ʺ�������ӡ����������
void tree_printFloat(void* data);
// ���ʺ�������ӡ�ַ�������
void tree_printChar(void* data);
//�ͷ��ڴ� 
void freeTree(TreeNode* node);

	/*
	ͨ�ú���
	*/
void swap(void* val_1, void* val_2, int size);
void my_qsort(list_iter* iter, int num, int size, int (*compare)(const void*, const void*));
void vector_reverse(Vector* vector);
void list_reverse(list* p, int size);
void print(void* data_structure, int flag, int data_type);
