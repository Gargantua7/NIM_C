#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"

void billMana(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/计费管理--------\n");
	printf("请选择你需要的功能：\n");
	printf("输入“1”：上机\n");
	printf("输入“2”：下机\n");
	printf("输入“0”：返回上一级菜单\n");
	printf("\n请输入：_\b");
	int a;
	scanf("%d", &a);
	printf("\n");
	switch (a)
	{
	case 1:
		billMana_login();
		break;
	case 2:
		billMana_logout();
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
void billMana_login(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/计费管理/上机--------\n");
	char* number;
	char* password;
	getchar();
	printf("\n请输入卡号：\n");
	number = gcc();
	struct info* need;
	need = searchs(number);
	if (need != -1)
	{
		if (need->sta == 1)  //检查账号是否可用
		{
			printf("\n请输入密码:\n");
			password = gcc();
			if (strcmp(password, need->password) == 0)
			{
				FILE* p;
				char z[35];
				sprintf(z, "data\\%sLine.txt", need->number);
				p = fopen(z, "w");  //在data目录创建一个以用户名+Line命名的文件
				if (p == NULL)
					ferr();
				time_t timp;
				struct tm* t;
				time(&timp);
				t = gmtime(&timp);
				fprintf(p, "%d\n", t->tm_hour);  //记录上机时间
				fflush(p);
				printf("\n上机成功\n\n");
				fclose(p);
			}
			else
				printf("\n密码错误\n\n");
		}
		else
			printf("\n卡已注销\n\n");
	}
	else
		printf("\n查无此卡号\n\n");
	system("pause");
	main();
}
void billMana_logout(void)
{
	system("CLS");
	printf("欢迎使用收费管理系统/计费管理/下机--------\n");
	char* number;
	getchar();
	printf("\n请输入卡号：\n");
	number = gcc();
	struct info* need;
	need = searchs(number);
	if (need != -1)
	{
		char z[35];
		sprintf(z, "data\\%sLine.txt", need->number);
		FILE* p;
		if ((p = fopen(z, "r")) != NULL)
		{
			int intime, imatime, usetime;
			fscanf(p, "%d", &intime);
			time_t timp;
			struct tm* t;
			time(&timp);
			t = gmtime(&timp);
			imatime = t->tm_hour;  //获取当前时间（即下机时间）
			usetime = imatime - intime + 1;  //计算使用时间
			if (usetime < 0)
				usetime += 24;  //隔天计算
			struct rate* cost;
			cost = chead;
			double pay;
			pay = (double)usetime / (double)cost->time * cost->pay;  //计算本次花费
			savaz(pay);
			need->money -= pay;  //扣除余额
			FILE* h;
			char d[40];
			sprintf(d, "data\\user\\%s.txt", need->number);
			h = fopen(d, "a");
			if (h == NULL)
				ferr();
			fprintf(h, "%d/%d/%d %d:%d:%d\t%lf\n", (1900 + t->tm_year), (1 + t->tm_mon), t->tm_mday, (8 + t->tm_hour), t->tm_min, t->tm_sec, pay);
			//向data\user文件夹内卡号同名文件记录下消费信息
			fflush(h);
			struct info* a;
			a = ahead;
			FILE * fp;
			fp = fopen("data\\Card.txt", "w");
			if (fp == NULL)
				ferr();
			for (int i = 0; i < usernum; i++)  //重写文件
			{
				fprintf(fp, "%s\n%s\n%lf\n%d\n", a->number, a->password, a->money, a->sta);
				fflush(fp);
				a = a->next;
			}
			if (need->money >= 0)
				printf("\n下机成功！余额：%lf元\n\n", need->money);
			else
				printf("\n下机成功！但余额不足，请尽快充值！\n\n欠款：%lf元\n\n", -need->money);
			fclose(fp);
			fclose(p);
			remove(z);  //删除上机时创建的文件
		}
		else
			printf("\n此卡未上机！\n\n");
	}
	else
		printf("\n查无此卡号\n\n");
	system("pause");
	main();
}