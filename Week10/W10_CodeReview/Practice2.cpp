#include <iostream>
using namespace std;
#define MaxSize 100
typedef char ElemType;
typedef struct qnode {
	ElemType data;
	struct qnode* lchild;
	struct qnode* rchild;
}BTree;
//创建二叉树
void CreateBTree(BTree*& b, char* str) {
	int top = -1, j, k = 0;
	BTree* St[MaxSize],*p;
	b = NULL;
	char ch = str[k];
	while (ch != '\0') {
		switch (ch) {
		case '(':top++; j = 1; St[top] = p; break;
		case',':j = 2; break;
		case')':top--; break;
		default: {
			BTree* p = (BTree*)malloc(sizeof(BTree));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL)
				b = p;
			else
				switch (j) {
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			break;
		}
		}
		k++;
		ch = str[k];
	}
}
void CreateBTree(BTree*& b, char* str) {
	BTree * St[MaxSize], * p;
	int top = -1, k, j = 0;
	b = NULL;
	char ch = str[j];
	while (ch != '\0') {
		switch (ch) {
		case '(':top++; k = 1; St[top] = p; break;
		case ',':k = 2; break;
		case ')':top--; break;
		default: {
				p = (BTree*)malloc(sizeof(BTree));
				p->data = ch;
				p->lchild = p->rchild = NULL;
				switch (k) {
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
				break;
			}
		}
		j++;
		ch = str[j];
	}
}
//查找结点
BTree* FindNode(BTree*& b, ElemType x) {
	if (b == NULL)
		return NULL;
	else if (b->data == x)
		return b;
	else {
		BTree *p = FindNode(b->lchild,x);
		if (p != NULL)
			return p;
		else
			return(FindNode(b->rchild, x));
	}
}
//输出
void DispBTree(BTree*& b) {
	if (b != NULL) {
		printf("%c", b->data);
		if (b->lchild != NULL) {
			printf("(");
			printf("%c", b->lchild->data);
			if (b->rchild != NULL) {
				printf(",");
				printf("%c", b->rchild->data);
			}
			printf(")");
		}
	}
}
void DispBTree(BTree*& b) {
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