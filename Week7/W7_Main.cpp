#include "W7_Defination.h"
int main() {
	BTNode* b = NULL;
	int n =1;
	while (n != 0) {
		cout << " = ====�������Ӧ������ִ����Ӧ����==== = " << endl;
		cout << "1.����������" << endl;
		cout << "2.���ٶ�����" << endl;
		cout << "3.���������" << endl;
		cout << "4.������������" << endl;
		cout << "5.�������Ҷ�ӽ����" << endl;
		cout << "= ====--------==== =" << endl;
		cin >> n;
		switch (n) {
		case 1: {
			cout << "�������ŷ������봴���Ķ�����:"<<endl;
			char str[50];
			cin >> str;
			CreatBTree(b, str);
			cout << "�����������ɹ���"<<endl;
			break; }
			case 2:
				DestroyBTree(b);
				cout << "������������"<<endl;
				break;
			case 3:
				cout << "���������:" << endl;
				DispBTree(b);
				break; 
			case 4: 
				cout << "������������" << endl;
				cout<<CountNode(b)<<endl;
				break;
			case 5:
				cout << "�������Ҷ�ӽ����" << endl;
				cout << CountLeaf(b) << endl;
				break;
			default:
				cout << "�������" << endl;
				break;
		}
		system("pause");
		system("cls");
	}
}