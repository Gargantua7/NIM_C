#pragma once
#ifndef ws_struct_INCLUDED
#define ws_struct_INCLUDED
#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
extern int admin_power;  //当前系统管理员权限
extern int usernum;  //账户数量
extern int adminnum;  //管理员数量
extern int ratenum;  //计费标准数量
extern int* ahead;  //账户信息链表头指针
extern int* bhead;  //管理员信息链表头指针
extern int* chead;  //计费标准链表头指针
extern double sava_s[12];  //每月营业额数组
extern int sava_t[12];  //每月上机次数数组
struct admin_info  //管理员账户链表
{
	char number[16];  //账号
	char password[16];  //密码
	int power;  //权限
	struct admin_info* next;
};
struct info  //用户账户链表
{
	char number[16];  //卡号
	char password[16];  //密码
	double money;  //余额
	int sta;  //状态信息
	struct info* next;
};
struct rate  //计费标准链表
{
	double pay;  //对应花费
	int time;  //对应上机时间
	struct rate* next;
};
void ferr(void);  //文件打开报错
void merr(void);  //内存申请报错
void admininfo(void);  //管理员信息链表写入
void* adminSearch(char s[17]);  //查找管理员信息
char* gcc(void);  //字符串读取
void user_info(void);  //用户信息链表写入
int* searchs(char s[17]);  //用户信息查找
void rates(void);  //从rate.txt读取计费信息到链表
void* ratesearch(int time);  //向链表查询计费标准
void savas(void);  //营业额
void savaz(double x);  //重写Sava.txt；x为一次性营业额
void welcome(void);  //主界面
void cardMana(void);  //卡管理主界面
void cardMana_add(void);  //卡管理-添加卡
void cardMana_inquire(void);  //卡管理-查询卡
void cardMana_revoke(void);  //卡管理-注销，重新激活卡
void billStand(void);  //计费标准管理
void billStand_add(void);  //新增计费标准
void billStand_inquire(void);  //查询计费标准
void billStand_del(void);  //删除计费标准
void billStand_change(void);  //修改计费标准
void billMana(void);  //计费管理
void billMana_login(void);  //计费管理-上机
void billMana_logout(void);  //计费管理-下机
void costMana(void);  //费用管理
void costMana_charge(void);  //费用管理-充值
void costMana_refund(void);  //费用管理-退费
void queSta(void);  //查询统计
void queSta_inquire(void);  //查询消费记录
void queSta_all(void);  //统计总营业额
void queSta_month(void);  //统计月营业额
void adminMana(void);  //权限管理
void adminMana_add(void);  //权限管理-添加管理员
void adminMana_del(void);  //权限管理-删除管理员
void adminMana_change(void);  //权限管理-更改管理员权限
void systems(void);  //系统
void systems_logout(void);  //系统-管理员账号登出
void systems_exit(void);  //系统-关闭系统
void login(void);  //管理员登录
void first(void);  //首次使用，注册超级管理员账号
#endif