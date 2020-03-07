#define _CRT_SECURE_NO_WARNINGS 1

#include"Prime.h"

const int PRIMECOUNT = 28;
const size_t primeList[PRIMECOUNT] =
{
    53ul, 97ul, 193ul, 389ul, 769ul,
    1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
    49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
    1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
    50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
    1610612741ul, 3221225473ul, 4294967291ul
};

size_t GetNextPrime(size_t capacity)//获取比当前容量大的素数
{
	for (auto e : primeList)
	{
		if (e > capacity)
		{
			return e;
		}
	}
	return primeList[PRIMECOUNT];
}
