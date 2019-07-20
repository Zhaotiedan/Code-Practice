#define _CRT_SECURE_NO_WARNINGS 1


#include "seqlist.h"

void SeqListInit(SeqList* psl, size_t capacity)
{
	psl->array = (SLDataType *)calloc(psl->array, psl->capacity * sizeof(SLDataType));
	psl->capacity = capacity;
	int size = 0;
}
void SeqListDestory(SeqList* psl)
{
	if (psl)
	{
		free(psl->array);
		psl->array = NULL;
	}
	psl->size = 0;
	psl->capacity = 0;
}
void CheckCapacity(SeqList* psl)//每进行一次push操作都要进行判断,查满，扩容要给倍数
{
	if (psl->size >= psl->capacity)
	{
		psl->capacity *= 2;
		psl->array = (SLDataType *)realloc(psl->array, psl->capacity * sizeof(SLDataType));
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x)//尾插
{
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}
void SeqListPopBack(SeqList* psl)//尾删size--就可
{
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x)//头插，为了防止覆盖需要从后往前遍历，插完记得size++
{
	int i;
	CheckCapacity(psl);
	for (i = psl->size - 1; i >= 0; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}
void SeqListPopFront(SeqList* psl)//头删：整体向前前移一位就可，删完记得size--
{
	int i=0;
	for (i = 0; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

int SeqListFind(SeqList* psl, SLDataType x)//找值为x的元素的下标
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			break;
		}
	}
	return i;
}

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)//在pos的位置插入x，从pos位置往后移，与头删相同
{
	int i;
	CheckCapacity(psl);
	for (i = psl->size - 1; i >= pos; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}

void SeqListErase(SeqList* psl, size_t pos)//擦除pos位置的数据，与头删相同
{
	int i = 0;
	for (i = pos; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}

void SeqListRemove(SeqList* psl, SLDataType x)//移除数据,删除值为x的值
{
	SeqListErase(psl, SeqListFind(psl, x));//移除第一个值为x的元素

}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)//修改，把pos的值改成x
{
	int i = 0;
	for (i = psl->size - 1; i >= pos; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}
void SeqListPrint(SeqList* psl)
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d", psl->array[i]);
	}
}
void SeqListBubbleSort(SeqList* psl)
{
	int i, j = 0;
	for (i = 0; i < psl->size; i++)
	{
		for (j = i+1; j < psl->size; j++)
		{
			int tmp = 0;
			if (psl->array[i] > psl->array[j])
			{
				tmp = psl->array[j];
				psl->array[j] = psl->array[i];
				psl->array[i] = tmp;
			}
		}
	}
}
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	int left = 0;
	int right = psl->array[psl->size];
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (psl->array[mid] < x)
		{
			left = mid + 1;
		}
		else if (psl->array[mid] > x)
		{
			right = mid - 1;
		}
		else
			return mid;
	}
	return -1;
	
}
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1)
void SeqListRemoveAll1(SeqList* psl, SLDataType x)//清楚所有值为x的数据，移位
{
	int gap = 0;
	int i = 0;
	for (i = 0; i < psl->size - gap; i++)
	{
		if (psl->array[i + gap] == x)
		{
			gap++;
			if ((gap + i) >= psl->capacity)
			{
				break;
			}
		}
		psl->array[i] = psl->array[i + gap];
	}
	psl->size = psl->size - gap;
}
void SeqListRemoveAll2(SeqList* psl, SLDataType x)//将所有不为x的值保留到另外一个数组tmp中
{
	SLDataType * tmp= (SLDataType *)calloc(psl->capacity, psl->capacity * sizeof(SLDataType));
	int i, j = 0;
	for (i = 0, j = 0; i < psl->size; i++)
	{
		if (psl->array[i] != x)
		{
			tmp[j] = psl->array[i];
			j++;
		}
		free(psl->array);
		psl->array = tmp;
		psl->size = j;
	}
}