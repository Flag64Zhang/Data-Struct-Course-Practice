#include<iostream>
#include"table.h"
using namespace std;

int main() {
	SqList* L = NULL;
	bool loop = true;

	while (loop)
	{
		int option = 0;
		CheckInput(option, "==============请输入对应数字以执行操作==============\n\t1.初始化顺序表L\n\t2.摧毁顺序表L\n\t3.依次插入元素 a,b,c,d,e\n\t4.在指定索引增加元素\n\t5.删除指定索引元素\n\t6.删除指定对象元素\n\t7.输出顺序表L\n\t8.输出顺序表L的长度\n\t9.判定顺序表L是否为空\n\t10.输出顺序表L的第 i 个元素\n\t11.输出顺序表L的指定元素的首个索引\n\t12.获取顺序表中元素（阿斯克码）最大值\n===================输入-1退出程序===================");
		system("cls");
		switch (option)
		{
		case 1:{
			InitList(L);
			cout << "初始化完成" << endl;
			break;
		}
		case 2: {
			DestroyList(L);
			cout << "摧毁完成" << endl;
			break;
		}
		case 3: {
			CheckList(L);
			InsertByOrder(L);
			cout << "插入完成" << endl;
			break;
		}
		case 4: {
			ElemType e;
			int i = 0;
			CheckList(L);
			CheckInput(i, "请输入要插入的位置：");
			CheckInput(e, "请输入要插入的元素：");

			if (AddElemByOrder(L, e, i))
			{
				cout << "插入成功" << endl;
			}
			else {
				cout << "插入失败" << endl;
			}
			break;
		}
		case 5: {
			ElemType e;
			int i = 0;
			CheckList(L);
			CheckInput(i, "请输入要删除元素的索引：");

			if (DeleteElemByOrder(L, e, i)) {
				cout << "位于 " << i << "处的元素 " << e << " 已被删除" << endl;
			}
			else {
				cout << "删除失败" << endl;
			}
			break;
		}
		case 6: {
			ElemType e;
			int i = 0;
			CheckList(L);
			CheckInput(e, "请输入要删除元素对象：");

			if (DeleteElemByObj(L, e, i)) {
				cout << "位于 " << i << "处的元素 " << e << " 已被删除" << endl;
			}
			else {
				cout << "删除失败" << endl;
			}
			break;
		}
		case 7: {
			CheckList(L);
			cout << "线性表输出如下: " << endl;
			ShowList(L);
			break;
		}
		case 8: {
			CheckList(L);
			cout << "顺序表的长度是：" << GetListLength(L) << endl;
			break;
		}
		case 9: {
			CheckList(L);
			if (IsEmpty(L)) {
				cout << "线性表是空" << endl;
			}
			else {
				cout << "线性表不是空的" << endl;
			}
			break;
		}
		case 10: {
			ElemType e;
			int i = 0;
			CheckList(L);
			CheckInput(i, "请输入索引：");

			if (GetElemByOrder(L, e, i)) {
				cout << "线性表第" << i << "个元素是：" << e << endl;
			}
			else {
				cout << "错误，请检测索引值是否正确" << endl;
			}
			break;
		}
		case 11: {
			ElemType e;
			CheckList(L);
			CheckInput(e, "请输入元素：");

			int result = GetFirstOrderByElem(L, e);

			if (result != 0) {
				cout << "元素 " << e << " 首次出现的索引值是：" << result << endl;
			}
			else {
				cout << "查无此元素" << endl;
			}
			break;
		}
		case 12: {
			ElemType max;
			int i = 0;
			CheckList(L);
			if (GetMaxElem(L, max, i)) {
				cout << "该顺序表中最大值为：" << max << " 其位于第 " << i << " 位" << endl;
			}
			else {
				cout << "无法获取" << endl;
			}
			break;
		}

		case -1: {
			loop = false;
			DestroyList(L);
			break;
		}
		default:
			cout << "输入错误，请重试！" << endl;
			break;
		}
	}
	return 0;
}