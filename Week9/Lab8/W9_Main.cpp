#include "W9_Defination.h"
int main() {
	cout << "Welcome to use!" << endl;
	cout << "Author:William_Zhang\nStudent Number:23124426\nDate:2024/10/17" << endl;
	MatGraph g;
	int i = 1;
	while (i != 0) {
		cout << "__________���������ѡ����_________" << endl;
		cout << "1.������Ȩͼ���ڽӾ���" << endl;
		cout << "2.����kruscal�㷨ʵ�ָ�ͼ����С������" << endl;
		cout << "3.�Զ���0ΪԴ��ĵ�Դ���·����Ⲣ���" << endl;
		cout << "_______________________________________" << endl;
		cin >> i;
        switch (i) {
        case 1:
            CreatMat(g);
            DispMat(g);
            cout << "��Ȩͼ���ڽӾ������ɹ�!" << endl;
            break;
        case 2:
            cout << "���ɴ�Ȩͼ����С������:" << endl;
            Kruskal(g);
            cout << "��Ȩͼ����С�������������!" << endl;
            break;
        case 3:
            cout << "�Զ���0ΪԴ��ĵ�Դ���·����Ⲣ���:" << endl;
            Dijkstra(g, 0);
            break;
        default:
            cout << "�������!" << endl;
            break;
        }
        system("pause");
        system("cls");
    }
}