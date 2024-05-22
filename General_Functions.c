#include"MYSTL.h"


//通用交换函数
void swap(void* val_1, void* val_2,int size)
{
	void* temp = malloc(size);
	assert(temp != NULL);
	
	memcpy(temp, val_1, size);
	memcpy(val_1, val_2, size);
	memcpy(val_2, temp, size);

	free(temp);
}


/// <summary>
/// 为节点排序
/// </summary>
/// <param name="list_iter">节点迭代器</param>
/// <param name="num">节点个数</param>
/// <param name="size">单个数据的字节大小</param>
/// <param name="compare">逻辑比较函数</param>
void my_qsort(list_iter* iter, int num, int size, int (*compare)(const void*, const void*))
{
	int i, j;
	void* temp = malloc(size);
	for (i = 0; i < num-1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			if (compare(iter->next->value, iter->next->next->value) > 0)//大于零升序排序
			{
				swap(iter->next->next->value, iter->next->value, size);
			}
			list_next(iter);//指向下一个节点继续排序
		}
	}
	free(temp);
}

/// <summary>
/// vector逆序函数
/// </summary>
/// <param name="vector">传入的vector地址</param>
void vector_reverse(Vector *vector)
{
	int i, j;
	char* p = vector->date;
	void* temp = malloc(vector->type);
	for (i = 0,j = vector->len-1; i<=j; i++,j--)
	{
		swap(p+i * vector->type, p + j * vector->type, vector->type);
	}
}
/// <summary>
/// 链表逆序函数
/// </summary>
/// <param name="p">list指针</param>
/// <param name="size">单个data的字节数</param>
void list_reverse(list* p,int size)
{
	list_iter* p1, *p2;
	p1 = list_get_iterator(p ,0 );//正向迭代器
	p2 = list_get_iterator(p, 1);//逆向迭代器
	int i, j;
	for (i = 0, j = p->length; i <= j; i++, j--)
	{
		swap(p1->next->value, p2->next->value, size);
		list_next(p1);
		list_next(p2);
	}
}

/// <summary>
/// list\vector通用输出函数
/// </summary>
/// <param name="data_structure">数据结构类型</param>
/// <param name="flag">数据结构类型标记</param>
/// <param name="data_type">数据类型标志</param>
void print(void* data_structure, int flag, int data_type)
{
	if (flag == 1)//为vector
	{
		Vector* p = data_structure;
		int i, j;
		printf("\n{vector}:");
		for (i = 0; i < p->len; i++)
		{
			switch (data_type) 
			{
			case INT_TYPE:
				printf(" %d", *(int*)((char*)p->date+i*p->type));
				break;
			case FLOAT_TYPE:
				printf(" %f", *(float*)((char*)p->date + i * p->type));
				break;
			case CHAR_TYPE:
				printf(" %c", *(char*)((char*)p->date + i * p->type));
				break;
			default:
				printf("Unknown type\n");
				break;
			}
		}
		printf("\n");
	}
	if (flag == 2)
	{
		list* p = data_structure;
		int i;
		list_iter* x = list_get_iterator(p, 0);
		printf("list:");
		for (i = 0; i < p->length; i++)
		{
			switch (data_type)
			{
			case INT_TYPE:
				printf("%d\n", *(int*)(x->next->value));
				break;
			case FLOAT_TYPE:
				printf("%f\n", *(float*)(x->next->value));
				break;
			case CHAR_TYPE:
				printf("%c\n", *(char*)(x->next->value));
				break;
			default:
				printf("Unknown type\n");
				break;

				list_next(p);
			}
		}
	}
}