#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int a[4];
	bool i = 0, j = 0;
	char s;
	while (1) {
		i = 0;
		j = 0;
		cout << "***************************************" << endl;  //标语
		cout << "**                                   **" << endl;
		cout << "**        欢迎进入逻辑运算程序       **" << endl;
		cout << "**                                   **" << endl;
		cout << "***************************************" << endl << endl;
		cout << endl << " 请输入P的值（0或1）,以回车结束:";
		cin >> i;  //读取P的值
		if (i != 0 && i != 1)
		{
			cout << endl << "P的值输入有误, 请重新输入!";
			Sleep(2000);
			system("cls");  //清屏
			cin.clear();
			char t;
			while ((t = cin.get()) != '\n');
			continue;
		}
		cout << endl << " 请输入Q的值（0或1）,以回车结束:";
		cin >> j;  //读取Q的值
		if (j != 0 && j != 1)
		{
			cout << endl << "Q的值输入有误, 请重新输入!";
			Sleep(2000);
			system("cls");  //清屏
			cin.clear();
			char t;
			while ((t = cin.get()) != '\n');
			continue;
		}
		a[0] = i && j;  //与运算
		a[1] = i || j;  //或运算
		a[2] = (!i) || j;  //蕴含运算，将其转化为与或非形式
		a[3] = ((!i) || j) && ((!j) || i);  //等值运算，将其转化为与或非形式
		cout << endl << " 合取:" << endl;
		cout << "       P/\\Q = " << a[0] << endl;
		cout << endl << " 析取:" << endl;
		cout << "       P\\/Q = " << a[1] << endl;
		cout << endl << " 条件:" << endl;
		cout << "       P->Q = " << a[2] << endl;
		cout << endl << " 双条件:" << endl;
		cout << "       P<->Q = " << a[3] << endl;
		while (1) {
			cout << endl << "是否继续运算?（y/n）"; //询问是否继续操作
			cin >> s;
			if (s == 'y' || s == 'n')
			{
				if (s == 'y')
				{
					system("cls");  //清屏
					char t;
					while ((t = cin.get()) != '\n');
					break;  //返回顶层
				}
				else
				{
					cout << "欢迎下次再次使用!" << endl;  //退出
					exit(0);
				}
			}
			else
			{
				cout << "输入错误,请重新输入!" << endl; //错误校验
				continue;
			}
		}
	}
	return 0;
}