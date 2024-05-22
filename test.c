#include"MYSTL.h"
/*
   测试文件
*/

//排序逻辑函数
int cmp(const void* a, const void* b) 
{
	return *(int*)a - *(int*)b;
}


int main(void)
{
	/*
	Vector vec;
	int size_init;
	printf("请输入容器初始化的大小：");
	scanf("%d", &size_init);
	Vector_initial(&vec, sizeof(int), size_init);

	printf("请输入%d个数据:\n", size_init);
	int* b = Vector_front(&vec);
	for (int i = 0; i < vec.len; i++)
	{
		scanf("%d", (int*)Vector_at(&vec,i));
	}
	printf("排序之前：");
	*/
	/*for (int i = 0; i < vec.len; i++)
	{
		printf("%d\n", *((int*)b + i));
	}*/
	
	/*
	print(&vec, 1, INT_TYPE);//通用打印函数
	qsort(Vector_front(&vec), 5, 4, cmp);
	printf("排序之后：\n");
	for (int i = 0; i < vec.len; i++)
	{
		printf("%d\n", *(int*)Vector_at(&vec, i));
	}
	vector_reverse(&vec);
	printf("逆序之后：\n");
	for (int i = 0; i < vec.len; i++)
	{
		printf("%d\n", *(int*)Vector_at(&vec, i));
	}
	Vector_clear(&vec);
	return 0;
	*/
	


	
	Map mymap;
	Map_init(&mymap, 0, 4, 4);
	int a[5] = { 1,2,3,4,5 }, b[5] = { 1,2,3,4,5 };
	Map_insert_arr(&mymap,a, b,5);
	printf("使用map_at便利打印：");
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", *((int*)Map_at(&mymap,a+i)));
	}
	int key;
	printf("输入你想要删除的value的key:");
	scanf("%d", &key);
	//移除指定数据
	Map_remove(&mymap, &key);
	printf("删除之后：");
	Map_print(&mymap, INT_TYPE);
	printf("再次查找删除的数据，检查是否删除(0表示删除成功)：");
	printf("%d\n", Map_find(&mymap,&key));//0表未找到

	Map_clear(&mymap);
	return 0;
	

	/*
	//测试list
	//测试数据
	char a = 'A';
	char b = 'B';
	char c = 'C';
	//创建链表
	list* list = list_create();
	//测试空表是否报错
	printf("-----测试空链表是否报错\n");
	printf("%p\n", list_get_value_head(list));
	printf("%p\n", list_get_value_tail(list));
	//表头添加数据
	list_add_node_head(list, &a);
	list_add_node_head(list, &b);
	//表尾添加数据
	list_add_node_tail(list, &c);
	list_add_node_tail(list, &a);
	printf("-----此时链表长度：%d\n", list->length);
	printf("-----测试表头出队-----\n");
	//先出队两次，测试表头出队
	while (list->length > 2)
	{
		printf("%c\n", *(char*)list_get_value_head(list));
	}
	printf("-----测试表尾出队-----\n");
	//测试表尾出队
	while (list->length)
	{
		printf("%c\n", *(char*)list_get_value_tail(list));
	}
	//添加数据 
	list_add_node_head(list, &a);
	list_add_node_head(list, &b);
	list_add_node_head(list, &c);
	//创建一个正向迭代器迭代器
	list_iter* iter = list_get_iterator(list, LIST_START_HEAD);
	//测试迭代器
	printf("-----测试迭代器-------\n");
	printf("%c\n", *(char*)list_next(iter));
	printf("%c\n", *(char*)list_next(iter));
	printf("%c\n", *(char*)list_next(iter));
	//释放迭代器
	list_release_iterator(iter);
	//清除链表节点
	list_empty(list);
	printf("-----测试空链表是否报错\n");
	printf("%p\n", list_get_value_head(list));
	printf("%p\n", list_get_value_tail(list));
	// 释放链表 
	list_release(list);
	return 0;
	*/


	/*
	//测试stack
	char a = 'a';
	char b = 'b';
	char c = 'c';
	stack* stack = stack_create();
	stack_push(stack, &a);
	stack_push(stack, &b);
	stack_push(stack, &c);
	while (stack->length > 0)
	{
		printf("%c\n", *(char*)stack_pop(stack));
	}

	stack_push(stack, &a);
	stack_empty(stack);

	stack_release(stack);

	return 0;
	*/


	//二叉树
	/*
	TreeNode* root = NULL;

	// 插入整型数据
	int data1 = 2, data2 = 3, data3 = 1, data4 = 5, data5 = 4;
	insert(&root, &data1, compareInt);
	insert(&root, &data2, compareInt);
	insert(&root, &data3, compareInt);
	insert(&root, &data4, compareInt);
	insert(&root, &data5, compareInt);

	// 先序遍历并打印整型数据
	printf("先序整型: ");
	preOrder(root, printInt);
	printf("\n");

	// 中序遍历并打印整型数据
	printf("中序整型: ");
	inOrder(root, printInt);
	printf("\n");

	// 后序遍历并打印整型数据
	printf("后序整型: ");
	postOrder(root, printInt);
	printf("\n");

	// 查找整型数据
	int key = 3;
	TreeNode* result = search(root, &key, compareInt);
	if (result != NULL)
	{
		printf("Found %d\n", *(int*)result->data);
	}
	else
	{
		printf("Not found\n");
	}

	freeTree(root);

	// 浮点型数据测试
	TreeNode* root_float = NULL;

	float fdata1 = 5.5, fdata2 = 3.7, fdata3 = 1.3, fdata4 = 2.8, fdata5 = 4.4;
	insert(&root_float, &fdata1, compareFloat);
	insert(&root_float, &fdata2, compareFloat);
	insert(&root_float, &fdata3, compareFloat);
	insert(&root_float, &fdata4, compareFloat);
	insert(&root_float, &fdata5, compareFloat);

	// 先序遍历并打印浮点型数据
	printf("先序浮点型: ");
	preOrder(root_float, printFloat);
	printf("\n");

	// 中序遍历并打印浮点型数据
	printf("中序浮点型: ");
	inOrder(root_float, printFloat);
	printf("\n");

	// 后序遍历并打印浮点型数据
	printf("后序浮点型: ");
	postOrder(root_float, printFloat);
	printf("\n");

	// 查找浮点型数据
	float fkey = 3.3;
	TreeNode* fresult = search(root_float, &fkey, compareFloat);
	if (fresult != NULL)
	{
		printf("Found %f\n", *(float*)fresult->data);
	}
	else
	{
		printf("Not found\n");
	}

	freeTree(root_float);

	TreeNode* root_char = NULL;

	char cdata1 = 'e', cdata2 = 'c', cdata3 = 'a', cdata4 = 'b', cdata5 = 'd';
	insert(&root_char, &cdata1, compareChar);
	insert(&root_char, &cdata2, compareChar);
	insert(&root_char, &cdata3, compareChar);
	insert(&root_char, &cdata4, compareChar);
	insert(&root_char, &cdata5, compareChar);

	// 先序遍历并打印字符型数据
	printf("先序字符型: ");
	preOrder(root_char, printChar);
	printf("\n");

	// 中序遍历并打印字符型数据
	printf("中序字符型: ");
	inOrder(root_char, printChar);
	printf("\n");

	// 后序遍历并打印字符型数据
	printf("后序字符型: ");
	postOrder(root_char, printChar);
	printf("\n");

	// 查找字符型数据
	char ckey = 'c';
	TreeNode* cresult = search(root_char, &ckey, compareChar);
	if (cresult != NULL)
	{
		printf("Found %c\n", *(char*)cresult->data);
	}
	else
	{
		printf("Not found\n");
	}
	freeTree(root_char);
	return 0;
	*/


	
}