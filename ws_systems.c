#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"

void systems(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/系统--------\n");
	printf("请选择你需要的功能：\n");
	printf("输入“1”：退出管理员账号\n");
	printf("输入“2”：关闭系统\n");
	printf("输入“0”：返回上一级菜单\n");
	printf("\n请输入：_\b");
	int a;
	scanf("%d", &a);
	printf("\n");
	switch (a)
	{
	case 1:
		systems_logout();
		break;
	case 2:
		systems_exit();
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
void systems_logout(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/系统/退出管理员账号--------\n");
	printf("\n确定退出管理员账号？\n输入“0”：确定退出管理员账号\n请输入；_\b");
	int a;
	scanf("%d", &a);
	if (a == 0)
	{
		printf("\n管理员账号退出成功！\n");
		admin_power = 0;
		getchar();
		Sleep(3000);
		main();
	}
	else
	{
		printf("\n输入不合法！");
		Sleep(3000);
		systems();
	}
}
void systems_exit(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/系统/关闭系统--------\n");
	printf("\n确定关闭系统？\n输入“0”：确定关闭系统\n\n请输入；_\b");
	int a;
	scanf("%d", &a);
	if (a == 0)
	{
		printf("\n系统即将关闭！\n");
		Sleep(3000);
		exit(0);
	}
	else
	{
		printf("\n输入不合法！\n");
		Sleep(1000);
		systems();
	}
}