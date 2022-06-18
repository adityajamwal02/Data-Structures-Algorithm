#include<iostream>
using namespace std;
int max(int a, int b) { return (a > b) ? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
	if (n == 0 || W == 0)
		return 0;
	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);
	else
		return max(
			val[n - 1]
				+ knapSack(W - wt[n - 1],
						wt, val, n - 1),
			knapSack(W, wt, val, n - 1));
}
int main()
{
	int val[] = { 20000,10500,89000,4000,23000 };
	int wt[] = { 10,5, 26,8, 12 };
	int W = 40;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack(W, wt, val, n);
	return 0;
}
