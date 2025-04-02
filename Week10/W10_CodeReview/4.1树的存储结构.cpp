#include <iostream>
using namespace std;
typedef char ElemType;
#define MaxSize 100
//树的存储结构

//双亲存储结构(求双亲节点容易，求子节点需要遍历)
typedef struct {
	ElemType data;
	int parent;
}PTree[MaxSize];
//孩子链存储结构(查找子节点容易，求双亲节点需要遍历，且树度大时空指针域多)
#define MaxSons 10//(树的度)
typedef struct node {
	ElemType data;
	struct node* sons[MaxSons];
}TSonNode;
int TreeHeight1(TSonNode* t) {//(孩子链存储结构求树高度的递归算法)
	TSonNode* p;
	int i, h, maxh = 0;
	if (t == NULL)return 0;
	else {
		for (i = 0; i < MaxSons; i++) {
			p = t->sons[i];
			if (p != NULL) {
				h = TreeHeight1(p);
				if (maxh < h) maxh = h;
			}
		}
		return(maxh + 1);
	}
}
//孩子兄弟链存储结构(方便实现树和二叉树之间的转换，但求双亲节点需要遍历)
typedef struct tnode {
	ElemType data;
	struct tnode* hp;//兄弟
	struct tnode* vp;//孩子
}TSBNode;
int TreeHeight2(TSBNode* t) {//(孩子兄弟链存储结构求树高度的递归算法)
	TSBNode* p;
	int h, maxh = 0;
	if (t == NULL) return 0;
	else {
		p = t->vp;
		while (p != NULL) {
			h = TreeHeight2(p);
			if (maxh < h)maxh = h;
			p = p->hp;
		}
		return (maxh + 1);
	}
}
