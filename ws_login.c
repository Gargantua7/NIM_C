#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"
int admin_power;	
void login(void)  //进入系统登录管理员账号
{
	system("CLS");
	char* num, * password;
	struct admin_info* need;
	printf("欢迎使用收费管理系统--------\n\n请登录管理员账号！\n\n输入管理员账号：\n");
	num = gcc();
	need = adminSearch(num);
	if (need != -1)
	{
		printf("\n请输入密码\n");
		password = gcc();
		if (strcmp(password, need->password) == 0)
		{
			admin_power = need->power;  //修改当前系统管理员权限
			if (admin_power > 0)
				printf("\n登录成功！\n");
			else
				printf("\n此管理员账号已被注销！\n");
			Sleep(1000);
			main();
		}
		else
		{
			printf("\n密码错误！\n");
			Sleep(1000);
			main();
		}
	}
	else
	{
		printf("\n无此管理员账号！\n\n请重新输入\n");
		Sleep(3000);
		main();
	}
}
void first(void)  //首次进入系统注册管理员账号
{
	FILE* fp;
	if ((fp = fopen("data\\Admin.txt", "r")) == NULL)  //若无Admin.txt则创建并注册超级管理员账号
	{
		system("CLS");
		printf("欢迎使用收费管理系统--------\n");
		char* num, * password;
		printf("\n首次使用系统请注册一个超级管理员账号！\n");
		printf("\n请输入账号：\n");
		num = gcc();
		fp = fopen("data\\Admin.txt", "a");
		fprintf(fp, "%s\n", num);
		printf("\n请输入密码：\n");
		password = gcc();
		fprintf(fp, "%s\n2\n", password);
		admin_power = 2;  //直接获得超级管理员权限
		printf("\n创建成功！即将进入系统\n");
		fflush(fp);
		Sleep(3000);
		main();
	}
	fclose(fp);
}