#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"
int usernum;
int ratenum;
int* chead;
void billStand(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/�Ʒѱ�׼����--------\n");
	printf("��ѡ������Ҫ�Ĺ��ܣ�\n");
	printf("���롰1����������׼\n");
	printf("���롰2������ѯ��׼\n");
	printf("���롰3����ɾ����׼\n");
	printf("���롰4�����޸ı�׼\n");
	printf("���롰0����������һ���˵�\n");
	printf("\n�����룺_\b");
	int a;
	scanf("%d", &a);
	printf("\n");
	switch (a)
	{
	case 1:
		billStand_add();
		break;
	case 2:
		billStand_inquire();
		break;
	case 3:
		billStand_del();
		break;
	case 4:
		billStand_change();
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
void billStand_add(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/�Ʒѱ�׼����/��ӼƷѱ�׼--------\n");
	double pay;
	int time;
	FILE* add;
	getchar();
	add = fopen("data\\Rate.txt", "a");
	if (add == NULL)
		ferr();
	printf("\n�������µļƷѱ�׼���������ʽΪ��a b����aСʱbԪ��\n");
	scanf("%d %lf", &time, &pay);
	printf("\n");
	fprintf(add, "%d\n%lf\n", time, pay);
	fclose(add);
	getchar();
	printf("\n��ӳɹ���\n\n");
	system("pause");
	main();
}
void billStand_inquire(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/�Ʒѱ�׼����/��ѯ�Ʒѱ�׼--------\n");
	double pay, ahead;
	int time;
	getchar();
	printf("\n��������Ҫ��ѯ�ļƷѱ�׼�������������ϻ�ʱ�䣩\n");
	scanf("%d", &time);
	struct rate* need;
	need = ratesearch(time);
	if (need != -1)
		printf("\n�ϻ�%dСʱ������%lfԪ\n\n", need->time, need->pay);
	else
		printf("\n��ѯʧ�ܣ��������ֵ��\n\n");
	system("pause");
	main();
}
void billStand_del(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/�Ʒѱ�׼����/ɾ���Ʒѱ�׼--------\n");
	int time, x;
	getchar();
	printf("\n��������Ҫɾ���ļƷѱ�׼�������������ϻ�ʱ����\n");
	scanf("%d", &time);
	struct rate* need;
	need = ratesearch(time);
	if (need != -1)
	{
		printf("\nȷ��ɾ���Ʒѱ�׼��%dСʱ����%lfԪ ��\nȷ�������롰1��\n\n", need->time, need->pay);
		scanf("%d", &x);
		if (x == 1)
		{
			struct rate* a;
			a = chead;
			FILE* p;
			p = fopen("data\\Rate.txt", "w");  //��д�ļ�
			if (p == NULL)
				ferr();
			for (int i = 0; i < ratenum; i++)
			{
				if (a->time != time)
					fprintf(p, "%d\n%lf\n", a->time, a->pay);
				a = a->next;
			}
			printf("\n���ĳɹ���\n\n");
			fclose(p);
		}
	}
	else
	{
		printf("\n�޴˱�׼���������ֵ��\n\n");
	}
	system("pause");
	main();
}
void billStand_change(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/�Ʒѱ�׼����/�޸ļƷѱ�׼--------\n");
	double pay;
	int time;
	getchar();
	printf("\n��������Ҫ�޸ĵļƷѱ�׼������������ʱ����\n");
	scanf("%d", &time);
	struct rate* need;
	need = ratesearch(time);
	if (need != -1)
	{
		printf("\n�������޸ĺ�ļƷѱ�׼�������뻨�ѣ�\n");
		scanf("%lf", &pay);
		need->pay = pay;
		struct rate* a;
		a = chead;
		FILE* p;
		p = fopen("data\\Rate.txt", "w");  //��д�ļ�
		if (p == NULL)
			ferr();
		for (int i = 0; i < ratenum; i++)
		{
			fprintf(p, "%d\n%lf\n", a->time, a->pay);
			a = a->next;
		}
		printf("\n���ĳɹ���\n\n");
		fclose(p);
	}
	else
	{
		printf("\n�޴˱�׼���������ֵ��\n\n");
	}
	system("pause");
	main();
}