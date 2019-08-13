#define _CRT_SECURE_NO_WARNINGS 1

#include "AdressBook.h"

void Menu()
{
	printf("************************\n");
	printf("***1.Add      2.Del*****\n");
	printf("***3.Mod      4.Search**\n");
	printf("***5.Sort     6.Show****\n");
	printf("***7.Clear    0.Exit****\n");
	printf("************************\n");
	printf("Please Select:> ");
}
int InitFile(contact_pp ct_pp,FILE*fp)
{
	contact_p ct_p = (contact_p)malloc(sizeof(contact_t));
	if (ct_p)
	{
		fread(ct_p, sizeof(contact_t), 1, fp);//读头
		int _cap = ct_p->cap;
		int size = sizeof(contact_t) + ct_p->cap * sizeof(person_t);//总大小
		contact_p p = (contact_p)realloc(ct_p, size);//扩展空间
		if (p)
		{
			ct_p = p;
			fread(ct_p->list, ct_p->cap * sizeof(person_t), 1, fp);//读数据
			(*ct_pp) = ct_p;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}
int Load(contact_pp ct_pp)
{
	FILE*fp = fopen(CT_FILE, "rb");
	if (NULL == fp)
	{
		printf("Init contact defualt!\n");
		InitPersonDeafault(ct_pp);
		return 1;
	}
	int ret = InitFile(ct_pp, fp);
	fclose(fp);
	return ret;
}
void InitPersonDeafault(contact_pp ct_pp)
{
	*ct_pp = malloc(sizeof(contact_t) + sizeof(person_t)*LIST_DEFAULT);
	if (NULL == (*ct_pp))
	{
		printf("%d:%s\n", errno, strerror(errno));
		exit(1);
	}
	(*ct_pp)->cap = LIST_DEFAULT;
	(*ct_pp)->size = 0;
	printf("Debug:Init Contact Success!\n");
}
static int IsFull(contact_p ct_p)//static只想让这个函数在本文件内有效，不展示给用户。yes-1，no-0
{
	return ct_p->size == ct_p->cap ? 1 : 0;
}

//扩容
static int Inc(contact_pp ct_pp)
{
	int new_size = sizeof(contact_t) + ((*ct_pp)->cap + INC_SIZE) * sizeof(person_t);
	contact_p p = realloc(*ct_pp, new_size);
	if (!p)
	{
		printf("Inc Error!\n");
		return 0;
	}
	p->cap = (*ct_pp)->cap + INC_SIZE;
	*ct_pp = p;
	printf("Inc Success!\n");
	return 1;
}
void AddPerson(contact_pp ct_pp)//因为考虑到涉及扩容操作，指针ct_p会发生变化，所以这里选择传二级指针。
{
	if (!IsFull(*ct_pp) || Inc(ct_pp))//contact没有满或者申请新的内存成功都可以add
	{
		person_p p = &((*ct_pp)->list[(*ct_pp)->size]);//size初值为0，最大值为5，永远指向下一个没被放入的有效位置
		printf("Please Enter Name:");
		scanf("%s", p->name);
		printf("Please Enter Sex:");
		scanf(" %c", &(p->sex));
		printf("Please Enter Age:");
		scanf(" %u", &(p->age));
		printf("Please Enter Telphone:");
		scanf(" %s", p->telephone);
		printf("Please Enter Address:");
		scanf(" %s", p->address);
		((*ct_pp)->size)++;
	}
	else
	{
		printf("relloc error!\n");
	}
}

void ShowPerson(contact_p ct_p)
{
	int top = ct_p->size;
	int i = 0;
	person_p p = ct_p->list;
	for (i = 0; i < top; i++)
	{
		printf("|%-6s|%-2c|%-3u|%-12s|%-16s| \n", p[i].name, p[i].sex, p[i].age, p[i].telephone, p[i].address);
	}
}

static int person_cmp(const void* p1, const void* p2)
{
	person_p _p1 = (person_p)p1;
	person_p _p2 = (person_p)p2;
	return strcmp(_p1->name, _p2->name);
}
void SortPerson(contact_p ct_p)
{
	person_p p = ct_p->list;
	qsort(p, ct_p->size, sizeof(person_t), person_cmp);
}


int FindPos(contact_p ct_p,char *name)
{
	person_p p = ct_p->list;
	int top = ct_p->size;
	int i = 0;
	for (i = 0; i < top; i++)
	{
		if (strcmp(name, p[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void DelPerson(contact_p ct_p)
{
	char name[NAME_SIZE] = { 0 };
	int pos = 0;
	int j = 0;
	int top = ct_p->size;
	printf("Please Enter The Delete Person Name: ");
	scanf("%s", &name);
	pos = FindPos(ct_p, name);
	if (pos == -1)
	{
		printf("The Name Is Not Exit!Enter Again!\n");
		return;
	}
	for (j = pos; j < top; j++)
	{
		ct_p->list[j] = ct_p->list[j + 1];
	}
	(ct_p->size)--;
	printf("Delete Success!\n");
}

void ModPerson(contact_p ct_p)
{
	char name[NAME_SIZE] = { 0 };
	int top = ct_p->size;
	int i = 0;
	int pos = 0;
	int age = 0;
	printf("Please Enter The Modified Person Name: ");
	scanf("%s", &name);
	pos = FindPos(ct_p, name);
	if (pos == -1)
	{
		printf("The Name Is Not Exit!Enter Again!\n");
		return;
	}
	//修改年龄
	printf("Please Enter The Modified Age: ");
	scanf("%d", &age);
	ct_p->list[pos].age = age;
	printf("Modifiy Success!\n");
}

void SearchPerson(contact_p ct_p)
{
	char name[NAME_SIZE] = { 0 };
	int pos = 0;
	printf("Please Enter The Person Seaching Name:>");
	scanf("%s", &name);
	pos = FindPos(ct_p, name);
	if (pos == -1)
	{
		printf("The Name Is Not Exit!Enter Again!\n");
		return;
	}
	printf("|%-6s|%-2c|%-3u|%-12s|%-16s| \n", ct_p->list[pos].name, ct_p->list[pos].sex, +\
		ct_p->list[pos].age, ct_p->list[pos].telephone, ct_p->list[pos].address);

}
void ClearPerson(contact_p ct_p)
{
	ct_p->size = 0;
	printf("Clear Success!\n");
}
void Save(contact_p ct_p)
{
	FILE*fp = fopen(CT_FILE, "wb");
	if (NULL == fp)
	{
		printf("fopen error!\n");
		return;
	}
	int size = sizeof(contact_t) + (ct_p->cap) * sizeof(person_t);//通讯录的大小加上每一个人结构体的大小
	fwrite(ct_p, size, 1, fp);

	fclose(fp);
}
