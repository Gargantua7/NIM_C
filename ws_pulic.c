#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"
//ȫ�ֱ�������
int sava_t[12];
double sava_s[12];
int* ahead;
int* bhead;
int admin_power;
int adminnum;
void ferr(void)  //�ļ���ʧ�ܱ���
{
	system("CLS");
	printf("ERROE:�ļ���ʧ�ܣ�\n");
	system("pause");
	exit(0);
}
void merr(void)  //�ڴ�����ʧ�ܱ���
{
	system("CLS");
	printf("ERROE:�ڴ�����ʧ�ܣ�\n");
	system("pause");
	exit(0);
}
void admininfo(void)  //����Ա��Ϣ
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
			node->number[strlen(node->number) - 1] = '\0';  //��'\n'��Ϊ'\0'����֮���ַ����Ƚϣ���ͬ
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
void* adminSearch(char s[17])  //����Ա��Ϣ����
{
	struct admin_info* a;
	a = bhead;
	for (int i = 0; i < adminnum; i++)
	{
		if (strcmp(s, a->number) == 0)
		{
			return a;  //Ѱ���˺ŷ���ָ��
			break;
		}
		else
			a = a->next;
	}
	return -1;  //���򷵻�-1
}
char* gcc(void)  //�ַ�����ȡ
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
void user_info(void)  //�û���Ϣ
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
int* searchs(char s[17])  //�û���Ϣ����
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
void rates(void)  //��rate.txt��ȡ�Ʒ���Ϣ������
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
void* ratesearch(int time)  //�������ѯ�Ʒѱ�׼
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
void savas(void)  //Ӫҵ��
{
	FILE* fp;
	if ((fp = fopen("data\\Sava.txt", "r")) == NULL)  //��Sava.txt�򴴽�����ʼ��
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
		fscanf(fp, "%lf\n%d\n", &sava_s[i], &sava_t[i]);  //��ȡӪҵ����Ϣ
	}
	fclose(fp);
}
void savaz(double x)  //��дSava.txt��xΪһ����Ӫҵ��
{

	time_t timp;
	struct tm* t;
	time(&timp);
	t = gmtime(&timp);
	int nmonth = t->tm_mon;  //��ȡ��ǰ�·���Ϣ
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
