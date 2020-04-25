#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"

void cardMana(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/卡管理--------\n");
	printf("\n请选择你需要的功能：\n");
	printf("输入“1”：添加卡\n");
	printf("输入“2”：查询卡\n");
	printf("输入“3”：注销、重新激活卡\n");
	printf("输入“0”：返回上一级菜单\n");
	printf("\n请输入：_\b");
	int a;
	scanf("%d", &a);
	printf("\n");
	switch (a)
	{
	case 1:
		cardMana_add();
		break;
	case 2:
		cardMana_inquire();
		break;
	case 3:
		cardMana_revoke();
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
void cardMana_add(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/卡管理/添加卡--------\n");
	char* number;
	char* password;
	double money;
	int sta = 1;
	FILE* addCardFile;
	getchar();
	addCardFile = fopen("data\\Card.txt", "a");
	if (addCardFile == NULL)
		ferr();
	printf("\n请输入开卡卡号：\n");
	number = gcc();
	int* k = searchs(number);
	if (k != -1)
	{
		printf("\n此卡号已存在！\n\n");
		system("pause");
		main();
	}
	fprintf(addCardFile, "%s\n", number);
	FILE* fp;
	char z[40];
	sprintf(z, "data\\user\\%s.txt", number);  //向文件夹data\user内创建与卡号同名文件
	fp = fopen(z, "wb");
	if (fp == NULL)
		ferr();
	printf("\n请输入不超过16个字符的密码:\n");
	password = gcc();
	printf("\n请输入开卡金额：\n");
	scanf("%lf", &money);
	printf("\n");
	fprintf(addCardFile, "%s\n%lf\n%d\n", password, money, sta);  //向文件Card.txt导出账户信息
	fclose(addCardFile);
	printf("\n开卡成功！\n\n");
	system("pause");
	main();
}
void cardMana_inquire(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/卡管理/查询卡--------\n");
	char* cardnum;
	struct info* need;
	getchar();
	printf("\n请输入卡号：\n");
	cardnum = gcc();
	need = searchs(cardnum);
	if (need != -1)
	{
		printf("\n卡号\t密码\t余额\t\t状态\n%s\t%s\t%lf\t", need->number, need->password, need->money);
		if (need->sta == 1)
			printf("可用\n");
		else
			printf("注销\n");
	}
	else
		printf("\n查无此卡号\n\n");
	system("pause");
	main();
}
void cardMana_revoke(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/卡管理/注销，重新激活卡--------\n");
	char* cardnum;
	struct info* need;
	getchar();
	printf("\n请输入需要操作的卡号：\n");
	cardnum = gcc();
	need = searchs(cardnum);
	if (need != -1)
	{
		FILE* fp = fopen("data\\Card.txt", "r+");
		if (fp == NULL)
			ferr();
		struct info data;
		while (1)
		{
			fgets(&data.number, 1024, fp);  //依次读取账户信息
			if (data.number[strlen(data.number) - 1] == '\n')
			{
				data.number[strlen(data.number) - 1] = '\0';
			}
			fgets(&data.password, 1024, fp);
			if (data.password[strlen(data.password) - 1] == '\n')
			{
				data.password[strlen(data.password) - 1] = '\0';
			}
			fscanf(fp, "%lf\n%d", &data.money, &data.sta);
			if (strcmp(data.number, cardnum) == 0)  //读取到相同卡号时，更改状态
			{
				fseek(fp, -1, SEEK_CUR);
				if (data.sta == 1)
					fprintf(fp, "0");
				else
					fprintf(fp, "1");
				printf("\n操作成功！\n");
				break;
			}
			fgetc(fp);
		}
		fclose(fp);
	}
	else
		printf("\n查无此卡号\n\n");
	system("pause");
	main();
}