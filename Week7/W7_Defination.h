#pragma once
#include <iostream>
#define MaxSize 50
using namespace std;
typedef char ElemType;
typedef struct node {
	ElemType data;
	struct node* lchild;
	struct node* rchild;
}BTNode;

void CreatBTree(BTNode*& b, char* str);
void DestroyBTree(BTNode*& b);
void DispBTree(BTNode* b);
int CountNode(BTNode* b);
int CountLeaf(BTNode* b);