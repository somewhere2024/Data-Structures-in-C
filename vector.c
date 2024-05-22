/*
vector各个函数实现
*/
#include"MYSTL.h"

/// <summary>
/// 判断容量是否管够
/// </summary>
/// <param name="vec">传入需判断的容器</param>
void capacity(Vector* vec)
{
	if (vec->len == 0)
	{
		vec->date = malloc(vec->type * MINCAP);
		if (vec->date == NULL)
		{
			perror("初始化vector失败");
			exit(-1);
		}
		else
		{
			vec->cap = MINCAP;
		}
	}
	else if (vec->len == vec->cap)//空间已满需要扩容
	{
		void* _date = realloc(vec->date, (vec->cap + MINCAP) * vec->type);//_date的地址将要赋给vec->date
		if (_date == NULL)
		{
			perror("扩容失败vector");
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
/// 初始化容器
/// </summary>
/// <param name="vec"></param>
/// <param name="type">单个数据的字节数</param>
/// <param name="len">数组长度</param>
void Vector_initial(Vector* vec, int type, unsigned int len)
{
	if (len)
	{
		vec->date = calloc(len, type);//新申请的内存可以初始化为0
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
/// 支持下标遍历函数
/// </summary>
/// <param name="vec">数组名</param>
/// <param name="i">下标</param>
/// <returns></returns>
void* Vector_at(const Vector* vec, int i)//支持遍历函数
{
	if (i + 1 > vec->len || i < 0)//判断i的合法性
	{
		return NULL;
	}
	return (void*)((char*)vec->date + vec->type * i);//date为第一个元素的地址
}
/// <summary>
/// 返回头指针
/// </summary>
/// <param name="vec"></param>
/// <returns></returns>
void* Vector_front(const Vector* vec)
{
	return (void*)vec->date;
}
/// <summary>
/// 返回尾指针
/// </summary>
/// <param name="vec"></param>
/// <returns></returns>
void* Vector_back(const Vector* vec)
{
	char* date_back = (char*)vec->date + vec->type * (vec->len - 1);
	return (void*)date_back;
}
/// <summary>
/// 查找元素，返回该元素，没有则返回NULL
/// </summary>
/// <param name="vec">传入的容器</param>
/// <param name="val">需要查找的数据</param>
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
	return NULL;//没有找到返回空
}

/// <summary>
/// 判断函数是否为空
/// </summary>
/// <param name="vec">传入的容器</param>
/// <returns></returns>
bool Vector_empty(const Vector* vec)//检测vector内是否为空，空为真 O(1)
{
	if (!vec->len)
		return true;
	else
		return false;
}

//返回大小函数
int Vector_capacity(const Vector* vec)
{
	return vec->cap;
}
int Vector_lenth(const Vector* vec)
{
	return vec->len;
}

/// <summary>
/// 尾部追加
/// </summary>
/// <param name="vec">传入的容器</param>
/// <param name="x">追加的数据</param>
void Vector_push_back(Vector* vec, void* x)//向容器尾部插入一个元素X
{
	capacity(vec);
	char* str1 = (char*)vec->date + vec->type * vec->len;//str1储存的vec->date尾部的地址
	/*
	memcpy()的使用:
	如果目标数组destin本身已有数据，执行memcpy（）后，将覆盖原有数据（最多覆盖n）。
	如果要追加数据，则每次执行memcpy后，要将目标数组地址增加到你要追加数据的地址。
	*/
	memcpy(str1, x, vec->type);//内存拷贝过后str1还是void*类型
	vec->len++;
}
/// <summary>
/// 指定位置之前插入n个“x”
/// </summary>
/// <param name="vec">传入的容器</param>
/// <param name="p">指定的位置指针</param>
/// <param name="n">插入个数</param>
/// <param name="x">插入的数据</param>
void Vector_insert_nfront(Vector* vec, const void* p, const int n, const void* x)// 数组中指向元素p前增加n个相同的元素x
{
	if (p >= Vector_front(vec) && p <= Vector_back(vec))//判断p所指向的位置是否合法
	{
		capacity(vec);
		int size = (char*)Vector_back(vec) - p + vec->type;//指向char类型的指针加减的基本单位为1
		void* ptr = malloc(size);
		if (!ptr)
		{
			exit(1);
		}
		memcpy(ptr, p, size);//先把p处以后的数据内存拷贝到ptr指向的内存中
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
		memcpy((char*)Vector_at(vec, sizen), ptr, size);//将p处以后的元素
		free(ptr);
	}
}
/// <summary>
/// 向指定位置插入“x”
/// </summary>
/// <param name="vec">传入的容器</param>
/// <param name="p">指定的位置指针</param>
/// <param name="x">插入的元素</param>
void Vector_insert_front(Vector* vec, const void* p, const void* x)
{
	capacity(vec);
	if (p >= Vector_front(vec) && p <= Vector_back(vec))
	{
		int size = (char*)Vector_back(vec) - p + vec->type;
		void* ptr = malloc(size);
		if (ptr == NULL)
		{
			printf("分配内存失败");
			exit(1);
		}
		memcpy(ptr, p, size);
		memcpy(p, x, vec->type);
		memcpy((char*)p + vec->type, ptr, size);//拷贝p位置之后的数据
		vec->len++;
		free(ptr);
	}
}

/// <summary>
/// 向量中指向元素p前插入另一个相同类型向量的指针[p1,p2)间的数
/// </summary>
/// <param name="vec">传入的容器</param>
/// <param name="p">指定的位置指针</param>
/// <param name="p1">插入数据开始处</param>
/// <param name="p2">插入数据结尾处</param>
void Vector_insert(Vector* vec, const void* p, const void* p1, const void* p2)
{
	if (p >= Vector_front(vec) && p <= Vector_back(vec))
	{
		capacity(vec);
		int size = (char*)Vector_back(vec) - p + vec->type;
		void* ptr = malloc(size);
		if (!ptr)
		{
			printf("申请内存失败");
			exit(1);
		}
		memcpy(ptr, p, size);
		int sizen = ((char*)p - Vector_front(vec)) / vec->type;
		int push_n = ((char*)p2 - (char*)p1) / vec->type + 1;
		for (unsigned int i = 0; i < push_n; i++)
		{
			capacity(vec);
			memcpy((char*)Vector_at(vec, sizen), (char*)p1 + i * vec->type, vec->type);//内存拷贝
			sizen++;
			vec->len++;
		}
		memcpy((char*)Vector_at(vec, sizen), ptr, size);//将覆盖的元素添加回来

		free(ptr);
	}
}
/// <summary>
/// 删除尾部元素
/// </summary>
/// <param name="vec"></param>
void Vector_del_back(Vector* vec)//删除向量中最后一个元素
{
	vec->len--;
}

/// <summary>
/// 删除指针区间内的元素
/// </summary>
/// <param name="vec">传入的容器</param>
/// <param name="p1">删除起始位置</param>
/// <param name="p2">删除末尾位置</param>
void Vector_del_p(Vector* vec, const void* p1, const void* p2)
{
	if (p1 <= p2 && Vector_front(vec) <= p1 && p2 <= Vector_back(vec))
	{
		memcpy(p1, (char*)p2 + vec->type, (int)((char*)Vector_back(vec) - (char*)p2));//将p2之后的元素拷贝到前面来
		vec->len -= (((int)((char*)p2 - (char*)p1)) / vec->type + 1);
	}
}

/// <summary>
/// 删除区间内的元素
/// </summary>
/// <param name="vec">传入的容器</param>
/// <param name="left">删除起始下标位置</param>
/// <param name="right">删除末尾下标位置</param>
void Vector_del_int(Vector* vec, const int left, const int right)
{
	if (left < right && left >= Vector_front(vec) && right <= Vector_back(vec))
	{
		memcpy(Vector_at(vec, left), Vector_at(vec, right + 1), (vec->len - 1 - right) * vec->type);
		vec->len -= (right - left + 1);
	}
}

/// <summary>
/// 清空动态数组,释放内存
/// </summary>
/// <param name="vec">需要清空的动态数组</param>
void Vector_clear(Vector* vec)
{
	free(vec->date);
	vec->date = NULL;
	vec->len = 0;
	vec->cap = 0;
}