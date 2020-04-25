#define _CRT_SECURE_NO_WARNINGS 1
#include "ws_stuct.h"
int admin_power = 0;
int main(void)
{
	mkdir("data");  //创建文件夹
	mkdir("data\\user");  //创建文件夹
	first();
	fclose(fopen("data\\Admin.txt", "a"));  //创建文件
	admininfo();
	fclose(fopen("data\\Card.txt", "a"));  //创建文件
	user_info();
	fclose(fopen("data\\Rate.txt", "a"));  //创建文件
	rates();
	savas();
	if (admin_power == 0)  //进入系统要求登录管理员账号
		login();
	welcome();  //进入主界面
	return 0;
}

