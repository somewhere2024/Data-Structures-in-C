#include"MYSTL.h"
/*
   �����ļ�
*/

//�����߼�����
int cmp(const void* a, const void* b) 
{
	return *(int*)a - *(int*)b;
}


int main(void)
{
	/*
	Vector vec;
	int size_init;
	printf("������������ʼ���Ĵ�С��");
	scanf("%d", &size_init);
	Vector_initial(&vec, sizeof(int), size_init);

	printf("������%d������:\n", size_init);
	int* b = Vector_front(&vec);
	for (int i = 0; i < vec.len; i++)
	{
		scanf("%d", (int*)Vector_at(&vec,i));
	}
	printf("����֮ǰ��");
	*/
	/*for (int i = 0; i < vec.len; i++)
	{
		printf("%d\n", *((int*)b + i));
	}*/
	
	/*
	print(&vec, 1, INT_TYPE);//ͨ�ô�ӡ����
	qsort(Vector_front(&vec), 5, 4, cmp);
	printf("����֮��\n");
	for (int i = 0; i < vec.len; i++)
	{
		printf("%d\n", *(int*)Vector_at(&vec, i));
	}
	vector_reverse(&vec);
	printf("����֮��\n");
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
	printf("ʹ��map_at������ӡ��");
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", *((int*)Map_at(&mymap,a+i)));
	}
	int key;
	printf("��������Ҫɾ����value��key:");
	scanf("%d", &key);
	//�Ƴ�ָ������
	Map_remove(&mymap, &key);
	printf("ɾ��֮��");
	Map_print(&mymap, INT_TYPE);
	printf("�ٴβ���ɾ�������ݣ�����Ƿ�ɾ��(0��ʾɾ���ɹ�)��");
	printf("%d\n", Map_find(&mymap,&key));//0��δ�ҵ�

	Map_clear(&mymap);
	return 0;
	

	/*
	//����list
	//��������
	char a = 'A';
	char b = 'B';
	char c = 'C';
	//��������
	list* list = list_create();
	//���Կձ��Ƿ񱨴�
	printf("-----���Կ������Ƿ񱨴�\n");
	printf("%p\n", list_get_value_head(list));
	printf("%p\n", list_get_value_tail(list));
	//��ͷ�������
	list_add_node_head(list, &a);
	list_add_node_head(list, &b);
	//��β�������
	list_add_node_tail(list, &c);
	list_add_node_tail(list, &a);
	printf("-----��ʱ�����ȣ�%d\n", list->length);
	printf("-----���Ա�ͷ����-----\n");
	//�ȳ������Σ����Ա�ͷ����
	while (list->length > 2)
	{
		printf("%c\n", *(char*)list_get_value_head(list));
	}
	printf("-----���Ա�β����-----\n");
	//���Ա�β����
	while (list->length)
	{
		printf("%c\n", *(char*)list_get_value_tail(list));
	}
	//������� 
	list_add_node_head(list, &a);
	list_add_node_head(list, &b);
	list_add_node_head(list, &c);
	//����һ�����������������
	list_iter* iter = list_get_iterator(list, LIST_START_HEAD);
	//���Ե�����
	printf("-----���Ե�����-------\n");
	printf("%c\n", *(char*)list_next(iter));
	printf("%c\n", *(char*)list_next(iter));
	printf("%c\n", *(char*)list_next(iter));
	//�ͷŵ�����
	list_release_iterator(iter);
	//�������ڵ�
	list_empty(list);
	printf("-----���Կ������Ƿ񱨴�\n");
	printf("%p\n", list_get_value_head(list));
	printf("%p\n", list_get_value_tail(list));
	// �ͷ����� 
	list_release(list);
	return 0;
	*/


	/*
	//����stack
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


	//������
	/*
	TreeNode* root = NULL;

	// ������������
	int data1 = 2, data2 = 3, data3 = 1, data4 = 5, data5 = 4;
	insert(&root, &data1, compareInt);
	insert(&root, &data2, compareInt);
	insert(&root, &data3, compareInt);
	insert(&root, &data4, compareInt);
	insert(&root, &data5, compareInt);

	// �����������ӡ��������
	printf("��������: ");
	preOrder(root, printInt);
	printf("\n");

	// �����������ӡ��������
	printf("��������: ");
	inOrder(root, printInt);
	printf("\n");

	// �����������ӡ��������
	printf("��������: ");
	postOrder(root, printInt);
	printf("\n");

	// ������������
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

	// ���������ݲ���
	TreeNode* root_float = NULL;

	float fdata1 = 5.5, fdata2 = 3.7, fdata3 = 1.3, fdata4 = 2.8, fdata5 = 4.4;
	insert(&root_float, &fdata1, compareFloat);
	insert(&root_float, &fdata2, compareFloat);
	insert(&root_float, &fdata3, compareFloat);
	insert(&root_float, &fdata4, compareFloat);
	insert(&root_float, &fdata5, compareFloat);

	// �����������ӡ����������
	printf("���򸡵���: ");
	preOrder(root_float, printFloat);
	printf("\n");

	// �����������ӡ����������
	printf("���򸡵���: ");
	inOrder(root_float, printFloat);
	printf("\n");

	// �����������ӡ����������
	printf("���򸡵���: ");
	postOrder(root_float, printFloat);
	printf("\n");

	// ���Ҹ���������
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

	// �����������ӡ�ַ�������
	printf("�����ַ���: ");
	preOrder(root_char, printChar);
	printf("\n");

	// �����������ӡ�ַ�������
	printf("�����ַ���: ");
	inOrder(root_char, printChar);
	printf("\n");

	// �����������ӡ�ַ�������
	printf("�����ַ���: ");
	postOrder(root_char, printChar);
	printf("\n");

	// �����ַ�������
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