#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"

void cardMana(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/������--------\n");
	printf("\n��ѡ������Ҫ�Ĺ��ܣ�\n");
	printf("���롰1������ӿ�\n");
	printf("���롰2������ѯ��\n");
	printf("���롰3����ע�������¼��\n");
	printf("���롰0����������һ���˵�\n");
	printf("\n�����룺_\b");
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
		printf("\n���벻�Ϸ���\n");
		Sleep(3000);
		main();
		break;
	}
}
void cardMana_add(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/������/��ӿ�--------\n");
	char* number;
	char* password;
	double money;
	int sta = 1;
	FILE* addCardFile;
	getchar();
	addCardFile = fopen("data\\Card.txt", "a");
	if (addCardFile == NULL)
		ferr();
	printf("\n�����뿪�����ţ�\n");
	number = gcc();
	int* k = searchs(number);
	if (k != -1)
	{
		printf("\n�˿����Ѵ��ڣ�\n\n");
		system("pause");
		main();
	}
	fprintf(addCardFile, "%s\n", number);
	FILE* fp;
	char z[40];
	sprintf(z, "data\\user\\%s.txt", number);  //���ļ���data\user�ڴ����뿨��ͬ���ļ�
	fp = fopen(z, "wb");
	if (fp == NULL)
		ferr();
	printf("\n�����벻����16���ַ�������:\n");
	password = gcc();
	printf("\n�����뿪����\n");
	scanf("%lf", &money);
	printf("\n");
	fprintf(addCardFile, "%s\n%lf\n%d\n", password, money, sta);  //���ļ�Card.txt�����˻���Ϣ
	fclose(addCardFile);
	printf("\n�����ɹ���\n\n");
	system("pause");
	main();
}
void cardMana_inquire(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/������/��ѯ��--------\n");
	char* cardnum;
	struct info* need;
	getchar();
	printf("\n�����뿨�ţ�\n");
	cardnum = gcc();
	need = searchs(cardnum);
	if (need != -1)
	{
		printf("\n����\t����\t���\t\t״̬\n%s\t%s\t%lf\t", need->number, need->password, need->money);
		if (need->sta == 1)
			printf("����\n");
		else
			printf("ע��\n");
	}
	else
		printf("\n���޴˿���\n\n");
	system("pause");
	main();
}
void cardMana_revoke(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/������/ע�������¼��--------\n");
	char* cardnum;
	struct info* need;
	getchar();
	printf("\n��������Ҫ�����Ŀ��ţ�\n");
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
			fgets(&data.number, 1024, fp);  //���ζ�ȡ�˻���Ϣ
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
			if (strcmp(data.number, cardnum) == 0)  //��ȡ����ͬ����ʱ������״̬
			{
				fseek(fp, -1, SEEK_CUR);
				if (data.sta == 1)
					fprintf(fp, "0");
				else
					fprintf(fp, "1");
				printf("\n�����ɹ���\n");
				break;
			}
			fgetc(fp);
		}
		fclose(fp);
	}
	else
		printf("\n���޴˿���\n\n");
	system("pause");
	main();
}