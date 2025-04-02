#include <iostream>
using namespace std;
typedef char ElemType;
#define MaxSize 100

//声明
typedef struct {
	ElemType data[MaxSize];
	int top;
} SqStack;
//初始化
void InitList(SqStack*& s) {
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}
//销毁
void DestroyStack(SqStack*& s) {
	free(s);
}
//判断是否为空
bool StackEmpty(SqStack*& s) {
	return(s->top == -1);
}
//进栈
bool Push(SqStack*& s, ElemType e) {
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}
// 出栈
bool Pop(SqStack*& s, ElemType& e) {
	if (s->top == -1)
		return false;
	s->top++;
	e = s->data[s->top];
	return true;
}
//取栈顶元素
bool GetTop(SqStack*& s, ElemType& e) {
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}