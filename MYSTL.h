#pragma once

#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include <stdarg.h>

#define MINCAP 10//Vector的最小申请容量
#define MIN_map_cap 10
#define MAX_SIZE 100
#define maxsize 5 //定义队列的最大容量 

typedef enum {
	INT_TYPE,
	FLOAT_TYPE,
	CHAR_TYPE
} DataType;

/*
C语言_vector
*/
typedef struct vector
{
	void* date;//指向自定义元素类型
	int len;//当前元素个数
	int cap;//容器的容量
	int type;//类型占用字节个数
}Vector;
//检查容量
void capacity(Vector* vec);
//遍历函数
void* Vector_at(const Vector* vec, int i);// 返回下标为i的元素的指针
void* Vector_front(const Vector* vec);//返回向量头指针，指向第一个元素
void* Vector_back(const Vector* vec);//返回向量尾指针，指向向量最后一个元素
void* Vector_find(const Vector* vec, const void* x);//查找数据，返回找到的指针，没有返回NULL
//插入函数
void Vector_push_back(Vector* vec, void* x);
void Vector_insert_nfront(Vector* vec, const void* p, const int n, const void* x);//数组中指向元素p前增加n个相同的元素x
void Vector_insert_front(Vector* vec, const void* p, const void* x);// 向量中指向元素p前增加一个元素x
void Vector_insert(Vector* vec, const void* p, const void* p1, const void* p2);// 向量中指向元素p前插入另一个相同类型向量的指针[p1,p2)间的数
//判断函数
bool Vector_empty(const Vector* vec);//检测vector内是否为空，空为真 O(1)
//返回大小函数
int Vector_lenth(const Vector* vec);//返回数组长度
int Vector_capacity(const Vector* vec);//返回容器容量
//初始化函数
void Vector_initial(Vector* vec,int type,unsigned int len);
//删除函数
void Vector_del_back(Vector* vec);//删除向量中最后一个元素
void Vector_del_p(Vector* vec, const void* p1, const void* p2);//删除指针区间内的数据
void Vector_del_int(Vector* vec, const int left, const int right);//删除区间内的数据
void Vector_clear(Vector* vec);//清空vector的数组，释放内存


/*
C语言实现map
*/
typedef struct map
{
	void* value;
	void* key;//键值
	unsigned int len;//map的大小
	unsigned int value_size;//数据类型字节数
	unsigned int key_size;
	unsigned int cap;//实际申请的大小
}Map;
void Map_capacity(Map* map);//检查容量
void Map_init(Map* map ,int cap ,int value_size,int key_size);//初始化
void Map_insert(Map* map,void* key, void* value);//插入key与元素
void Map_insert_arr(Map* map, void* key, void* value, size_t arr_len);//批量插入key与元素
void Map_print(Map* map);
void* Map_at(Map* map, void* key);//通过key查找并返回元素
void Map_clear(Map* map);
void Map_remove(Map* map, void* key);
bool Map_find(Map* map, void* key);//检查由key对应的value



//简单实现stack
typedef struct stack_node {
	struct stack_node* next;
	void* data;
}stack_node;

typedef struct stack {
	struct stack_node* top;
	/* 表示栈的高度 */
	int length;
}stack;

/* 创建栈 */
stack* stack_create();
/* 入栈 */
stack* stack_push(stack* stack, void* data);
/* 出栈 */
void* stack_pop(stack* stack);
/* 清空栈中所有元素，但不清除栈本身 */
void stack_empty(stack* stack);
/* 清空栈中所有元素并删除栈 */
void stack_release(stack* stack);


//实现双向list

#define LIST_START_HEAD 0   //从表头到表尾遍历
#define LIST_START_TAIL 1  //从表尾到表头遍历
/* 链表节点 */
typedef struct list_node
{
	struct list_node* prev;   //前驱节点
	struct list_node* next;   //后继节点
	void* value;    //值
} list_node;

/* 链表 */
typedef struct list
{
	unsigned long length;    //表长度
	list_node* head;   //表头
	list_node* tail;    //表尾
} list;

