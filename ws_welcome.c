#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"

void welcome(void)  //ϵͳ��ҳ��
{
	system("CLS");
	printf("��ӭʹ���շѹ���ϵͳ--------\n");
	printf("\n��ǰ�˺�Ȩ�޵ȼ�Ϊ��");
	switch (admin_power)
	{
	case 0:
		printf("�޹���ԱȨ��\n");
		break;
	case 1:
		printf("��׼����Ա\n");
		break;
	case 2:
		printf("��������Ա\n");
		break;
	default:
		printf("Ȩ�޵ȼ���ȡʧ��\n");
		break;
	}
	printf("\n��ѡ������Ҫ�Ĺ��ܣ�\n");
	printf("���롰1����������\n");
	printf("���롰2�����Ʒѱ�׼����\n");
	printf("���롰3�����Ʒѹ���\n");
	printf("���롰4�������ù���\n");
	printf("���롰5������ѯͳ��\n");
	printf("���롰6����Ȩ�޹���\n");
	printf("���롰7����ϵͳ\n");
	printf("�����룺_\b");
	int a;
	scanf("%d", &a);
	printf("\n");
	switch (a)
	{
	case 1:
		cardMana();
		break;
	case 2:
		billStand();
		break;
	case 3:
		billMana();
		break;
	case 4:
		costMana();
		break;
	case 5:
		queSta();
		break;
	case 6:
		adminMana();
		break;
	case 7:
		systems();
		break;
	default:
		printf("���벻�Ϸ���");
		getchar();
		Sleep(3000);
		main();
		break;
	}
}