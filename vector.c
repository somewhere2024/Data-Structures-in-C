/*
vector��������ʵ��
*/
#include"MYSTL.h"

/// <summary>
/// �ж������Ƿ�ܹ�
/// </summary>
/// <param name="vec">�������жϵ�����</param>
void capacity(Vector* vec)
{
	if (vec->len == 0)
	{
		vec->date = malloc(vec->type * MINCAP);
		if (vec->date == NULL)
		{
			perror("��ʼ��vectorʧ��");
			exit(-1);
		}
		else
		{
			vec->cap = MINCAP;
		}
	}
	else if (vec->len == vec->cap)//�ռ�������Ҫ����
	{
		void* _date = realloc(vec->date, (vec->cap + MINCAP) * vec->type);//_date�ĵ�ַ��Ҫ����vec->date
		if (_date == NULL)
		{
			perror("����ʧ��vector");
			exit(-1);
		}
		else
		{
			vec->date = _date;
			vec->cap += MINCAP;
		}
	}
}
/// <summary>
/// ��ʼ������
/// </summary>
/// <param name="vec"></param>
/// <param name="type">�������ݵ��ֽ���</param>
/// <param name="len">���鳤��</param>
void Vector_initial(Vector* vec, int type, unsigned int len)
{
	if (len)
	{
		vec->date = calloc(len, type);//��������ڴ���Գ�ʼ��Ϊ0
		vec->cap = len;
		vec->len = len;
		vec->type = type;
	}
	else
	{
		vec->date = NULL;
		vec->len = 0;
		vec->cap = 0;
		vec->type = type;
	}

}

/// <summary>
/// ֧���±��������
/// </summary>
/// <param name="vec">������</param>
/// <param name="i">�±�</param>
/// <returns></returns>
void* Vector_at(const Vector* vec, int i)//֧�ֱ�������
{
	if (i + 1 > vec->len || i < 0)//�ж�i�ĺϷ���
	{
		return NULL;
	}
	return (void*)((char*)vec->date + vec->type * i);//dateΪ��һ��Ԫ�صĵ�ַ
}
/// <summary>
/// ����ͷָ��
/// </summary>
/// <param name="vec"></param>
/// <returns></returns>
void* Vector_front(const Vector* vec)
{
	return (void*)vec->date;
}
/// <summary>
/// ����βָ��
/// </summary>
/// <param name="vec"></param>
/// <returns></returns>
void* Vector_back(const Vector* vec)
{
	char* date_back = (char*)vec->date + vec->type * (vec->len - 1);
	return (void*)date_back;
}
/// <summary>
/// ����Ԫ�أ����ظ�Ԫ�أ�û���򷵻�NULL
/// </summary>
/// <param name="vec">���������</param>
/// <param name="val">��Ҫ���ҵ�����</param>
/// <returns></returns>
void* Vector_find(const Vector* vec, const void* val)
{
	int i = 0;
	for (i = 0; i < vec->len; i++)
	{
		if (memcmp(Vector_at(vec, i), val, vec->type) == 0)
		{
			return Vector_at(vec, i);
		}
	}
	return NULL;//û���ҵ����ؿ�
}

/// <summary>
/// �жϺ����Ƿ�Ϊ��
/// </summary>
/// <param name="vec">���������</param>
/// <returns></returns>
bool Vector_empty(const Vector* vec)//���vector���Ƿ�Ϊ�գ���Ϊ�� O(1)
{
	if (!vec->len)
		return true;
	else
		return false;
}

//���ش�С����
int Vector_capacity(const Vector* vec)
{
	return vec->cap;
}
int Vector_lenth(const Vector* vec)
{
	return vec->len;
}

