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
        cout << "__________请输入序号选择功能_________" << endl;
        cout << "1.建立带权图的邻接表" << endl;
        cout << "2.输出带权图的邻接表" << endl;
        cout << "3.实现图的深度优先遍历并输出" << endl;
        cout << "_______________________________________" << endl;
        cin >> i;
        switch (i) {
            case 1:
                for (int i = 0; i < n; i++) 
                    for (int j = 0; j < n; j++) 
                        A[i][j] = matrixData[i][j];
                CreateAdj(G, A, n, e);
                cout << "带权图的邻接表建立成功!" << endl;
                break;
            case 2:
                cout << "带权图的邻接表输出如下:" << endl;
                DispAdj(G);
                cout << "带权图的邻接表输出完毕!" << endl;
                break;
            case 3:
                cout << "带权图的邻接表深度优先遍历并输出:" << endl;
                DFS(G, 2);
                cout << endl;
                DispAdj(G);
                break;
            default:
                cout << "输入错误!" << endl;
                break;
        }
        system("pause");
        system("cls");
    }
}