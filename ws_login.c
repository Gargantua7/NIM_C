#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"
int admin_power;	
void login(void)  //����ϵͳ��¼����Ա�˺�
{
	system("CLS");
	char* num, * password;
	struct admin_info* need;
	printf("��ӭʹ���շѹ���ϵͳ--------\n\n���¼����Ա�˺ţ�\n\n�������Ա�˺ţ�\n");
	num = gcc();
	need = adminSearch(num);
	if (need != -1)
	{
		printf("\n����������\n");
		password = gcc();
		if (strcmp(password, need->password) == 0)
		{
			admin_power = need->power;  //�޸ĵ�ǰϵͳ����ԱȨ��
			if (admin_power > 0)
				printf("\n��¼�ɹ���\n");
			else
				printf("\n�˹���Ա�˺��ѱ�ע����\n");
			Sleep(1000);
			main();
		}
		else
		{
			printf("\n�������\n");
			Sleep(1000);
			main();
		}
	}
	else
	{
		printf("\n�޴˹���Ա�˺ţ�\n\n����������\n");
		Sleep(3000);
		main();
	}
}
void first(void)  //�״ν���ϵͳע�����Ա�˺�
{
	FILE* fp;
	if ((fp = fopen("data\\Admin.txt", "r")) == NULL)  //����Admin.txt�򴴽���ע�ᳬ������Ա�˺�
	{
		system("CLS");
		printf("��ӭʹ���շѹ���ϵͳ--------\n");
		char* num, * password;
		printf("\n�״�ʹ��ϵͳ��ע��һ����������Ա�˺ţ�\n");
		printf("\n�������˺ţ�\n");
		num = gcc();
		fp = fopen("data\\Admin.txt", "a");
		fprintf(fp, "%s\n", num);
		printf("\n���������룺\n");
		password = gcc();
		fprintf(fp, "%s\n2\n", password);
		admin_power = 2;  //ֱ�ӻ�ó�������ԱȨ��
		printf("\n�����ɹ�����������ϵͳ\n");
		fflush(fp);
		Sleep(3000);
		main();
	}
	fclose(fp);
}