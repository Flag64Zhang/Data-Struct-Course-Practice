/*
Version: Final
Author: <William Zhang 23124426>
Date: 2024/9/20
*/
#include"W5_Definition.h"
int main() {
	LinkQuNode* q = NULL;
	int n = 1;
		while (n != 0) {
			cout << " = ====�������Ӧ������ִ����Ӧ����==== = " << endl;
			cout << "1.��ʼ������" << endl;
			cout << "2.�ж������Ƿ�Ϊ��" << endl;
			cout << "3.���ν���" << endl;
			cout << "4.һ���Խ���" << endl;
			cout << "5.����һ��Ԫ�أ������Ԫ��" << endl;
			cout << "6.��������" << endl;
			cout << "7.�����������" << endl;
			cout << "= ====--------==== =" << endl;
			cin >> n;
			switch (n)
			{
			case 1:
				cout << "----��ʼ������----" << endl;
				InitQueue(q);
				cout << "----���ӳ�ʼ���ɹ�----" << endl;
				break;
			case 2:
				cout << "----�ж������Ƿ�Ϊ��----" << endl;
				if (QueueEmpty(q))
					cout << "����Ϊ�գ�" << endl;
				else
					cout << "���Ӳ�Ϊ�գ�" << endl;
				break;
			case 3:
				cout << "----���ν���----" << endl;
				int num_1;
				ElemType e;
				cout << "���������Ԫ�ظ���" << endl;
				cin >> num_1;
				for (int c = 0; c < num_1; c++)
				{
					cout << "���������Ԫ��" << endl;
					cin >> e;
					enQueue(q, e);
				}
				break;
			case 4:
				cout << "----һ�ν���----" << endl;
				int num_2;
				cout << "���������Ԫ�ظ�����";
				cin >> num_2;
				if (num_2 > 0) {
					ElemType* arr = (ElemType*)malloc(num_2 * sizeof(ElemType));
					if (arr == NULL) {
						cout << "�ڴ����ʧ��" << endl;
						break;
					}
					cout << "������Ҫ��ջ��Ԫ�أ�"<<endl;
					for (int i = 0; i < num_2; ++i) {
						cin >> arr[i];
					}
					enQueueALL(q, arr,num_2);
					free(arr);
				}
				else {
					cout << "Ԫ�������������0" << endl;
				}
				break;
			case 5:
				cout << "----����һ��Ԫ�أ������Ԫ��----" << endl;
				deQueue(q, e);
				cout << "���ӵ�Ԫ����:" << e<<endl;
				break;
			case 6:
				cout << "----��������----" << endl;
				DestroyQueue(q);
				cout << "�������ٳɹ�" << endl;
				break;
			case 7:
				cout << "----�����������----" << endl;
				QueuePrint(q);
				break;
			default:
				cout << "�������!" << endl;
			}
			system("pause");
			system("cls");
		}
	return 0;
}