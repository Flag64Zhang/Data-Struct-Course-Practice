#include"W9_Defination.h"

int main() {
    cout << "Welcome to use!" << endl;
    cout << "Author:William_Zhang\nStudent Number:23124426\nDate:2024/10/24" << endl;
    AdjGraph* G = NULL;
    int A[MAXV][MAXV] = { 0 };
    int i = 1;
    int n = 7;
    int e = 10;
    int matrixData[7][7] = {
        {0, 0, 1, 0, 0,0,0},
        {0, 0, 0, 1, 1,0,1},
        {0, 0, 0, 1, 0,0,0},
        {0, 0, 0, 0, 1,1,0},
        {0, 0, 0, 0, 0,0,0},
        {0, 0, 0, 0, 0,0,0},
        {0, 0, 0, 0, 0,1,0}
    };
    while (i != 0) {
        cout << "__________���������ѡ����_________" << endl;
        cout << "1.����AOV��" << endl;
        cout << "2.���AOV��" << endl;
        cout << "3.ʵ��AOV�������������" << endl;
        cout << "_______________________________________" << endl;
        cin >> i;
        switch (i) {
        case 1:
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    A[i][j] = matrixData[i][j];
            CreateAdj(G, A, n, e);
            cout << "AOV�������ɹ�!" << endl;
            break;
        case 2:
            cout << "AOV���������:" << endl;
            DispAdj(G);
            cout << "AOV��������!" << endl;
            break;
        case 3:
            cout << "ʵ��AOV�������������:" << endl;
            TopSort(G);
            cout << endl;
            break;
        default:
            cout << "�������!" << endl;
            break;
        }
        system("pause");
        system("cls");
    }
}