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
		cout << "***************************************" << endl;  //����
		cout << "**                                   **" << endl;
		cout << "**        ��ӭ�����߼��������       **" << endl;
		cout << "**                                   **" << endl;
		cout << "***************************************" << endl << endl;
		cout << endl << " ������P��ֵ��0��1��,�Իس�����:";
		cin >> i;  //��ȡP��ֵ
		if (i != 0 && i != 1)
		{
			cout << endl << "P��ֵ��������, ����������!";
			Sleep(2000);
			system("cls");  //����
			cin.clear();
			char t;
			while ((t = cin.get()) != '\n');
			continue;
		}
		cout << endl << " ������Q��ֵ��0��1��,�Իس�����:";
		cin >> j;  //��ȡQ��ֵ
		if (j != 0 && j != 1)
		{
			cout << endl << "Q��ֵ��������, ����������!";
			Sleep(2000);
			system("cls");  //����
			cin.clear();
			char t;
			while ((t = cin.get()) != '\n');
			continue;
		}
		a[0] = i && j;  //������
		a[1] = i || j;  //������
		a[2] = (!i) || j;  //�̺����㣬����ת��Ϊ������ʽ
		a[3] = ((!i) || j) && ((!j) || i);  //��ֵ���㣬����ת��Ϊ������ʽ
		cout << endl << " ��ȡ:" << endl;
		cout << "       P/\\Q = " << a[0] << endl;
		cout << endl << " ��ȡ:" << endl;
		cout << "       P\\/Q = " << a[1] << endl;
		cout << endl << " ����:" << endl;
		cout << "       P->Q = " << a[2] << endl;
		cout << endl << " ˫����:" << endl;
		cout << "       P<->Q = " << a[3] << endl;
		while (1) {
			cout << endl << "�Ƿ��������?��y/n��"; //ѯ���Ƿ��������
			cin >> s;
			if (s == 'y' || s == 'n')
			{
				if (s == 'y')
				{
					system("cls");  //����
					char t;
					while ((t = cin.get()) != '\n');
					break;  //���ض���
				}
				else
				{
					cout << "��ӭ�´��ٴ�ʹ��!" << endl;  //�˳�
					exit(0);
				}
			}
			else
			{
				cout << "�������,����������!" << endl; //����У��
				continue;
			}
		}
	}
	return 0;
}