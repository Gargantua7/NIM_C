#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"
int usernum;
int ratenum;
int* chead;
void billStand(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/计费标准管理--------\n");
	printf("请选择你需要的功能：\n");
	printf("输入“1”：新增标准\n");
	printf("输入“2”：查询标准\n");
	printf("输入“3”：删除标准\n");
	printf("输入“4”：修改标准\n");
	printf("输入“0”：返回上一级菜单\n");
	printf("\n请输入：_\b");
	int a;
	scanf("%d", &a);
	printf("\n");
	switch (a)
	{
	case 1:
		billStand_add();
		break;
	case 2:
		billStand_inquire();
		break;
	case 3:
		billStand_del();
		break;
	case 4:
		billStand_change();
		break;
	case 0:
		welcome();
		break;
	default:
		printf("\n输入不合法！\n");
		Sleep(3000);
		main();
		break;
	}
}
void billStand_add(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/计费标准管理/添加计费标准--------\n");
	double pay;
	int time;
	FILE* add;
	getchar();
	add = fopen("data\\Rate.txt", "a");
	if (add == NULL)
		ferr();
	printf("\n请输入新的计费标准：（输入格式为：a b，即a小时b元）\n");
	scanf("%d %lf", &time, &pay);
	printf("\n");
	fprintf(add, "%d\n%lf\n", time, pay);
	fclose(add);
	getchar();
	printf("\n添加成功！\n\n");
	system("pause");
	main();
}
void billStand_inquire(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/计费标准管理/查询计费标准--------\n");
	double pay, ahead;
	int time;
	getchar();
	printf("\n请输入需要查询的计费标准：（输入整数上机时间）\n");
	scanf("%d", &time);
	struct rate* need;
	need = ratesearch(time);
	if (need != -1)
		printf("\n上机%d小时将花费%lf元\n\n", need->time, need->pay);
	else
		printf("\n查询失败，请更换数值！\n\n");
	system("pause");
	main();
}
void billStand_del(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/计费标准管理/删除计费标准--------\n");
	int time, x;
	getchar();
	printf("\n请输入需要删除的计费标准：（输入整数上机时长）\n");
	scanf("%d", &time);
	struct rate* need;
	need = ratesearch(time);
	if (need != -1)
	{
		printf("\n确定删除计费标准：%d小时花费%lf元 ？\n确定请输入“1”\n\n", need->time, need->pay);
		scanf("%d", &x);
		if (x == 1)
		{
			struct rate* a;
			a = chead;
			FILE* p;
			p = fopen("data\\Rate.txt", "w");  //重写文件
			if (p == NULL)
				ferr();
			for (int i = 0; i < ratenum; i++)
			{
				if (a->time != time)
					fprintf(p, "%d\n%lf\n", a->time, a->pay);
				a = a->next;
			}
			printf("\n更改成功！\n\n");
			fclose(p);
		}
	}
	else
	{
		printf("\n无此标准，请更换数值！\n\n");
	}
	system("pause");
	main();
}
void billStand_change(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/计费标准管理/修改计费标准--------\n");
	double pay;
	int time;
	getchar();
	printf("\n请输入需要修改的计费标准：（输入整数时长）\n");
	scanf("%d", &time);
	struct rate* need;
	need = ratesearch(time);
	if (need != -1)
	{
		printf("\n请输入修改后的计费标准：（输入花费）\n");
		scanf("%lf", &pay);
		need->pay = pay;
		struct rate* a;
		a = chead;
		FILE* p;
		p = fopen("data\\Rate.txt", "w");  //重写文件
		if (p == NULL)
			ferr();
		for (int i = 0; i < ratenum; i++)
		{
			fprintf(p, "%d\n%lf\n", a->time, a->pay);
			a = a->next;
		}
		printf("\n更改成功！\n\n");
		fclose(p);
	}
	else
	{
		printf("\n无此标准，请更换数值！\n\n");
	}
	system("pause");
	main();
}