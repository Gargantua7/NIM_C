#define _CRT_SECURE_NO_WARNINGS
#include "ws_stuct.h"

void adminMana(void)
{
	system("CLS");
	if (admin_power == 2)
	{
		printf("��ӭʹ���շѹ���ϵͳ/Ȩ�޹���--------\n");
		printf("��ѡ������Ҫ�Ĺ��ܣ�\n");
		printf("���롰1������ӹ���Ա\n");
		printf("���롰2����ע������Ա\n");
		printf("���롰3��������Ȩ��\n");
		printf("���롰0����������һ���˵�\n");
		printf("�����룺_\b");
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
			printf("���벻�Ϸ���");
			Sleep(3000);
			main();
			break;
		}
	}
	else
	{
		printf("��Ȩ�޷��ʴ˲˵���");
		Sleep(3000);
		main();
	}
}
void adminMana_add(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/Ȩ�޹���/��ӹ���Ա--------\n");
	char* number;
	char* password;
	int power;
	FILE* addCardFile;
	getchar();
	addCardFile = fopen("data\\Admin.txt", "a");
	if (addCardFile == NULL)
		ferr();
	printf("\n��������Ҫ��ӵĹ���Ա�˺ţ�\n");
	number = gcc();
	int* k = adminSearch(number);
	if (k != -1)
	{
		printf("\n�˹���Ա�˺��Ѵ���\n\n");
		system("pause");
		main();
	}
	fprintf(addCardFile, "%s\n", number);
	printf("\n��������Ҫ��ӵĹ���Ա�˺�����:\n");
	password = gcc();
	fprintf(addCardFile, "%s\n", password);
	printf("\n��ѡ�����ԱȨ�ޣ�\n���롰1����һ�����Ա\n���롰2������������Ա\n������:_\b");
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
		printf("\n\n����ֵ�Ƿ�!\n��Ĭ������Ϊһ�����Ա\n\n");
		fprintf(addCardFile, "1\n");
		break;
	}
	fclose(addCardFile);
	printf("\n\n��ӹ���Ա�˺ųɹ���\n\n");
	system("pause");
	main();
}
void adminMana_del(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/Ȩ�޹���/ע������Ա--------\n");
	char* num;
	struct admin_info* need;
	getchar();
	printf("\n��������Ҫע���Ĺ���Ա�˺ţ�\n");
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
				printf("\nע���ɹ���\n\n");
				break;
			}
			fgetc(fp);
		}
		fclose(fp);
	}
	else
		printf("\n���޴˹���Ա�˺�\n\n");
	system("pause");
	main();
}
void adminMana_change(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/Ȩ�޹���/����Ȩ��--------\n");
	char* num;
	struct admin_info* need;
	getchar();
	printf("\n��������Ҫ����Ȩ�޵Ĺ���Ա�˺ţ�\n");
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
					printf("\n����Ϊ��������Ա�ɹ���\n\n");
				}

				if (k == 2) {
					fprintf(fp, "1");
					printf("\n����Ϊһ�����Ա�ɹ���\n\n");
				}
				getchar();
				break;
			}
			fgetc(fp);
		}
		fclose(fp);
	}
	else
		printf("\n���޴˹���Ա�˺�\n\n");
	system("pause");
	main();
}