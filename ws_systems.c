#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"

void systems(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/ϵͳ--------\n");
	printf("��ѡ������Ҫ�Ĺ��ܣ�\n");
	printf("���롰1�����˳�����Ա�˺�\n");
	printf("���롰2�����ر�ϵͳ\n");
	printf("���롰0����������һ���˵�\n");
	printf("\n�����룺_\b");
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
		printf("���벻�Ϸ���");
		Sleep(3000);
		main();
		break;
	}
}
void systems_logout(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/ϵͳ/�˳�����Ա�˺�--------\n");
	printf("\nȷ���˳�����Ա�˺ţ�\n���롰0����ȷ���˳�����Ա�˺�\n�����룻_\b");
	int a;
	scanf("%d", &a);
	if (a == 0)
	{
		printf("\n����Ա�˺��˳��ɹ���\n");
		admin_power = 0;
		getchar();
		Sleep(3000);
		main();
	}
	else
	{
		printf("\n���벻�Ϸ���");
		Sleep(3000);
		systems();
	}
}
void systems_exit(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/ϵͳ/�ر�ϵͳ--------\n");
	printf("\nȷ���ر�ϵͳ��\n���롰0����ȷ���ر�ϵͳ\n\n�����룻_\b");
	int a;
	scanf("%d", &a);
	if (a == 0)
	{
		printf("\nϵͳ�����رգ�\n");
		Sleep(3000);
		exit(0);
	}
	else
	{
		printf("\n���벻�Ϸ���\n");
		Sleep(1000);
		systems();
	}
}