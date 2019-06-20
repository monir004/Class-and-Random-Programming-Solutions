#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int max(int a, int b)
{
	return (a>b) ? a : b;
}
int knapsack(int *wt, int *val, int item, int n)
{
    int arr[item+1][n+1];

	for (int i = 0; i <= item; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				arr[i][j] = 0;
			else if (wt[i - 1] > j)
				arr[i][j] = arr[i - 1][j];
			else arr[i][j] = max(arr[i - 1][j], val[i - 1] + arr[i - 1][j - wt[i - 1]]);
		}
	}
	for (int i = 0; i <= item; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	int i = item, j = n;
	// Picked knapsack items and corresponding weight printing....
	while (i&&j)
	{
		if (arr[i][j] == arr[i - 1][j]) i--;
		else {
			cout << "Value = " << val[i - 1] << "\tWeight = " << wt[i - 1] << endl;
			j = j - wt[i - 1];
			i--;
		}
	}
	return arr[item][n];
}
int main()
{
	int S, N;
	cout << "Enter total item and capacity : ";
	scanf("%d %d", &N, &S);
	int val[N],wt[N];
	for (int i = 0; i<N; i++)
	{

		//cout << "Enter " << i << " no value and capacity : ";
		scanf("%d %d", &val[i], &wt[i]);
	}
	int n = knapsack(wt, val, N, S);
	printf("%d\n", n);
	/*
	4=Total value,, 13=Capacity
	4 13
    //value and weight
	5 5
	4 6
	7 8
	7 4

	0       0       0       0       0       0       0       0       0       0       0       0       0       0
	0       0       0       0       0       5       5       5       5       5       5       5       5       5
	0       0       0       0       0       5       5       5       5       5       5       9       9       9
	0       0       0       0       0       5       5       5       7       7       7       9       9       12
	0       0       0       0       7       7       7       7       7       12      12      12      14      14

	Value = 7       Weight = 4
	Value = 7       Weight = 8

	Highest weight we can pick = 14
	*/
	return 0;
}

