#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int twomin(int a[], int left, int right, float min2, float min1)
{
	float lmin1, lmin2, rmin1, rmin2;
	int mid;
	if (left = right)
	{
		min1 = min2 = a[left];
	}
	else if(left=right-1)
		if (a[left] < a[right])
		{
			min2 = a[right];
			min1 = a[left];
		}
		else
		{
			min2 = a[left];
			min1 = a[right];
		}
	else
	{
		mid = left + (right - left) / 2;
		two(a, left, mid, lmin2, lmin1);
		two(a, mid + 1, right, rmin2, rmin1);
		if (lmin1 < rmin1)
			if(lmin2<rmin1)
		    {
				min1 = lmin1;
				min2 = lmin2;
		    }
			else
			{
				min1 = lmin1;
				min2 = rmin2;
			}
		else
			if (rmin2 < lmin1)
			{
				min1 = lmin1;
				min2 = rmin2;
			}
			else
			{
				min1 = rmin2;
				min2 = lmin1;
			}
		return (min1, min2);
	}
}
int twomax(int a[], int left, int right, float max2, float max1)
{
	float lmax2, lmax2, lmax1, rmax1, rmax2;
	int mid;
	if (left = right)
		max2 = max1 = a[left];
	else if(left=right-1)
		if (a[left] < a[right])
		{
			max2 = a[right];
			max1 = a[left];
		}
		else
		{
			max2 = a[left];
			max1 = a[right];
		}
	else
	{
		mid = left + (right - left) / 2;
		twomax(a, left, mid - 1, lmax2, lmax1);
		twomax(a, mid, right, lmax2, lmax1);
		if (lmax1 > rmax1)
			if (lmax2 > rmax1)
			{
				max1 = lmax1;
				max2 = lmax2;
			}
			else
			{
				max1 = lmax1;
				max2 = rmax1;
			}
		else
			if (rmax2 > lmax1)
			{
				max1 = rmax1;
				max2 = rmax2;
			}
			else
			{
				max1 = rmax1;
				max2 = rmax2;
			}
		return (max1, max2);
	}
}
int main()
{
	float a[100];
	int n = 0;
	int i = 0;
	float min1, min2;
	float max1, max2;
	for (i = 0; i < n - 1; i++)
	{
		scanf("%d", a[n]);
	}
	twomin(a, 0, n - 1, min1, min2);
	printf("%f  %f", min1, min2);
	twomax(a, 0, n - 1, max1, max2);
	printf("%f  %f", max1, max2);
	
	return 0;
}