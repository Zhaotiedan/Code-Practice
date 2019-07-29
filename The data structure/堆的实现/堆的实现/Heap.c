#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

#define SWAP(a,b,tmp){\
                  tmp=a;\
                  a = b;\
                  b = tmp\
                     }
void swap(HPDataType *a, HPDataType *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void swap2()//异或思想
{

}
//向下调整算法：假设为大堆
void HeapAdjust(Heap *hp, int n)//n为调整的下标
{
	int cur = n;
	while (cur * 2 + 1 < hp->size)//无左节点，为叶子时跳出
	{
		//小于左
		//左有右无。考虑右孩子为空的情况，可能会出现越界
		if (hp->_a[cur] < hp->_a[2 * cur + 1])
		{
			//只要前面为1后面不执行 所以不越界
			if (cur * 2 + 2 >= hp->size || hp->_a[2 * cur + 1]> hp->_a[2 * cur + 2])//左大于右，和左换，变下标
			{
				swap(&hp->_a[cur], &hp->_a[2 * cur + 1]);
				cur = cur * 2 + 1;
			}
			//右大于左，否则和右孩子换，变下标
			else
			{
				swap(&hp->_a[cur], &hp->_a[2 * cur + 2]);
				cur = cur * 2 + 2;
			}
		}
		//已经大于左：左小于右，和右换，变下标
		//右孩子存在时才进
		else if (cur * 2 + 2 < hp->size &&  hp->_a[2 * cur + 1] < hp->_a[2 * cur + 2])
		{
			swap(&hp->_a[cur], &hp->_a[2 * cur + 2]);
			cur = cur * 2 + 2;
		}
		//比左大，比右大
		else
		{
			break;
		}
	}
}
void HeapInit(Heap *hp, HPDataType *a, int n)//从第一个非叶子开始向下调整
{
	int i = 0;
	hp->capacity = MAXSIZE > n ? MAXSIZE : n;//预防n>MAXSIZE
	hp->size = n;
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*hp->capacity);
	if (!hp->_a)
	{
		return;
	}
	memcpy(hp->_a, a, sizeof(HPDataType)*n);

	for (i = n / 2 - 1; i >= 0; i--)
	{
		HeapAdjust(hp, i);
	}
}
void HeapDestory(Heap *hp)
{
	if (hp->_a)
	{
		free(hp->_a);
		hp->capacity = hp->size = 0;
	}
}
void HeapPush(Heap *hp, HPDataType x)
{
	int cur = hp->size;//找到下标
	if (hp->size >= hp->capacity)
	{
		hp->capacity *= 2;
		hp->_a = (HPDataType *)realloc(hp->_a, sizeof(HPDataType)*hp->capacity);
	}
	//尾插
	hp->_a[hp->size] = x;
	hp->size++;
	//向上调整
	while (cur)
	{
		if (hp->_a[cur] > hp->_a[(cur - 1) / 2])//大于爸
		{
			swap(&hp->_a[cur], &hp->_a[(cur - 1) / 2]);
			cur = (cur - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPop(Heap *hp)
{
	//swap(hp->_a, hp->_a + hp->size - 1);
	swap(&hp->_a[0], &hp->_a[hp->size - 1]);
	hp->size--;
	HeapAdjust(hp, 0);
}
HPDataType HeapTop(Heap *hp)
{
	if (!hp->size)
	{
		return (HPDataType)0;
	}
	return hp->_a[0];
}
int HeapSize(Heap *hp)
{
	return hp->size;
}
int HeapEmpty(Heap *hp)
{
	return hp->size == 0;
}
void HeapPrint(Heap *hp)
{
	int i = 0;
	int tag = 0;
	int tmp = 1;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->_a[i]);
		if (i == tag)
		{
			putchar('\n');
			tmp *= 2;
			tag += tmp;
		}
	}
}

// 堆排序
void HeapSort(Heap *hp)
{
	int tmp = hp->size;
	while (hp->size >= 1)
	{
		HeapPop(hp);
	}
	hp->size = tmp;
}