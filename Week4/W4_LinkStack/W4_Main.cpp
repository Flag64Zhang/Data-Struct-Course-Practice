/*
Author: <William Zhang 23124426>
Date: 2024/9/20
*/
#include "W4_De_Funcs.h"

int main()
{
	LinkStNode* s = NULL;
	int e;
	int n = 1;
	while (n != 0) {
		cout << " = ====�������Ӧ������ִ����Ӧ����==== = " << endl;
		cout << "1.��ʼ����ջ" << endl;
		cout << "2.���ν�ջ" << endl;
		cout << "3.һ���Խ�ջ" << endl;
		cout << "4.�����ջԪ��" << endl;
		cout << "5.������ջ" << endl;
		cout << "6.�ж���ջ�Ƿ�Ϊ��" << endl;
		cout << "7.ȡջ��Ԫ�ز����" << endl;
		cout << "= ====--------==== =" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "----��ʼ����ջ----" << endl;
			InitStack(s);
			break;
		case 2:
			cout << "----���ν�ջ----" << endl; {
				int num;
				char e;
				cout << "������Ԫ��������";
				cin >> num; 
				if (num > 0) {
					for (int i = 0; i < num; ++i) {
						cout << "����Ҫ��ջ�ĵ�" << i + 1 << "��Ԫ�أ�" << endl;
						cin >> e;
						PushSequentially(s, e);
					}
				}
				else {
					cout << "Ԫ�������������0" << endl;
				}
			}
			break;

		case 3:
			cout << "----һ�ν�ջ----" << endl;
			{
				int num;
				cout << "������Ԫ��������";
				cin >> num;
				if (num > 0) {
					ElemType* arr = (ElemType*)malloc(num * sizeof(ElemType));
					if (arr == NULL) {
						cout << "�ڴ����ʧ��" << endl;
						break;
					}
					cout << "������Ҫ��ջ��Ԫ�أ�";
					for (int i = 0; i < num; ++i) {
						cin >> arr[i];
					}
					PushAll(s, arr, num);
					free(arr);
				}
				else {
					cout << "Ԫ�������������0" << endl;
				}
			}
			break;
		case 4:
			cout << "----�����ջ----" << endl;
			LinkStPrint(s);
			break;
		case 5:
			cout << "----������ջ----" << endl;
			DestroyStack(s);
			cout << "������ջ�ɹ�" << endl;
			break;
		case 6:
			cout << "----�ж���ջ�Ƿ�Ϊ��----" << endl;
			if (StackEmpty(s))
				cout << "��ջΪ�գ�" << endl;
			else
				cout << "��ջ��Ϊ�գ�" << endl;
			break;
		case 7:
			cout << "----ȡջ��Ԫ�ز����----" << endl;
			{
				char topElement;
				if (GetTop(s, topElement))
					cout << "ջ��Ԫ��Ϊ��" << topElement << endl;
				else
					cout << "ջΪ�գ�" << endl;
			}
			break;
		default:
			cout << "�������" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}