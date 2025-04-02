/*
Author: <William Zhang 23124426>
Date: 2024/9/20
*/
#include "W4_De_Funcs.h"

int main()
{
	LinkStNode* s = NULL;
	int e;
	int n = 1;
	while (n != 0) {
		cout << " = ====请输入对应数字以执行相应操作==== = " << endl;
		cout << "1.初始化链栈" << endl;
		cout << "2.依次进栈" << endl;
		cout << "3.一次性进栈" << endl;
		cout << "4.输出链栈元素" << endl;
		cout << "5.销毁链栈" << endl;
		cout << "6.判断链栈是否为空" << endl;
		cout << "7.取栈顶元素并输出" << endl;
		cout << "= ====--------==== =" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "----初始化链栈----" << endl;
			InitStack(s);
			break;
		case 2:
			cout << "----依次进栈----" << endl; {
				int num;
				char e;
				cout << "请输入元素数量：";
				cin >> num; 
				if (num > 0) {
					for (int i = 0; i < num; ++i) {
						cout << "输入要进栈的第" << i + 1 << "个元素：" << endl;
						cin >> e;
						PushSequentially(s, e);
					}
				}
				else {
					cout << "元素数量必须大于0" << endl;
				}
			}
			break;

		case 3:
			cout << "----一次进栈----" << endl;
			{
				int num;
				cout << "请输入元素数量：";
				cin >> num;
				if (num > 0) {
					ElemType* arr = (ElemType*)malloc(num * sizeof(ElemType));
					if (arr == NULL) {
						cout << "内存分配失败" << endl;
						break;
					}
					cout << "请输入要进栈的元素：";
					for (int i = 0; i < num; ++i) {
						cin >> arr[i];
					}
					PushAll(s, arr, num);
					free(arr);
				}
				else {
					cout << "元素数量必须大于0" << endl;
				}
			}
			break;
		case 4:
			cout << "----输出链栈----" << endl;
			LinkStPrint(s);
			break;
		case 5:
			cout << "----销毁链栈----" << endl;
			DestroyStack(s);
			cout << "销毁链栈成功" << endl;
			break;
		case 6:
			cout << "----判断链栈是否为空----" << endl;
			if (StackEmpty(s))
				cout << "链栈为空！" << endl;
			else
				cout << "链栈不为空！" << endl;
			break;
		case 7:
			cout << "----取栈顶元素并输出----" << endl;
			{
				char topElement;
				if (GetTop(s, topElement))
					cout << "栈顶元素为：" << topElement << endl;
				else
					cout << "栈为空！" << endl;
			}
			break;
		default:
			cout << "输入错误！" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}