#include <iostream>
using namespace std;
typedef char ElemType;
#define MaxSize 100
//���Ĵ洢�ṹ

//˫�״洢�ṹ(��˫�׽ڵ����ף����ӽڵ���Ҫ����)
typedef struct {
	ElemType data;
	int parent;
}PTree[MaxSize];
//�������洢�ṹ(�����ӽڵ����ף���˫�׽ڵ���Ҫ�����������ȴ�ʱ��ָ�����)
#define MaxSons 10//(���Ķ�)
typedef struct node {
	ElemType data;
	struct node* sons[MaxSons];
}TSonNode;
int TreeHeight1(TSonNode* t) {//(�������洢�ṹ�����߶ȵĵݹ��㷨)
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
//�����ֵ����洢�ṹ(����ʵ�����Ͷ�����֮���ת��������˫�׽ڵ���Ҫ����)
typedef struct tnode {
	ElemType data;
	struct tnode* hp;//�ֵ�
	struct tnode* vp;//����
}TSBNode;
int TreeHeight2(TSBNode* t) {//(�����ֵ����洢�ṹ�����߶ȵĵݹ��㷨)
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