/// <summary>
/// β��׷��
/// </summary>
/// <param name="vec">���������</param>
/// <param name="x">׷�ӵ�����</param>
void Vector_push_back(Vector* vec, void* x)//������β������һ��Ԫ��X
{
	capacity(vec);
	char* str1 = (char*)vec->date + vec->type * vec->len;//str1�����vec->dateβ���ĵ�ַ
	/*
	memcpy()��ʹ��:
	���Ŀ������destin�����������ݣ�ִ��memcpy�����󣬽�����ԭ�����ݣ���า��n����
	���Ҫ׷�����ݣ���ÿ��ִ��memcpy��Ҫ��Ŀ�������ַ���ӵ���Ҫ׷�����ݵĵ�ַ��
	*/
	memcpy(str1, x, vec->type);//�ڴ濽������str1����void*����
	vec->len++;
}
/// <summary>
/// ָ��λ��֮ǰ����n����x��
/// </summary>
/// <param name="vec">���������</param>
/// <param name="p">ָ����λ��ָ��</param>
/// <param name="n">�������</param>
/// <param name="x">���������</param>
void Vector_insert_nfront(Vector* vec, const void* p, const int n, const void* x)// ������ָ��Ԫ��pǰ����n����ͬ��Ԫ��x
{
	if (p >= Vector_front(vec) && p <= Vector_back(vec))//�ж�p��ָ���λ���Ƿ�Ϸ�
	{
		capacity(vec);
		int size = (char*)Vector_back(vec) - p + vec->type;//ָ��char���͵�ָ��Ӽ��Ļ�����λΪ1
		void* ptr = malloc(size);
		if (!ptr)
		{
			exit(1);
		}
		memcpy(ptr, p, size);//�Ȱ�p���Ժ�������ڴ濽����ptrָ����ڴ���
		int sizen = ((char*)p - Vector_front(vec)) / vec->type;
		for (unsigned int i = 0; i < n; i++)
		{
			capacity(vec);
			memcpy((char*)Vector_at(vec, sizen), x, vec->type);
			sizen++;
			vec->len++;
		}
		if (vec->cap < (size / vec->type) + sizen)
		{
			vec = realloc(vec, vec->cap + (size / vec->type) + sizen);
		}
		memcpy((char*)Vector_at(vec, sizen), ptr, size);//��p���Ժ��Ԫ��
		free(ptr);
	}
}
/// <summary>
/// ��ָ��λ�ò��롰x��
/// </summary>
/// <param name="vec">���������</param>
/// <param name="p">ָ����λ��ָ��</param>
/// <param name="x">�����Ԫ��</param>
void Vector_insert_front(Vector* vec, const void* p, const void* x)
{
	capacity(vec);
	if (p >= Vector_front(vec) && p <= Vector_back(vec))
	{
		int size = (char*)Vector_back(vec) - p + vec->type;
		void* ptr = malloc(size);
		if (ptr == NULL)
		{
			printf("�����ڴ�ʧ��");
			exit(1);
		}
		memcpy(ptr, p, size);
		memcpy(p, x, vec->type);
		memcpy((char*)p + vec->type, ptr, size);//����pλ��֮�������
		vec->len++;
		free(ptr);
	}
}

/// <summary>
/// ������ָ��Ԫ��pǰ������һ����ͬ����������ָ��[p1,p2)�����
/// </summary>
/// <param name="vec">���������</param>
/// <param name="p">ָ����λ��ָ��</param>
/// <param name="p1">�������ݿ�ʼ��</param>
/// <param name="p2">�������ݽ�β��</param>
void Vector_insert(Vector* vec, const void* p, const void* p1, const void* p2)
{
	if (p >= Vector_front(vec) && p <= Vector_back(vec))
	{
		capacity(vec);
		int size = (char*)Vector_back(vec) - p + vec->type;
		void* ptr = malloc(size);
		if (!ptr)
		{
			printf("�����ڴ�ʧ��");
			exit(1);
		}
		memcpy(ptr, p, size);
		int sizen = ((char*)p - Vector_front(vec)) / vec->type;
		int push_n = ((char*)p2 - (char*)p1) / vec->type + 1;
		for (unsigned int i = 0; i < push_n; i++)
		{
			capacity(vec);
			memcpy((char*)Vector_at(vec, sizen), (char*)p1 + i * vec->type, vec->type);//�ڴ濽��
			sizen++;
			vec->len++;
		}
		memcpy((char*)Vector_at(vec, sizen), ptr, size);//�����ǵ�Ԫ����ӻ���

		free(ptr);
	}
}
/// <summary>
/// ɾ��β��Ԫ��
/// </summary>
/// <param name="vec"></param>
void Vector_del_back(Vector* vec)//ɾ�����������һ��Ԫ��
{
	vec->len--;
}

/// <summary>
/// ɾ��ָ�������ڵ�Ԫ��
/// </summary>
/// <param name="vec">���������</param>
/// <param name="p1">ɾ����ʼλ��</param>
/// <param name="p2">ɾ��ĩβλ��</param>
void Vector_del_p(Vector* vec, const void* p1, const void* p2)
{
	if (p1 <= p2 && Vector_front(vec) <= p1 && p2 <= Vector_back(vec))
	{
		memcpy(p1, (char*)p2 + vec->type, (int)((char*)Vector_back(vec) - (char*)p2));//��p2֮���Ԫ�ؿ�����ǰ����
		vec->len -= (((int)((char*)p2 - (char*)p1)) / vec->type + 1);
	}
}

/// <summary>
/// ɾ�������ڵ�Ԫ��
/// </summary>
/// <param name="vec">���������</param>
/// <param name="left">ɾ����ʼ�±�λ��</param>
/// <param name="right">ɾ��ĩβ�±�λ��</param>
void Vector_del_int(Vector* vec, const int left, const int right)
{
	if (left < right && left >= Vector_front(vec) && right <= Vector_back(vec))
	{
		memcpy(Vector_at(vec, left), Vector_at(vec, right + 1), (vec->len - 1 - right) * vec->type);
		vec->len -= (right - left + 1);
	}
}

/// <summary>
/// ��ն�̬����,�ͷ��ڴ�
/// </summary>
/// <param name="vec">��Ҫ��յĶ�̬����</param>
void Vector_clear(Vector* vec)
{
	free(vec->date);
	vec->date = NULL;
	vec->len = 0;
	vec->cap = 0;
}