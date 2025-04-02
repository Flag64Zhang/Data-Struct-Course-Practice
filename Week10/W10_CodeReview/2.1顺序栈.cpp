#include <iostream>
using namespace std;
typedef char ElemType;
#define MaxSize 100

//����
typedef struct {
	ElemType data[MaxSize];
	int top;
} SqStack;
//��ʼ��
void InitList(SqStack*& s) {
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}
//����
void DestroyStack(SqStack*& s) {
	free(s);
}
//�ж��Ƿ�Ϊ��
bool StackEmpty(SqStack*& s) {
	return(s->top == -1);
}
//��ջ
bool Push(SqStack*& s, ElemType e) {
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}
// ��ջ
bool Pop(SqStack*& s, ElemType& e) {
	if (s->top == -1)
		return false;
	s->top++;
	e = s->data[s->top];
	return true;
}
//ȡջ��Ԫ��
bool GetTop(SqStack*& s, ElemType& e) {
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}