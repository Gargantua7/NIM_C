#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"

void costMana(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/���ù���--------\n");
	printf("��ѡ������Ҫ�Ĺ��ܣ�\n");
	printf("���롰1������ֵ\n");
	printf("���롰2�����˷�\n");
	printf("���롰0����������һ���˵�\n");
	printf("�����룺_\b");
	int a;
	scanf("%d", &a);
	printf("\n");
	switch (a)
	{
	case 1:
		costMana_charge();
		break;
	case 2:
		costMana_refund();
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
void costMana_charge(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/���ù���/��ֵ--------\n");
	char* cardnum;
	struct info* need;
	getchar();
	printf("\n��������Ҫ��ֵ�Ŀ��ţ�\n");
	cardnum = gcc();
	need = searchs(cardnum);
	if (need != -1)
	{
		printf("\n�������ֵ��\n");
		double payin;
		scanf("%lf", &payin);
		if (payin <= 0)
		{
			printf("\n����ֵ�Ƿ���\n");
			Sleep(3000);
			costMana_charge();
		}
		need->money += payin;
		struct info* a;
		a = ahead;
		FILE* p;
		p = fopen("data\\Card.txt", "w");
		if (p == NULL)
			ferr();
		for (int i = 0; i < usernum; i++)
		{
			fprintf(p, "%s\n%s\n%lf\n%d\n", a->number, a->password, a->money, a->sta);
			a = a->next;
		}
		printf("\n��ֵ�ɹ�����%lf\n\n", need->money);
		fclose(p);
	}
	else
		printf("\n���޴˿���\n\n");
	system("pause");
	main();
}
void costMana_refund(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/���ù���/�˷�--------\n");
	char* cardnum;
	struct info* need;
	getchar();
	printf("\n��������Ҫ�˿�Ŀ��ţ�\n");
	cardnum = gcc();
	need = searchs(cardnum);
	if (need != -1)
	{
		printf("\n������%lf\n\n�������˿��\n", need->money);
		double payout;
		scanf("%lf", &payout);
		if (payout <= need->money)
		{
			need->money -= payout;
			struct info* a;
			a = ahead;
			FILE* p;
			p = fopen("data\\Card.txt", "w");
			if (p == NULL)
				ferr();
			for (int i = 0; i < usernum; i++)  //��д�ļ�
			{
				fprintf(p, "%s\n%s\n%lf\n%d\n", a->number, a->password, a->money, a->sta);
				a = a->next;
			}
			printf("\n�˿�ɹ�����%lf\n\n", need->money);
			fclose(p);
		}
		else
			printf("\n�������㣡\n\n");
	}
	else
		printf("\n���޴˿���\n\n");
	system("pause");
	main();
}