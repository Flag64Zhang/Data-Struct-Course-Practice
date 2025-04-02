#include "W7_Defination.h"
//二叉树创建
void CreatBTree(BTNode*& b, char* str) {
	BTNode* St[MaxSize], * p = NULL;
	int top = -1;
	int k, j =0;
	char ch;
	b = NULL;
	ch = str[j];
	while (ch != '\0') {
		switch (ch) {
		case'(':
			top++;St[top] = p;k = 1;break;
		case')':
			top--;break;
		case',': 
			k = 2;break;
		default: 
			p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL) {
				b = p;
			}
			else {
				switch (k) {
				case 1: 
						St[top]->lchild = p;
						break;
				case 2: 
						St[top]->rchild = p;
						break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}
//二叉树的销毁
void DestroyBTree(BTNode*& b) {
	if (b != NULL) {
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}
//二叉树的输出
void DispBTree(BTNode* b) {
	if (b != NULL) {
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL) {
			printf("(");
			DispBTree(b->lchild);
			if (b->rchild != NULL) {
				printf(",");
			}
			DispBTree(b->rchild);
			printf(")");
		}
	}
}
//求二叉树结点数
int CountNode(BTNode* b) {
	if (b == NULL) 
		return 0;
	return CountNode(b->lchild) + CountNode(b->rchild) + 1;
}
//求二叉树叶子结点数
int CountLeaf(BTNode* b) {
	if (b == NULL)
		return 0;
	if (b->lchild == NULL && b->rchild == NULL)
		return 1;
	return CountLeaf(b->lchild) + CountLeaf(b->rchild);
}