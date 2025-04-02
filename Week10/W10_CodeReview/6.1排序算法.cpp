#include<iostream>
using namespace std;
typedef int KeyType;
typedef char InfoType;
typedef struct {
	KeyType key;
	InfoType data;
}RecType;
//÷±Ω”≤Â»Î≈≈–Ú
void InsertSort(RecType R[], int n) {
	int i, j; RecType tmp;
	for (i = 1; i < n; i++) {
		if (R[i].key < R[i - 1].key) {
			tmp = R[i];
			j = i - 1;
		}
		do {
			R[j + 1] = R[j];
			j--;
		} while (j >= 0 && R[j].key > tmp.key);
		R[j] = tmp;
	}
}
//’€∞Î≤Â»Î≈≈–Ú
void BinInsertSort(RecType R[], int n) {
	int i, j, mid, low, high;
	RecType tmp;
	for (i = 1; i < n; i++) {
		if (R[i].key < R[i - 1].key) {
			tmp = R[i];
			low = 0; high = i - 1;
			while (low <= high) {
				mid = (high + low) / 2;
				if (tmp.key < R[mid].key)
					high = mid - 1;
				else
					low = mid + 1;
			}
			for (j = i - 1; j >= high + 1; j--)
				R[j + 1] = R[j];
			R[high + 1] = tmp;
		}
	}
}
//œ£∂˚≈≈–Ú
void ShellSort(RecType R[], int n) {
	int i, j, d;
	RecType tmp;
	d = n / 2;
	while (d > 0) {
		for (i = d; i < n; i++) {
			tmp = R[i];
			j = i - d;
			while (j >= 0 && tmp.key < R[j].key) {
				R[j + d] = R[j];
				j = j - d;
			}
			R[j + d] = tmp;
		}
		d = d / 2;
	}
}
//√∞≈›≈≈–Ú
void BubbleSort(RecType R[], int n) {
	int i, j;
	RecType tmp;
	for (i = 0; i < n - 1; i++)
		for (j = n - 1; j > i; j--)
			if (R[j].key < R[j - 1].key) {
				tmp = R[j];
				R[j] = R[j - 1];
				R[j - 1] = tmp;
			}
}
//√∞≈›≈≈–Ú∏ƒ¡º
void BubbleSort_1(RecType R[], int n) {
	int i, j;
	RecType tmp;
	bool exchange;
	for (i = 0; i < n - 1; i++) {
		exchange = false;
		for (j = n - 1; j > i; j--) {
			if (R[j].key < R[j - 1].key) {
				tmp = R[j];
				R[j] = R[j - 1];
				R[j - 1] = tmp;
				exchange = true;
			}
		}
		if (!exchange)
			return;
	}
}
//øÏÀŸ≈≈–Ú
int partition(RecType R[], int s, int t) {//ªÆ∑÷
	int i = s; int j = t;
	RecType base = R[i];
	while (i < j) {
		while (i < j && R[j].key >= base.key) {
			j--;
		}
		if (j > i) {
			R[i] = R[j];
			i++;
		}
		while (i > j && R[i].key <= base.key) {
			i++;
		}
		if (j > i) {
			R[i] = R[j];
			j--;
		}
	}
	R[i] = base;
	return i;
}
void QuickSort(RecType R[], int s, int t) {
	int i;
	if (s < t) {
		i = partition(R, s, t);
		QuickSort(R, s, i - 1);
		QuickSort(R, i + 1, t);
	}
}
//ºÚµ•—°‘Ò≈≈–Ú
void SelectSort(RecType R[], int n) {
	int i, j, k;
	RecType tmp;
	for (i = 0; i < n - 1; i++) {
		k = i;
		for (j = i + 1; j < n; j++)
			if (R[j].key < R[k].key)
				k = j;
		if (k != i) {
			tmp = R[i];
			R[i] = R[k];
			R[k] = tmp;
		}
	}
}
//∂—≈≈–Ú
void sift(RecType R[], int low, int high) {//œÚœ¬…∏—°
	int i = low, j = 2 * i;
	RecType tmp = R[i];
	while (j <= high) {
		if (j < high && R[j].key < R[j + 1].key)
			j++;
		if (tmp.key < R[j].key) {
			R[i] = R[j];
			i = j;
			j = 2 * i;
		}
		else break;
	}
	R[i] = tmp;
}
void HeapSort(RecType R[], int n) {
	int i;
	RecType tmp;
	for (i = n / 2; i >= 1; i--)
		sift(R, i, n);
	for (i = n; i >= 2; i--) {
		tmp = R[1];
		R[1] = R[i];
		R[i] = tmp;
		sift(R, 1, i - 1);
	}
}