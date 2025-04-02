#include<iostream>
using namespace std;

typedef char ElemType;
#define MAX 100

typedef struct {
	ElemType Data[MAX];
	int length;
}SqList;

void InitList(SqList*& L) {
	L = (SqList*)malloc(sizeof(SqList));
	L -> length = 0;
}

void DestroyList(SqList*& L) {
	free(L);
	L = NULL;
}

void InsertByOrder(SqList* L) {
	char arr[] = { 'a','b','c','d','e' };
	for (int i = 0;i < 5;i++)
	{
		L->Data[L->length++] = arr[i];
	}
}

bool AddElemByOrder(SqList* L, ElemType e, int i) {
	int j = L->length;
	if (i<1 || i > L->length + 2) {
		return false;
	}
	while (j >= i) {
		L->Data[j] = L->Data[j-1];
		j--;
	}
	L->Data[i - 1] = e;
	L->length++;
	return true;
}

bool DeleteElemByOrder(SqList* L, ElemType& e, int i) {
	int j = i;
	if (i < 1 || i> L->length) {
		return false;
	}
	e = L->Data[i - 1];
	while (j < L->length) {
		L->Data[j - 1] = L->Data[j];
		j++;
	}
	L->length--;
	return true;
}

bool DeleteElemByObj(SqList* L, ElemType e, int& i) {
	int j = 0;
	while (j < L->length) {
		if (e == L->Data[j]) {
			i = j + 1;
			return DeleteElemByOrder(L, e, j + 1);
		}
		j++;
	}
	return true;
}

void ShowList(SqList* L) {
	for (int i = 0; i < L->length; i++) {
		cout << L->Data[i] << " ";
	}
	cout << endl;
}

int GetListLength(SqList* L) {
	return L->length;
}

bool IsEmpty(SqList*L) {
	if (L->length == 0) {
		return true;
	}
	return false;
}

bool GetElemByOrder(SqList* L,ElemType &e, int i) {
	if (i<1 || i> L->length) {
		return false;
	}
	e = L->Data[i - 1];
	return true;
}

int GetFirstOrderByElem(SqList* L, ElemType e) {
	int n = 0;
	while (n < L->length) {
		if (L->Data[n] == e) {
			return n+1;
		}
		n++;
	}
	return 0;
}

bool GetMaxElem(SqList* L,ElemType &max, int &i) {
	if (L->length == 0) {
		return false;
	}
	else {
		max = L->Data[0];
		for (int j = 0; j < L->length;j++) {
			if (L->Data[j] > max) {
				max = L->Data[j];
				i = j+1;
			}
		}
		return true;
	}
}

void CheckInput(ElemType& e, string str) {
	bool loop = true;
	while (loop) {
		cout << str << endl;
		if (cin >> e) {
			loop = false;
		}
		else {
			cout << "输入有误，请重试" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

void CheckInput(int& i, string str) {
	bool loop = true;
	while (loop) {
		cout << str << endl;
		if (cin >> i) {
			loop = false;
		}
		else {
			cout << "输入有误，请重试" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

void CheckList(SqList*& L) {
	if (L == NULL) {
		cout << "列表不存在或已被销毁，以自动初始化" << endl;
		InitList(L);
	}
}