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
        cout << "__________请输入序号选择功能_________" << endl;
        cout << "1.建立AOV网" << endl;
        cout << "2.输出AOV网" << endl;
        cout << "3.实现AOV网拓扑序列输出" << endl;
        cout << "_______________________________________" << endl;
        cin >> i;
        switch (i) {
        case 1:
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    A[i][j] = matrixData[i][j];
            CreateAdj(G, A, n, e);
            cout << "AOV网建立成功!" << endl;
            break;
        case 2:
            cout << "AOV网输出如下:" << endl;
            DispAdj(G);
            cout << "AOV网输出完毕!" << endl;
            break;
        case 3:
            cout << "实现AOV网拓扑序列输出:" << endl;
            TopSort(G);
            cout << endl;
            break;
        default:
            cout << "输入错误!" << endl;
            break;
        }
        system("pause");
        system("cls");
    }
}