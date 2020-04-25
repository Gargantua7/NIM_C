#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"

void costMana(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/费用管理--------\n");
	printf("请选择你需要的功能：\n");
	printf("输入“1”：充值\n");
	printf("输入“2”：退费\n");
	printf("输入“0”：返回上一级菜单\n");
	printf("请输入：_\b");
	int a;
	scanf("%d", &a);
	printf("\n");
	switch (a)
	{
	case 1:
		costMana_charge();
		break;
	case 2:
		costMana_refund();
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
void costMana_charge(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/费用管理/充值--------\n");
	char* cardnum;
	struct info* need;
	getchar();
	printf("\n请输入需要充值的卡号：\n");
	cardnum = gcc();
	need = searchs(cardnum);
	if (need != -1)
	{
		printf("\n请输入充值金额：\n");
		double payin;
		scanf("%lf", &payin);
		if (payin <= 0)
		{
			printf("\n输入值非法！\n");
			Sleep(3000);
			costMana_charge();
		}
		need->money += payin;
		struct info* a;
		a = ahead;
		FILE* p;
		p = fopen("data\\Card.txt", "w");
		if (p == NULL)
			ferr();
		for (int i = 0; i < usernum; i++)
		{
			fprintf(p, "%s\n%s\n%lf\n%d\n", a->number, a->password, a->money, a->sta);
			a = a->next;
		}
		printf("\n充值成功！余额：%lf\n\n", need->money);
		fclose(p);
	}
	else
		printf("\n查无此卡号\n\n");
	system("pause");
	main();
}
void costMana_refund(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/费用管理/退费--------\n");
	char* cardnum;
	struct info* need;
	getchar();
	printf("\n请输入需要退款的卡号：\n");
	cardnum = gcc();
	need = searchs(cardnum);
	if (need != -1)
	{
		printf("\n卡内余额：%lf\n\n请输入退款金额：\n", need->money);
		double payout;
		scanf("%lf", &payout);
		if (payout <= need->money)
		{
			need->money -= payout;
			struct info* a;
			a = ahead;
			FILE* p;
			p = fopen("data\\Card.txt", "w");
			if (p == NULL)
				ferr();
			for (int i = 0; i < usernum; i++)  //重写文件
			{
				fprintf(p, "%s\n%s\n%lf\n%d\n", a->number, a->password, a->money, a->sta);
				a = a->next;
			}
			printf("\n退款成功！余额：%lf\n\n", need->money);
			fclose(p);
		}
		else
			printf("\n卡内余额不足！\n\n");
	}
	else
		printf("\n查无此卡号\n\n");
	system("pause");
	main();
}