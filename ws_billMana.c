#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"

void billMana(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/�Ʒѹ���--------\n");
	printf("��ѡ������Ҫ�Ĺ��ܣ�\n");
	printf("���롰1�����ϻ�\n");
	printf("���롰2�����»�\n");
	printf("���롰0����������һ���˵�\n");
	printf("\n�����룺_\b");
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
		printf("\n���벻�Ϸ���\n");
		Sleep(3000);
		main();
		break;
	}
}
void billMana_login(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/�Ʒѹ���/�ϻ�--------\n");
	char* number;
	char* password;
	getchar();
	printf("\n�����뿨�ţ�\n");
	number = gcc();
	struct info* need;
	need = searchs(number);
	if (need != -1)
	{
		if (need->sta == 1)  //����˺��Ƿ����
		{
			printf("\n����������:\n");
			password = gcc();
			if (strcmp(password, need->password) == 0)
			{
				FILE* p;
				char z[35];
				sprintf(z, "data\\%sLine.txt", need->number);
				p = fopen(z, "w");  //��dataĿ¼����һ�����û���+Line�������ļ�
				if (p == NULL)
					ferr();
				time_t timp;
				struct tm* t;
				time(&timp);
				t = gmtime(&timp);
				fprintf(p, "%d\n", t->tm_hour);  //��¼�ϻ�ʱ��
				fflush(p);
				printf("\n�ϻ��ɹ�\n\n");
				fclose(p);
			}
			else
				printf("\n�������\n\n");
		}
		else
			printf("\n����ע��\n\n");
	}
	else
		printf("\n���޴˿���\n\n");
	system("pause");
	main();
}
void billMana_logout(void)
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ/�Ʒѹ���/�»�--------\n");
	char* number;
	getchar();
	printf("\n�����뿨�ţ�\n");
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
			imatime = t->tm_hour;  //��ȡ��ǰʱ�䣨���»�ʱ�䣩
			usetime = imatime - intime + 1;  //����ʹ��ʱ��
			if (usetime < 0)
				usetime += 24;  //�������
			struct rate* cost;
			cost = chead;
			double pay;
			pay = (double)usetime / (double)cost->time * cost->pay;  //���㱾�λ���
			savaz(pay);
			need->money -= pay;  //�۳����
			FILE* h;
			char d[40];
			sprintf(d, "data\\user\\%s.txt", need->number);
			h = fopen(d, "a");
			if (h == NULL)
				ferr();
			fprintf(h, "%d/%d/%d %d:%d:%d\t%lf\n", (1900 + t->tm_year), (1 + t->tm_mon), t->tm_mday, (8 + t->tm_hour), t->tm_min, t->tm_sec, pay);
			//��data\user�ļ����ڿ���ͬ���ļ���¼��������Ϣ
			fflush(h);
			struct info* a;
			a = ahead;
			FILE * fp;
			fp = fopen("data\\Card.txt", "w");
			if (fp == NULL)
				ferr();
			for (int i = 0; i < usernum; i++)  //��д�ļ�
			{
				fprintf(fp, "%s\n%s\n%lf\n%d\n", a->number, a->password, a->money, a->sta);
				fflush(fp);
				a = a->next;
			}
			if (need->money >= 0)
				printf("\n�»��ɹ�����%lfԪ\n\n", need->money);
			else
				printf("\n�»��ɹ��������㣬�뾡���ֵ��\n\nǷ�%lfԪ\n\n", -need->money);
			fclose(fp);
			fclose(p);
			remove(z);  //ɾ���ϻ�ʱ�������ļ�
		}
		else
			printf("\n�˿�δ�ϻ���\n\n");
	}
	else
		printf("\n���޴˿���\n\n");
	system("pause");
	main();
}