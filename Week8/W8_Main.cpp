#include "W8_Defination.h"
int main() {
    cout << "Welcome to use!" << endl;
    cout << "Author:William_Zhang\nStudent Number:23124426\nDate:2024/10/17" << endl;
    AdjGraph* G = NULL;
    int A[MAXV][MAXV] = { 0 }; 
    int i = 1;
    int n = 6; 
    int e = 10; 
    int matrixData[6][6] = {
        {0, 5, INF, 7, INF,3},
        {INF, 0, 4, INF,INF,INF},
        {8, INF, 0, INF, INF,9},
        {INF, INF, 5, 0, INF,6},
        {INF,INF,INF, 5, 0, INF},
        {3,INF,INF,INF,1,0}
    };
    while (i != 0) {
        cout << "__________���������ѡ����_________" << endl;
        cout << "1.������Ȩͼ���ڽӱ�" << endl;
        cout << "2.�����Ȩͼ���ڽӱ�" << endl;
        cout << "3.ʵ��ͼ��������ȱ��������" << endl;
        cout << "_______________________________________" << endl;
        cin >> i;
        switch (i) {
            case 1:
                for (int i = 0; i < n; i++) 
                    for (int j = 0; j < n; j++) 
                        A[i][j] = matrixData[i][j];
                CreateAdj(G, A, n, e);
                cout << "��Ȩͼ���ڽӱ����ɹ�!" << endl;
                break;
            case 2:
                cout << "��Ȩͼ���ڽӱ��������:" << endl;
                DispAdj(G);
                cout << "��Ȩͼ���ڽӱ�������!" << endl;
                break;
            case 3:
                cout << "��Ȩͼ���ڽӱ�������ȱ��������:" << endl;
                DFS(G, 2);
                cout << endl;
                DispAdj(G);
                break;
            default:
                cout << "�������!" << endl;
                break;
        }
        system("pause");
        system("cls");
    }
}