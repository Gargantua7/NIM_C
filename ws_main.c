#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"
int admin_power = 0;
int main(void)
{
	mkdir("data");  //�����ļ���
	mkdir("data\\user");  //�����ļ���
	first();
	fclose(fopen("data\\Admin.txt", "a"));  //�����ļ�
	admininfo();
	fclose(fopen("data\\Card.txt", "a"));  //�����ļ�
	user_info();
	fclose(fopen("data\\Rate.txt", "a"));  //�����ļ�
	rates();
	savas();
	if (admin_power == 0)  //����ϵͳҪ���¼����Ա�˺�
		login();
	welcome();  //����������
	return 0;
}

