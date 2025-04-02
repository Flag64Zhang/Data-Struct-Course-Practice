#include "W7_Defination.h"
int main() {
	BTNode* b = NULL;
	int n =1;
	while (n != 0) {
		cout << " = ====请输入对应数字以执行相应操作==== = " << endl;
		cout << "1.创建二叉树" << endl;
		cout << "2.销毁二叉树" << endl;
		cout << "3.输出二叉树" << endl;
		cout << "4.求二叉树结点数" << endl;
		cout << "5.求二叉树叶子结点数" << endl;
		cout << "= ====--------==== =" << endl;
		cin >> n;
		switch (n) {
		case 1: {
			cout << "请以括号法输入想创建的二叉树:"<<endl;
			char str[50];
			cin >> str;
			CreatBTree(b, str);
			cout << "二叉树创建成功！"<<endl;
			break; }
			case 2:
				DestroyBTree(b);
				cout << "二叉树已销毁"<<endl;
				break;
			case 3:
				cout << "输出二叉树:" << endl;
				DispBTree(b);
				break; 
			case 4: 
				cout << "求二叉树结点数" << endl;
				cout<<CountNode(b)<<endl;
				break;
			case 5:
				cout << "求二叉树叶子结点数" << endl;
				cout << CountLeaf(b) << endl;
				break;
			default:
				cout << "输入错误！" << endl;
				break;
		}
		system("pause");
		system("cls");
	}
}