#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"
//全局变量定义
int sava_t[12];
double sava_s[12];
int* ahead;
int* bhead;
int admin_power;
int adminnum;
void ferr(void)  //文件打开失败报错
{
	system("CLS");
	printf("ERROE:文件打开失败！\n");
	system("pause");
	exit(0);
}
void merr(void)  //内存申请失败报错
{
	system("CLS");
	printf("ERROE:内存申请失败！\n");
	system("pause");
	exit(0);
}
void admininfo(void)  //管理员信息
{
	struct admin_info* node, * end;
	struct admin_info* head;
	head = node = end = (struct admin_info*)malloc(sizeof(struct admin_info));
	if (head == NULL)
		merr();
	FILE * fp = fopen("data\\Admin.txt", "r");
	if (fp == NULL)
		ferr();
	adminnum = 0;
	while (1)
	{
		fgets(node->number, 1024, fp);
		if (node->number[strlen(node->number) - 1] == '\n')
		{
			node->number[strlen(node->number) - 1] = '\0';  //将'\n'改为'\0'便于之后字符串比较，下同
		}
		fgets(node->password, 1024, fp);
		if (node->password[strlen(node->password) - 1] == '\n')
		{
			node->password[strlen(node->password) - 1] = '\0';
		}
		if (fscanf(fp, "%d\n", &node->power) == EOF)
			break;
		end->next = node;
		end = node;
		adminnum++;
		node = (struct admin_info*)malloc(sizeof(struct admin_info));
		if (node == NULL)
			merr();
	}
	bhead = head;
	fclose(fp);
}
void* adminSearch(char s[17])  //管理员信息查找
{
	struct admin_info* a;
	a = bhead;
	for (int i = 0; i < adminnum; i++)
	{
		if (strcmp(s, a->number) == 0)
		{
			return a;  //寻得账号返回指针
			break;
		}
		else
			a = a->next;
	}
	return -1;  //否则返回-1
}
char* gcc(void)  //字符串读取
{
	char c;
	static char s[17];
	int i = 0;
	while ((c = getchar()) != '\n')
	{
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return s;
}
void user_info(void)  //用户信息
{
	struct info* node, * end;
	struct info* head;
	head = node = end = (struct info*)malloc(sizeof(struct info));
	if (head == NULL)
		merr();
	FILE * fp = fopen("data\\Card.txt", "r");
	if (fp == NULL)
		ferr();
	usernum = 0;
	while (1)
	{
		fgets(node->number, 1024, fp);
		if (node->number[strlen(node->number) - 1] == '\n')
		{
			node->number[strlen(node->number) - 1] = '\0';
		}
		fgets(node->password, 1024, fp);
		if (node->password[strlen(node->password) - 1] == '\n')
		{
			node->password[strlen(node->password) - 1] = '\0';
		}
		if (fscanf(fp, "%lf\n%d\n", &node->money, &node->sta) == EOF)
			break;
		end->next = node;
		end = node;
		usernum++;
		node = (struct info*)malloc(sizeof(struct info));
		if (node == NULL)
			merr();
	}
	ahead = head;
	fclose(fp);
}
int* searchs(char s[17])  //用户信息查找
{
	struct info* a;
	a = ahead;
	for (int i = 0; i < usernum; i++)
	{
		if (strcmp(s, a->number) == 0)
		{
			return a;
			break;
		}
		else
			a = a->next;
	}
	return -1;
}
void rates(void)  //从rate.txt读取计费信息到链表
{
	struct rate* node, * end;
	struct rate* head;
	head = node = end = (struct info*)malloc(sizeof(struct info));
	if (head == NULL)
		merr();
	FILE * fp = fopen("data\\Rate.txt", "r");
	if (fp == NULL)
		ferr();
	ratenum = 0;
	while (fscanf(fp, "%d\n%lf\n", &node->time, &node->pay) != EOF)
	{
		end->next = node;
		end = node;
		ratenum++;
		node = (struct info*)malloc(sizeof(struct info));
		if (node == NULL)
			merr();
	}
	chead = head;
	fclose(fp);
}
void* ratesearch(int time)  //向链表查询计费标准
{
	struct rate* a;
	a = chead;
	for (int i = 0; i < ratenum; i++)
	{
		if (a->time == time)
		{
			return a;
			break;
		}
		else
			a = a->next;
	}
	return -1;
}
void savas(void)  //营业额
{
	FILE* fp;
	if ((fp = fopen("data\\Sava.txt", "r")) == NULL)  //无Sava.txt则创建并初始化
	{
		fp = fopen("data\\Sava.txt", "a");
		if (fp == NULL)
			ferr();
		for (int i = 0; i < 12; i++)
		{
			fprintf(fp, "%lf\n%d\n", 0, 0);
		}
	}
	fp = fopen("data\\Sava.txt", "r");
	if (fp == NULL)
		ferr();
	for (int i = 0; i < 12; i++)
	{
		fscanf(fp, "%lf\n%d\n", &sava_s[i], &sava_t[i]);  //读取营业额信息
	}
	fclose(fp);
}
void savaz(double x)  //重写Sava.txt；x为一次性营业额
{

	time_t timp;
	struct tm* t;
	time(&timp);
	t = gmtime(&timp);
	int nmonth = t->tm_mon;  //获取当前月份信息
	sava_s[nmonth] += x;
	sava_t[nmonth] ++;
	FILE* fp;
	fp = fopen("data\\Sava.txt", "w");
	if (fp == NULL)
		ferr();
	for (int i = 0; i < 12; i++)
	{
		fprintf(fp, "%lf\n%d\n", sava_s[i], sava_t[i]);
		fflush(fp);
	}
	fclose(fp);
}
