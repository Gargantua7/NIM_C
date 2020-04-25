#define _CRT_SECURE_NO_WARNINGS
#include "ws_stuct.h"

void adminMana(void)
{
	system("CLS");
	if (admin_power == 2)
	{
		printf("欢迎使用收费管理系统/权限管理--------\n");
		printf("请选择你需要的功能：\n");
		printf("输入“1”：添加管理员\n");
		printf("输入“2”：注销管理员\n");
		printf("输入“3”：配置权限\n");
		printf("输入“0”：返回上一级菜单\n");
		printf("请输入：_\b");
		int a;
		scanf("%d", &a);
		printf("\n");
		switch (a)
		{
		case 1:
			adminMana_add();
			break;
		case 2:
			adminMana_del();
			break;
		case 3:
			adminMana_change();
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
	else
	{
		printf("无权限访问此菜单！");
		Sleep(3000);
		main();
	}
}
void adminMana_add(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/权限管理/添加管理员--------\n");
	char* number;
	char* password;
	int power;
	FILE* addCardFile;
	getchar();
	addCardFile = fopen("data\\Admin.txt", "a");
	if (addCardFile == NULL)
		ferr();
	printf("\n请输入需要添加的管理员账号：\n");
	number = gcc();
	int* k = adminSearch(number);
	if (k != -1)
	{
		printf("\n此管理员账号已存在\n\n");
		system("pause");
		main();
	}
	fprintf(addCardFile, "%s\n", number);
	printf("\n请输入需要添加的管理员账号密码:\n");
	password = gcc();
	fprintf(addCardFile, "%s\n", password);
	printf("\n请选择管理员权限：\n输入“1”：一般管理员\n输入“2”：超级管理员\n请输入:_\b");
	scanf("%d", &power);
	switch (power)
	{
	case 1:
		fprintf(addCardFile, "1\n");
		break;
	case 2:
		fprintf(addCardFile, "2\n");
		break;
	default:
		printf("\n\n输入值非法!\n已默认配置为一般管理员\n\n");
		fprintf(addCardFile, "1\n");
		break;
	}
	fclose(addCardFile);
	printf("\n\n添加管理员账号成功！\n\n");
	system("pause");
	main();
}
void adminMana_del(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/权限管理/注销管理员--------\n");
	char* num;
	struct admin_info* need;
	getchar();
	printf("\n请输入需要注销的管理员账号：\n");
	num = gcc();
	need = adminSearch(num);
	if (need != -1)
	{
		FILE* fp = fopen("data\\Admin.txt", "r+");
		if (fp == NULL)
			ferr();
		struct admin_info data;
		while (1)
		{
			fgets(&data.number, 1024, fp);
			if (data.number[strlen(data.number) - 1] == '\n')
			{
				data.number[strlen(data.number) - 1] = '\0';
			}
			fgets(&data.password, 1024, fp);
			if (data.password[strlen(data.password) - 1] == '\n')
			{
				data.password[strlen(data.password) - 1] = '\0';
			}
			fscanf(fp, "%d", &data.power);
			if (strcmp(data.number, num) == 0)
			{
				fseek(fp, -1, SEEK_CUR);
				fprintf(fp, "0");
				printf("\n注销成功！\n\n");
				break;
			}
			fgetc(fp);
		}
		fclose(fp);
	}
	else
		printf("\n查无此管理员账号\n\n");
	system("pause");
	main();
}
void adminMana_change(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/权限管理/配置权限--------\n");
	char* num;
	struct admin_info* need;
	getchar();
	printf("\n请输入需要更改权限的管理员账号：\n");
	num = gcc();
	need = adminSearch(num);
	if (need != -1)
	{
		int k;
		FILE* fp = fopen("data\\Admin.txt", "r+");
		if (fp == NULL)
			ferr();
		struct admin_info data;
		while (1)
		{
			fgets(&data.number, 1024, fp);
			if (data.number[strlen(data.number) - 1] == '\n')
			{
				data.number[strlen(data.number) - 1] = '\0';
			}
			fgets(&data.password, 1024, fp);
			if (data.password[strlen(data.password) - 1] == '\n')
			{
				data.password[strlen(data.password) - 1] = '\0';
			}
			fscanf(fp, "%d", &data.power);
			k = data.power;
			if (strcmp(data.number, num) == 0)
			{
				fseek(fp, -1, SEEK_CUR);
				if (k == 1) {
					fprintf(fp, "2");
					printf("\n配置为超级管理员成功！\n\n");
				}

				if (k == 2) {
					fprintf(fp, "1");
					printf("\n配置为一般管理员成功！\n\n");
				}
				getchar();
				break;
			}
			fgetc(fp);
		}
		fclose(fp);
	}
	else
		printf("\n查无此管理员账号\n\n");
	system("pause");
	main();
}