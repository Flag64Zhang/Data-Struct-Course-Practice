#include <iostream>
#include"W3_Definition.h"
int main()
{
	DLinkNode* L = NULL;
	int  i;
	char e;
	int n = 1;
	int d = 1;
	while (n != 0) {
		cout << " = ====�������Ӧ������ִ����Ӧ����==== = " << endl;
		cout << "1.��ʼ��˫����" << endl;
		cout << "2.����˫����" << endl;
		cout << "3.��������Ԫ��" << endl;
		cout << "4.���˫����" << endl;
		cout << "5.����˫����" << endl;
		cout << "6.�ж�˫�����Ƿ�Ϊ��" << endl;
		cout << "7.��˫������" << endl;
		cout << "8.������Ż�ȡָ��Ԫ��" << endl;
		cout << "9.����ָ��Ԫ����˫�����е�λ��" << endl;
		cout << "10.ɾ��ָ��Ԫ��" << endl;
		cout << "= ====--------==== =" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "----��ʼ��˫����----" << endl;
			InitList(L);
			break;
		case 2:
			cout << "----����˫����----" << endl;
			cout << "1.˫�������a,b,c,d,e" << endl;
			cout << "2.�Զ��崴��˫����" << endl;
			cin >> d;
			switch (d)
			{
			case 1: {
				CreateListR_1(L);
				cout << "˫�������ɹ�" << endl;
				break; }
			case 2: {
				cout << "��������Ҫa�����е�Ԫ�ظ�����";
				cin >> n;
				CreateListR(L,n);
				cout << "˫�������ɹ�" << endl;
				break; }
				}
			break;
			
		case 3:
			cout << "----��������Ԫ��----" << endl;
			cout << "������Ҫ�����λ�ã�";
			cin >> i;
			cout << "������Ҫ�����Ԫ�أ�";
			cin >> e;
			ListInsert(L, i, e);
			break;
		case 4:
			cout << "----���˫����----" << endl;
			DLinkListPrint(L);
			break;
		case 5:
			cout << "----����˫����----" << endl;
			DestroyList(L);
			cout << "����˫����ɹ�" << endl;
			break;
		case 6:
			cout << "----�ж�˫�����Ƿ�Ϊ��----" << endl;
			if (ListEmpty(L))
				cout << "˫����Ϊ�գ�" << endl;
			else
				cout << "˫����Ϊ�գ�" << endl;
			break;
		case 7:
			cout << "----��˫������----" << endl;
			cout << "˫������Ϊ��" << ListLength(L) << endl;
			break;
		case 8:
			cout << "----������Ż�ȡָ��Ԫ��----" << endl;
			cout << "������Ҫ��ȡ��Ԫ�ص���ţ�";
			cin >> i;
			GetElem(L, i, e);
			cout << "��Ԫ��Ϊ��" << e << endl;
			break;
		case 9:
			cout << "----����ָ��Ԫ����˫�����е�λ��----" << endl;
			cout << "������Ҫ���ҵ�Ԫ�أ�";
			cin >> e;
			i = LocateElem(L, e);
			if (i == 0) {
				cout << "Ԫ�ز����ڣ�" << endl;
			}
			else
				cout << "Ԫ����˫�����е�λ��Ϊ��" << i << endl;
			break;
		case 10:
			cout << "----ɾ��ָ��Ԫ��----" << endl;
			cout << "������Ҫɾ����Ԫ�ص���ţ�";
			cin >> i;
			ListDelete(L, i, e);
			cout << "ɾ���ɹ���" << endl;
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