#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"

void queSta(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/��ѯͳ��--------\n");
	printf("��ѡ������Ҫ�Ĺ��ܣ�\n");
	printf("���롰1������ѯ���Ѽ�¼\n");
	printf("���롰2����ͳ����Ӫҵ��\n");
	printf("���롰3����ͳ����Ӫҵ��\n");
	printf("���롰0����������һ���˵�\n");
	printf("\n�����룺_\b");
	int a;
	scanf("%d", &a);
	printf("\n");
	switch (a)
	{
	case 1:
		queSta_inquire();
		break;
	case 2:
		queSta_all();
		break;
	case 3:
		queSta_month();
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
void queSta_inquire(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/��ѯͳ��/��ѯ���Ѽ�¼--------\n");
	getchar();
	printf("\n��������Ҫ��ѯ�Ŀ��ţ�\n");
	char* cardnum;
	cardnum = gcc();
	struct info* need;
	need = searchs(cardnum);
	if (need != -1)
	{
		printf("\n��������\t\t���ѽ��\n");
		char z[40];
		char c;
		sprintf(z, "data\\user\\%s.txt", need->number);
		FILE* p;
		p = fopen(z, "r");
		if (p == NULL)
			ferr();
		while ((c = fgetc(p)) != EOF)
		{
			printf("%c", c);
		}
		fclose(p);
	}
	else
		printf("\n\n���޴˿���\n\n");
	system("pause");
	main();
}
void queSta_all(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/��ѯͳ��/ͳ����Ӫҵ��--------\n");
	double sum = 0;
	for (int i = 0; i < 12; i++)
	{
		sum += sava_s[i];
	}
	printf("\nһ���ڵ�Ӫҵ��Ϊ��%lfԪ\n\n", sum);
	system("pause");
	main();
}
void queSta_month(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/��ѯͳ��/ͳ����Ӫҵ��--------\n");
	printf("\n�·�\tӪҵ��\t\t�ϻ�����\n");
	for (int i = 0; i < 12; i++)
	{
		printf("%2d\t%lf\t%d\n", i + 1, sava_s[i], sava_t[i]);
	}
	printf("\n\n");
	system("pause");;
	main();
}