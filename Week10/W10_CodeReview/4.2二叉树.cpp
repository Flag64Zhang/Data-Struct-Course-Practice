#include <iostream>
using namespace std;
#define MaxSize 100
typedef char ElemType;
//声明
typedef struct tnode {
	ElemType data;
	struct tnode* lchild;
	struct tnode* rchild;
}BTNode;
//创建二叉树
void CreateBTree(BTNode*& b, char* str) {
	BTNode* St[MaxSize], * p;
	int top = -1, k, j = 0;
	b = NULL;
	char ch = str[j];
	while (ch != '\0') {
		switch (ch) {
		case '(':top++; k = 1; St[top] = p; break;
		case ',':k = 2; break;
		case ')':top--; break;
		default: {
			p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL)b = p;
			else {
				switch (k) {
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
			break;
		}
		}
		j++;
		ch = str[j];
	}
}
//销毁二叉树
void DestroyBTree(BTNode*& b) {
	if (b != NULL) {
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}
//查找结点
BTNode* FindNode(BTNode* b, ElemType x) {
	BTNode* p;
	if (b == NULL)
		return NULL;
	else if (b->data == x)
		return b;
	else {
		p = FindNode(b->lchild, x);
		if (p != NULL)
			return p;
		else
			return FindNode(b->rchild, x);
	}
}
//找孩子结点
BTNode* LchildFind(BTNode* b) {
	if (b == NULL || b->lchild == NULL)return NULL;
	else return b->lchild;
}
BTNode* RchildFind(BTNode* b) {
	if (b == NULL || b->rchild == NULL)return NULL;
	else return b->rchild;
}
//求高度
int BTHeight(BTNode* b) {
	int lchildh, rchildh;
	if (b == NULL)return (0);
	else {
		lchildh = BTHeight(b->lchild);
		rchildh = BTHeight(b->rchild);
		return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
	}
}
//输出二叉树
void DispBTree(BTNode* b) {
	if (b != NULL) {
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL) {
			printf("(");
			DispBTree(b->lchild);
			if (b->rchild != NULL) {
				printf(",");
				DispBTree(b->rchild);
			}
			printf(")");
		}
	}
}
//先序遍历
void PreOrder(BTNode* b) {
	if (b != NULL) {
		printf("%c", b->data);
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}
//中序遍历
void InOrder(BTNode* b) {
	if (b != NULL) {
		InOrder(b->lchild);
		printf("%c", b->data);
		InOrder(b->rchild);
	}
}
//后序遍历
void PostOrder(BTNode* b) {
	if (b != NULL) {
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf("%c", b->data);
	}
}