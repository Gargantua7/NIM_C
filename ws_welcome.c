#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"

void welcome(void)  //系统主页面
{
	system("CLS");
	printf("欢迎使用收费管理系统--------\n");
	printf("\n当前账号权限等级为：");
	switch (admin_power)
	{
	case 0:
		printf("无管理员权限\n");
		break;
	case 1:
		printf("标准管理员\n");
		break;
	case 2:
		printf("超级管理员\n");
		break;
	default:
		printf("权限等级获取失败\n");
		break;
	}
	printf("\n请选择你需要的功能：\n");
	printf("输入“1”：卡管理\n");
	printf("输入“2”：计费标准管理\n");
	printf("输入“3”：计费管理\n");
	printf("输入“4”：费用管理\n");
	printf("输入“5”：查询统计\n");
	printf("输入“6”：权限管理\n");
	printf("输入“7”：系统\n");
	printf("请输入：_\b");
	int a;
	scanf("%d", &a);
	printf("\n");
	switch (a)
	{
	case 1:
		cardMana();
		break;
	case 2:
		billStand();
		break;
	case 3:
		billMana();
		break;
	case 4:
		costMana();
		break;
	case 5:
		queSta();
		break;
	case 6:
		adminMana();
		break;
	case 7:
		systems();
		break;
	default:
		printf("输入不合法！");
		getchar();
		Sleep(3000);
		main();
		break;
	}
}