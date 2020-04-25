#pragma once
#ifndef ws_struct_INCLUDED
#define ws_struct_INCLUDED
#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
extern int admin_power;  //��ǰϵͳ����ԱȨ��
extern int usernum;  //�˻�����
extern int adminnum;  //����Ա����
extern int ratenum;  //�Ʒѱ�׼����
extern int* ahead;  //�˻���Ϣ����ͷָ��
extern int* bhead;  //����Ա��Ϣ����ͷָ��
extern int* chead;  //�Ʒѱ�׼����ͷָ��
extern double sava_s[12];  //ÿ��Ӫҵ������
extern int sava_t[12];  //ÿ���ϻ���������
struct admin_info  //����Ա�˻�����
{
	char number[16];  //�˺�
	char password[16];  //����
	int power;  //Ȩ��
	struct admin_info* next;
};
struct info  //�û��˻�����
{
	char number[16];  //����
	char password[16];  //����
	double money;  //���
	int sta;  //״̬��Ϣ
	struct info* next;
};
struct rate  //�Ʒѱ�׼����
{
	double pay;  //��Ӧ����
	int time;  //��Ӧ�ϻ�ʱ��
	struct rate* next;
};
void ferr(void);  //�ļ��򿪱���
void merr(void);  //�ڴ����뱨��
void admininfo(void);  //����Ա��Ϣ����д��
void* adminSearch(char s[17]);  //���ҹ���Ա��Ϣ
char* gcc(void);  //�ַ�����ȡ
void user_info(void);  //�û���Ϣ����д��
int* searchs(char s[17]);  //�û���Ϣ����
void rates(void);  //��rate.txt��ȡ�Ʒ���Ϣ������
void* ratesearch(int time);  //�������ѯ�Ʒѱ�׼
void savas(void);  //Ӫҵ��
void savaz(double x);  //��дSava.txt��xΪһ����Ӫҵ��
void welcome(void);  //������
void cardMana(void);  //������������
void cardMana_add(void);  //������-��ӿ�
void cardMana_inquire(void);  //������-��ѯ��
void cardMana_revoke(void);  //������-ע�������¼��
void billStand(void);  //�Ʒѱ�׼����
void billStand_add(void);  //�����Ʒѱ�׼
void billStand_inquire(void);  //��ѯ�Ʒѱ�׼
void billStand_del(void);  //ɾ���Ʒѱ�׼
void billStand_change(void);  //�޸ļƷѱ�׼
void billMana(void);  //�Ʒѹ���
void billMana_login(void);  //�Ʒѹ���-�ϻ�
void billMana_logout(void);  //�Ʒѹ���-�»�
void costMana(void);  //���ù���
void costMana_charge(void);  //���ù���-��ֵ
void costMana_refund(void);  //���ù���-�˷�
void queSta(void);  //��ѯͳ��
void queSta_inquire(void);  //��ѯ���Ѽ�¼
void queSta_all(void);  //ͳ����Ӫҵ��
void queSta_month(void);  //ͳ����Ӫҵ��
void adminMana(void);  //Ȩ�޹���
void adminMana_add(void);  //Ȩ�޹���-��ӹ���Ա
void adminMana_del(void);  //Ȩ�޹���-ɾ������Ա
void adminMana_change(void);  //Ȩ�޹���-���Ĺ���ԱȨ��
void systems(void);  //ϵͳ
void systems_logout(void);  //ϵͳ-����Ա�˺ŵǳ�
void systems_exit(void);  //ϵͳ-�ر�ϵͳ
void login(void);  //����Ա��¼
void first(void);  //�״�ʹ�ã�ע�ᳬ������Ա�˺�
#endif