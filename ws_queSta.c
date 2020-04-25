#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"

void queSta(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/查询统计--------\n");
	printf("请选择你需要的功能：\n");
	printf("输入“1”：查询消费记录\n");
	printf("输入“2”：统计总营业额\n");
	printf("输入“3”：统计月营业额\n");
	printf("输入“0”：返回上一级菜单\n");
	printf("\n请输入：_\b");
	int a;
	scanf("%d", &a);
	printf("\n");
	switch (a)
	{
	case 1:
		queSta_inquire();
		break;
	case 2:
		queSta_all();
		break;
	case 3:
		queSta_month();
		break;
	case 0:
		welcome();
		break;
	default:
		printf("输入不合法！");
		Sleep(3000);
		main();
		break;
	}
}
void queSta_inquire(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/查询统计/查询消费记录--------\n");
	getchar();
	printf("\n请输入需要查询的卡号：\n");
	char* cardnum;
	cardnum = gcc();
	struct info* need;
	need = searchs(cardnum);
	if (need != -1)
	{
		printf("\n消费日期\t\t消费金额\n");
		char z[40];
		char c;
		sprintf(z, "data\\user\\%s.txt", need->number);
		FILE* p;
		p = fopen(z, "r");
		if (p == NULL)
			ferr();
		while ((c = fgetc(p)) != EOF)
		{
			printf("%c", c);
		}
		fclose(p);
	}
	else
		printf("\n\n查无此卡号\n\n");
	system("pause");
	main();
}
void queSta_all(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/查询统计/统计总营业额--------\n");
	double sum = 0;
	for (int i = 0; i < 12; i++)
	{
		sum += sava_s[i];
	}
	printf("\n一年内的营业额为：%lf元\n\n", sum);
	system("pause");
	main();
}
void queSta_month(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/查询统计/统计月营业额--------\n");
	printf("\n月份\t营业额\t\t上机次数\n");
	for (int i = 0; i < 12; i++)
	{
		printf("%2d\t%lf\t%d\n", i + 1, sava_s[i], sava_t[i]);
	}
	printf("\n\n");
	system("pause");;
	main();
}