/* 迭代器结构 */
typedef struct list_iter
{
	list_node* next;  //下一个节点
	int direction;    //方向
}list_iter;

/*创建节点*/
list_node* creatnode(int data);
/* 创建链表 */
list* list_create(void);
/* 创建一个迭代器 */
list_iter* list_get_iterator(list* list, int direction);
/* 返回链表下一个节点值 */
void* list_next(list_iter* iter);
/* 释放迭代器内存 */
void list_release_iterator(list_iter* iter);
/* 添加一个节点在链表头部 */
list* list_add_node_head(list* list, void* value);
/* 添加一个节点在链表尾部 */
list* list_add_node_tail(list* list, void* value);
/* 删除一个节点 */
void list_del_node(list* list, list_node* node);
/* 获取头部元素 */
void* list_get_value_head(list* list);
/* 获取尾部元素 */
void* list_get_value_tail(list* list);
/* 清空链表中所有的节点但是不删除链表本身 */
void list_empty(list* list);
/* 释放整个链表 */
void list_release(list* list);



	//图
#define MAX_VERTICES 100
// 定义顶点结构体
typedef struct Vertex
{
	void* data;      // 存储顶点的数据
	bool visited;    // 访问标记,避免重复访问同一个节点 
} Vertex;
// 定义边结构体
typedef struct Edge
{
	int start;       // 边的起始顶点索引
	int end;         // 边的终止顶点索引
} Edge;
// 定义图结构体
typedef struct Graph
{
	int numVertices;           // 顶点数量
	int numEdges;              // 边数量
	Vertex* vertices[MAX_VERTICES];  // 顶点数组
	Edge* edges[MAX_VERTICES];       // 边数组
	int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];  // 邻接矩阵（判断是否有边） 
} Graph;

// 创建新顶点
Vertex* createVertex(void* data);
// 创建新边
Edge* createEdge(int start, int end);
// 创建图
Graph* createGraph();
// 添加顶点
void addVertex(Graph* graph, void* data);
// 添加边
void addEdge(Graph* graph, int start, int end);
// 深度优先搜索（DFS）
void dfs(Graph* graph, int vertexIndex, void (*print)(void*));
// 广度优先搜索（BFS）
void bfs(Graph* graph, int start, void (*print)(void*));
// 打印整数
void printInt(void* data);
// 打印浮点数
void printFloat(void* data);
// 打印字符
void printChar(void* data);



	//二叉树
	// 定义二叉树节点
	// 定义二叉树节点
typedef struct TreeNode
{
	void* data; // 泛型数据指针
	struct TreeNode* left; // 左子树指针
	struct TreeNode* right; // 右子树指针
} TreeNode;
// 创建新节点
TreeNode* createNode(void* data);
// 插入节点
void insert(TreeNode** root, void* data, int (*compare)(const void*, const void*));
// 先序遍历:根->左->右 
void preOrder(TreeNode* root, void (*visit)(void*));
// 中序遍历:左->根->右 
void inOrder(TreeNode* root, void (*visit)(void*));
// 后序遍历:左->右->根 
void postOrder(TreeNode* root, void (*visit)(void*));
// 查找节点
TreeNode* search(TreeNode* root, void* key, int (*compare)(const void*, const void*));
// 比较函数：整型
int compareInt(const void* a, const void* b);
// 比较函数：浮点型
int compareFloat(const void* a, const void* b);
// 比较函数：字符型
int compareChar(const void* a, const void* b);
// 访问函数：打印整型数据
void tree_printInt(void* data);
// 访问函数：打印浮点型数据
void tree_printFloat(void* data);
// 访问函数：打印字符型数据
void tree_printChar(void* data);
//释放内存 
void freeTree(TreeNode* node);

	/*
	通用函数
	*/
void swap(void* val_1, void* val_2, int size);
void my_qsort(list_iter* iter, int num, int size, int (*compare)(const void*, const void*));
void vector_reverse(Vector* vector);
void list_reverse(list* p, int size);
void print(void* data_structure, int flag, int data_type);
