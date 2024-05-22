#include"MYSTL.h"


//ͨ�ý�������
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
/// Ϊ�ڵ�����
/// </summary>
/// <param name="list_iter">�ڵ������</param>
/// <param name="num">�ڵ����</param>
/// <param name="size">�������ݵ��ֽڴ�С</param>
/// <param name="compare">�߼��ȽϺ���</param>
void my_qsort(list_iter* iter, int num, int size, int (*compare)(const void*, const void*))
{
	int i, j;
	void* temp = malloc(size);
	for (i = 0; i < num-1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			if (compare(iter->next->value, iter->next->next->value) > 0)//��������������
			{
				swap(iter->next->next->value, iter->next->value, size);
			}
			list_next(iter);//ָ����һ���ڵ��������
		}
	}
	free(temp);
}

/// <summary>
/// vector������
/// </summary>
/// <param name="vector">�����vector��ַ</param>
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
/// ����������
/// </summary>
/// <param name="p">listָ��</param>
/// <param name="size">����data���ֽ���</param>
void list_reverse(list* p,int size)
{
	list_iter* p1, *p2;
	p1 = list_get_iterator(p ,0 );//���������
	p2 = list_get_iterator(p, 1);//���������
	int i, j;
	for (i = 0, j = p->length; i <= j; i++, j--)
	{
		swap(p1->next->value, p2->next->value, size);
		list_next(p1);
		list_next(p2);
	}
}

/// <summary>
/// list\vectorͨ���������
/// </summary>
/// <param name="data_structure">���ݽṹ����</param>
/// <param name="flag">���ݽṹ���ͱ��</param>
/// <param name="data_type">�������ͱ�־</param>
void print(void* data_structure, int flag, int data_type)
{
	if (flag == 1)//Ϊvector
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