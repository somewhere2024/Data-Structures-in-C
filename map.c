#include"MYSTL.h"

/*
map各个函数的实现
*/


/// <summary>
/// 检查map的容量
/// </summary>
/// <param name="map"></param>
void Map_capacity(Map* map)
{
	if (map->len == 0)
	{
		map->value = malloc(map->value_size * MIN_map_cap);
		map->key = malloc(map->key_size * MIN_map_cap);
		if (map->value== NULL||map->key == NULL)
		{
			perror("初始化vector失败");
			exit(-1);
		}
		else
		{
			map->cap = MINCAP;
		}
	}
	else if (map->len == map->cap)//空间已满需要扩容
	{
		void* _value = realloc(map->value, (map->cap + MIN_map_cap) * map->value_size);
		void* _key = realloc(map->key, (map->cap + MIN_map_cap) * map->key_size);
		if (_value == NULL||_key == NULL)
		{
			perror("扩容失败vector");
			exit(-1);
		}
		else
		{
			map->value = _value;
			map->key = _key;
			map->cap += MIN_map_cap;
		}
	}
}

/// <summary>
/// 初始化map
/// </summary>
/// <param name="map">传入的map指针</param>
/// <param name="len">需要的长度</param>
/// <param name="value_size">单个数据的大小</param>
/// <param name="key_size">单个key的大小</param>
void Map_init(Map* map, int cap ,int value_size,int key_size)
{
	map->key = calloc(cap, key_size);
	map->value = calloc(cap, value_size);
	map->cap = cap;
	map->len = 0;
	map->value_size = value_size;
	map->key_size = key_size;
}

/// <summary>
/// 单个插入元素函数
/// </summary>
/// <param name="map">传入的map指针</param>
/// <param name="key">单个key</param>
/// <param name="value">单个value</param>
void Map_insert(Map *map, void* key, void* value)
{
	Map_capacity(map);
	memcpy((char*)map->key+map->len*map->key_size, key, map->key_size);
	memcpy((char*)map->value+map->value_size, value, map->value_size);
	map->len ++;
}

/// <summary>
/// 批量插入元素函数
/// </summary>
/// <param name="map">传入的map指针</param>
/// <param name="key">key数组</param>
/// <param name="value">value数组</param>
/// <param name="arr_len">数组长度</param>
void Map_insert_arr(Map* map, void* key, void* value,size_t arr_len)
{
	Map_capacity(map);
	int i;
	for (i = 0; i < arr_len; i++)
	{
		memcpy((char*)map->key + map->len * map->key_size, (char*)key+i*map->key_size, map->key_size);
		memcpy((char*)map->value +map->len * map->value_size,(char*)value+i*map->value_size, map->value_size);
		map->len++;
	}
}
/// <summary>
/// 键值查找value
/// </summary>
/// <param name="map">map指针</param>
/// <param name="key">key指针</param>
/// <returns></returns>
void* Map_at(Map* map, void* key)
{
	int i;
	for (i = 0; i < map->len; i++)
	{
		int flag = memcmp((char*)map->key + i * map->key_size, key, map->key_size);
		if (flag == 0)//找到value
		{
			return (char*)map->value + i * map->value_size;
		}
	}
	return - 1;//没找到
}

/// <summary>
/// 清空map函数
/// </summary>
/// <param name="map"></param>
void Map_clear(Map* map)
{
	if (map == NULL)
		exit(-1);
	free(map->key);
	free(map->value);
	map->key = NULL;
	map->value = NULL;
	map->cap = 0;
	map->len = 0;
	map->key_size = 0;
	map->value_size = 0;
}
/// <summary>
/// 由key删value函数
/// </summary>
/// <param name="map"></param>
/// <param name="key"></param>
void Map_remove(Map* map, void* key)
{
	int i,flag = 0;
	for (i = 0; i < map->len; i++)
	{
		flag = memcmp((char*)map->key + i * map->key_size, key, map->key_size);
		if (flag == 0)
		{
			memcpy((char*)map->value+i*map->value_size, (char*)map->value + (i + 1) * map->value_size,(map->len-i-1)*map->value_size);
			memcpy((char*)map->key + i * map->key_size, (char*)map->key + (i + 1) * map->key_size, (map->len - i - 1) * map->key_size);
			map->len--;
		}
	}
}

/// <summary>
/// 检查key有无对应的value
/// </summary>
/// <param name="map">传入map指针</param>
/// <param name="key">key值</param>
/// <returns></returns>
bool Map_find(Map* map, void* key)
{
	int i, flag = 1;
	for (i = 0; i < map->len; i++)
	{
		flag = memcmp((char*)map->key + i * map->key_size, key, map->key_size);//找到相等的则返回0
	}
	if (flag == 0)//0表示找到
		return true;
	if (flag == 1)
	return false;
}

void Map_print(Map* map,int data_type)
{
	
	int i, j;
	Map* p = map;
	printf("{map}:");
	for (i = 0; i < p->len; i++)
	{
		switch (data_type)
		{
		case INT_TYPE:
			printf(" %d", *(int*)((char*)p->value + i * p->value_size));
			break;
		case FLOAT_TYPE:
			printf(" %f", *(float*)((char*)p->value + i * p->value_size));
			break;
		case CHAR_TYPE:
			printf(" %c", *(char*)((char*)p->value + i * p->value_size));
			break;
		default:
			printf("未识别数据类型");
			break;
		}
	}
	printf("\n");
}