#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
int calculate1(int x)
{

	if (x >= 0)
	{
		int s = 0;
		for (int i = 0; i <= x; i++)
			s = s + i;
		cout <<"方法一（累加法）"<<endl<<"1+2+3+......+n=" << s<<endl;
	}
	else
	{
		cout << "Data Error!";
	}

	return 0;
	
}
int calculate2(int x)
{
	if (x >= 0)
	{
		int s = x*(x + 1) / 2;
		cout << "方法二（高斯法）" << endl << "1+2+3+......+n=" << s<<endl;
	}
	else
	{
		cout << "Data Error!";
	}
	
	return 0;
}
int main()
{
	int n;
	cout << "Please Enter the Value of n : ";
	cin >>  n;
	{auto start = chrono::high_resolution_clock::now();
	calculate1(n);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> duration = end - start;
	cout << "Execution time: " << duration.count() << " seconds" << endl; }
	{auto start = chrono::high_resolution_clock::now();
	calculate2(n);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> duration = end - start;
	cout << "Execution time: " << duration.count() << " seconds" << endl; }
	system("pause");
	return 0;
}