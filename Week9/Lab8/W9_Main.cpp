#include "W9_Defination.h"
int main() {
	cout << "Welcome to use!" << endl;
	cout << "Author:William_Zhang\nStudent Number:23124426\nDate:2024/10/17" << endl;
	MatGraph g;
	int i = 1;
	while (i != 0) {
		cout << "__________请输入序号选择功能_________" << endl;
		cout << "1.建立带权图的邻接矩阵" << endl;
		cout << "2.基于kruscal算法实现该图的最小生成树" << endl;
		cout << "3.以顶点0为源点的单源最短路径求解并输出" << endl;
		cout << "_______________________________________" << endl;
		cin >> i;
        switch (i) {
        case 1:
            CreatMat(g);
            DispMat(g);
            cout << "带权图的邻接矩阵建立成功!" << endl;
            break;
        case 2:
            cout << "生成带权图的最小生成树:" << endl;
            Kruskal(g);
            cout << "带权图的最小生成树生成完毕!" << endl;
            break;
        case 3:
            cout << "以顶点0为源点的单源最短路径求解并输出:" << endl;
            Dijkstra(g, 0);
            break;
        default:
            cout << "输入错误!" << endl;
            break;
        }
        system("pause");
        system("cls");
    }
}