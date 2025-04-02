/*
Author: <William Zhang 23124426>
Date: 2024/9/20
*/
#include <iostream>
using namespace std;

typedef char ElemType;
//定义栈节点
typedef struct linknode {
	ElemType data;
	struct linknode* next;
}LinkStNode;

void InitStack(LinkStNode*& s) {//初始化栈
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}
bool Pop(LinkStNode*& s, ElemType& e)//出栈
{
	LinkStNode* p ;
	if (s->next == NULL)
		return false;
	p = s->next;
	e = p->data;
	s->next = p->next;
	cout << "[出栈]元素为：" << e << endl;
	free(p);
	return true;
}
void DestroyStack(LinkStNode*& s)//销毁栈
{
	LinkStNode* pre = s, * p = s->next;
	while (p != NULL)
	{
		pre = p;
		p = pre->next;
		free(pre);
	}
	free(s);
	s = NULL;
}

bool StackEmpty(LinkStNode* s)//判断栈是否为空
{
	return s->next == NULL;
}

bool PushSequentially(LinkStNode*& s, ElemType e)//依次进栈
{
	LinkStNode* p = (LinkStNode*)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
	cout<<"[进栈]元素为："<<e<<endl;
	return true;
}

// 一次进栈多个元素
void PushAll(LinkStNode*& s,ElemType elems[]) {
	cout << "[进栈]元素为：";
	for (int i = 0; i < 3; ++i) {
		LinkStNode* p = (LinkStNode*)malloc(sizeof(LinkStNode));
		if (p == NULL) {
			cout << "内存分配失败" << endl;
			return;
		}
		p->data = elems[i];
		p->next = s->next;
		s->next = p;
		cout << elems[i] << " ";
	}
	cout << endl;
}

void LinkStPrint(LinkStNode*& s) //依次输出栈内元素
{
	if (s->next == NULL) {
		cout << "栈为空" << endl;
		return;
	}
	LinkStNode* p = s->next;
	cout << "链栈中元素为：";
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

bool GetTop(LinkStNode* s, ElemType& e)//取栈顶元素并输出
{
	if (s->next == NULL) {
		return false;
	}
	e = s->next->data;
	cout << "栈顶元素为：" << e << endl;
	return true;
}

int length(LinkStNode* top)//获取链表长度
{
	int i = 0;
	LinkStNode* p = top;
	while (p->next != NULL)
	{
		p = p->next;
		i++;
	}
	return i;
}

void SortStack(LinkStNode*& s) {
	LinkStNode* temp = NULL;
	InitStack(temp); // 初始化一个临时栈

	static int run_times = 0; // 记录递归运行次数
	int len=length(s); // 链栈长度

	LinkStNode* p = s->next; // 指向链栈的第一个元素
	char min = s->next->data; // 假设最小值为第一个元素
	int index = 0; // 记录最小值的位置
	int temp_num = 0; // 临时计数器

	// 寻找最小值和它的索引
	for (int i = 0; i < len - run_times; i++) {
		if (p->data < min) {
			min = p->data;
			index = temp_num;
		}
		p = p->next;
		temp_num++;
	}

	// 将小于最小值的元素移动到临时栈
	for (int i = 0; i < index; i++) {
		char elem;
		Pop(s, elem);
		PushSequentially(temp, elem);
	}

	// 弹出最小元素
	Pop(s, min);

	// 将剩余的元素移动到临时栈
	for (int j = 0; j < len - index - 1 - run_times; j++) {
		char elem;
		Pop(s, elem);
		PushSequentially(temp, elem);
	}

	// 将最小元素放回原栈
	PushSequentially(s, min);

	// 将临时栈中的元素移回原栈
	while (temp->next != NULL) {
		char elem;
		Pop(temp, elem);
		PushSequentially(s, elem);
	}

	run_times++;

	DestroyStack(temp); // 销毁临时栈

	if (run_times == len) {
		return; // 如果递归次数等于链栈长度，结束递归
	}
	else {
		SortStack(s); // 递归调用
	}
}


int main() {
	LinkStNode* s = nullptr;
	InitStack(s);
	ElemType arr[] = {'a', 'b', 'c'};
	// 进栈测试数据
	PushAll(s,arr);
	PushSequentially(s, 'd');
	PushSequentially(s, 'e');
	PushSequentially(s, 'f');

	cout << "原始栈: ";
	LinkStPrint(s);

	SortStack(s);

	cout << "处理栈: ";
	LinkStPrint(s);

	DestroyStack(s);
	return 0;
}