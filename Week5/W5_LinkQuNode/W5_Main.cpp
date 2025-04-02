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
			cout << " = ====请输入对应数字以执行相应操作==== = " << endl;
			cout << "1.初始化链队" << endl;
			cout << "2.判断链队是否为空" << endl;
			cout << "3.依次进队" << endl;
			cout << "4.一次性进队" << endl;
			cout << "5.出队一个元素，输出该元素" << endl;
			cout << "6.销毁链队" << endl;
			cout << "7.输出出队序列" << endl;
			cout << "= ====--------==== =" << endl;
			cin >> n;
			switch (n)
			{
			case 1:
				cout << "----初始化链队----" << endl;
				InitQueue(q);
				cout << "----链队初始化成功----" << endl;
				break;
			case 2:
				cout << "----判断链队是否为空----" << endl;
				if (QueueEmpty(q))
					cout << "链队为空！" << endl;
				else
					cout << "链队不为空！" << endl;
				break;
			case 3:
				cout << "----依次进队----" << endl;
				int num_1;
				ElemType e;
				cout << "请输入进队元素个数" << endl;
				cin >> num_1;
				for (int c = 0; c < num_1; c++)
				{
					cout << "请输入进队元素" << endl;
					cin >> e;
					enQueue(q, e);
				}
				break;
			case 4:
				cout << "----一次进队----" << endl;
				int num_2;
				cout << "请输入进队元素个数：";
				cin >> num_2;
				if (num_2 > 0) {
					ElemType* arr = (ElemType*)malloc(num_2 * sizeof(ElemType));
					if (arr == NULL) {
						cout << "内存分配失败" << endl;
						break;
					}
					cout << "请输入要进栈的元素："<<endl;
					for (int i = 0; i < num_2; ++i) {
						cin >> arr[i];
					}
					enQueueALL(q, arr,num_2);
					free(arr);
				}
				else {
					cout << "元素数量必须大于0" << endl;
				}
				break;
			case 5:
				cout << "----出队一个元素，输出该元素----" << endl;
				deQueue(q, e);
				cout << "出队的元素是:" << e<<endl;
				break;
			case 6:
				cout << "----销毁链队----" << endl;
				DestroyQueue(q);
				cout << "链队销毁成功" << endl;
				break;
			case 7:
				cout << "----输出出队序列----" << endl;
				QueuePrint(q);
				break;
			default:
				cout << "输入错误!" << endl;
			}
			system("pause");
			system("cls");
		}
	return 0;
}