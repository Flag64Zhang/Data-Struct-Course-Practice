/*
Author: <William Zhang 23124426>
Date: 2024/9/20
*/
#pragma once
#include <iostream>
using namespace std;

typedef char ElemType;
//定义栈节点
typedef struct linknode{
	ElemType data;
	struct linknode* next;
}LinkStNode;

void InitStack(LinkStNode* &s)//初始化栈
{
	s=(LinkStNode*)malloc(sizeof(LinkStNode));
	s->next=NULL;
}

void DestroyStack(LinkStNode*& s)//销毁栈
{
	LinkStNode* pre=s,*p=s->next;
	while(p!=NULL)
	{
		pre=p;
		p=pre->next;
		free(pre);
	}
	free(s);
	s=NULL;
}

bool StackEmpty(LinkStNode* s)//判断栈是否为空
{
	return s->next==NULL;
}

bool PushSequentially(LinkStNode* &s,ElemType e)//依次进栈
{
	LinkStNode* p=(LinkStNode*)malloc(sizeof(LinkStNode));
	p->data=e;
	p->next=s->next;
	s->next=p;
	return true;
}

// 一次进栈多个元素
void PushAll(LinkStNode*& s, const ElemType elems[], int size) {
	for (int i = 0; i < size; ++i) {
		LinkStNode* p = (LinkStNode*)malloc(sizeof(LinkStNode)); 
		if (p == NULL) {
			cout << "内存分配失败" << endl;
			return;
		}
		p->data = elems[i]; 
		p->next = s->next; 
		s->next = p; 
	}
}

void LinkStPrint(LinkStNode*& s) //依次输出栈内元素
{
	if (s == nullptr) {
		cout << "栈未初始化或已被销毁" << endl;
		return;
	}
	if (s->next == NULL) {
		cout << "栈为空" << endl;
		return;
	}
	LinkStNode* p = s->next;
	int count = 1;
	cout << "链栈中第" << count << "个元素为：" << p->data << endl;
	p = p->next; 
	while (p != NULL) {
		count++; 
		cout << "链栈中第" << count << "个元素为：" << p->data << endl;
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
	return true;
}