#include <iostream>
#include"W3_Definition.h"
int main()
{
	DLinkNode* L = NULL;
	int  i;
	char e;
	int n = 1;
	int d = 1;
	while (n != 0) {
		cout << " = ====请输入对应数字以执行相应操作==== = " << endl;
		cout << "1.初始化双链表" << endl;
		cout << "2.创建双链表" << endl;
		cout << "3.插入数据元素" << endl;
		cout << "4.输出双链表" << endl;
		cout << "5.销毁双链表" << endl;
		cout << "6.判断双链表是否为空" << endl;
		cout << "7.求双链表长度" << endl;
		cout << "8.按照序号获取指定元素" << endl;
		cout << "9.查找指定元素在双链表中的位置" << endl;
		cout << "10.删除指定元素" << endl;
		cout << "= ====--------==== =" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "----初始化双链表----" << endl;
			InitList(L);
			break;
		case 2:
			cout << "----创建双链表----" << endl;
			cout << "1.双链表插入a,b,c,d,e" << endl;
			cout << "2.自定义创建双链表" << endl;
			cin >> d;
			switch (d)
			{
			case 1: {
				CreateListR_1(L);
				cout << "双链表建立成功" << endl;
				break; }
			case 2: {
				cout << "请输入需要a数组中的元素个数：";
				cin >> n;
				CreateListR(L,n);
				cout << "双链表建立成功" << endl;
				break; }
				}
			break;
			
		case 3:
			cout << "----插入数据元素----" << endl;
			cout << "请输入要插入的位置：";
			cin >> i;
			cout << "请输入要插入的元素：";
			cin >> e;
			ListInsert(L, i, e);
			break;
		case 4:
			cout << "----输出双链表----" << endl;
			DLinkListPrint(L);
			break;
		case 5:
			cout << "----销毁双链表----" << endl;
			DestroyList(L);
			cout << "销毁双链表成功" << endl;
			break;
		case 6:
			cout << "----判断双链表是否为空----" << endl;
			if (ListEmpty(L))
				cout << "双链表为空！" << endl;
			else
				cout << "双链表不为空！" << endl;
			break;
		case 7:
			cout << "----求双链表长度----" << endl;
			cout << "双链表长度为：" << ListLength(L) << endl;
			break;
		case 8:
			cout << "----按照序号获取指定元素----" << endl;
			cout << "请输入要获取的元素的序号：";
			cin >> i;
			GetElem(L, i, e);
			cout << "该元素为：" << e << endl;
			break;
		case 9:
			cout << "----查找指定元素在双链表中的位置----" << endl;
			cout << "请输入要查找的元素：";
			cin >> e;
			i = LocateElem(L, e);
			if (i == 0) {
				cout << "元素不存在！" << endl;
			}
			else
				cout << "元素在双链表中的位置为：" << i << endl;
			break;
		case 10:
			cout << "----删除指定元素----" << endl;
			cout << "请输入要删除的元素的序号：";
			cin >> i;
			ListDelete(L, i, e);
			cout << "删除成功！" << endl;
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