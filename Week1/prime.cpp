#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
bool isPrime_1(int num) {
	if (num <= 1) return false;
	if (num <= 3) return true;
	if (num % 2 == 0 || num % 3 == 0) return false;
	for (int i = 5; i * i <= num; i += 6) {
		if (num % i == 0 || num % (i + 2) == 0) return false;
	}
	return true;
}
int countPrimes_1(int n)
{cout << "方法一（埃拉托斯特尼筛法）" << endl;
	int count = 0;
	for (int i = 2; i <= n; ++i) {
		if (isPrime_1(i)) ++count;
	}
	int primeCount = count;
	cout << "Number of primes between 1 and " << n << ": " << primeCount << endl;
	return 0;
}
bool isPrime_2(int num)
{
	int tmp = num - 1;
	for (int i = 2; i <= tmp; i++)
		if (num % i == 0)
			return 0;
	return 1;
}

int countPrimes_2(int n)
{	cout << "方法二（定义枚举法）" << endl;
	int count = 0;
	for (int i = 2; i <= n; ++i) {
		if (isPrime_1(i)) ++count;
	}
	int primeCount = count;
	cout << "Number of primes between 1 and " << n << ": " << primeCount << endl;
	return 0;
}
int main()
{
	int n;
	cout << "Enter a number: ";
	cin >> n;
	{
		auto start = chrono::high_resolution_clock::now();
		countPrimes_1(n);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> duration = end - start;
		cout << "Execution time: " << duration.count() << " seconds" << endl;
	}
	{
		auto start = chrono::high_resolution_clock::now();
		countPrimes_2(n);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> duration = end - start;
		cout << "Execution time: " << duration.count() << " seconds" << endl;
	}
	system("pause");
	return 0;
}