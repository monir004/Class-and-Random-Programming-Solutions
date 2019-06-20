#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout << "Enter number of pages ";
	int page; cin >> page;
	cout << "Enter the page number ";
	int arr[20];

	for (int i = 0; i < 20; i++)
	{
		int num; cin >> num;
		arr[i] = num;
	}
	cout << "Enter the frame size ";
	int fsize; cin >> fsize;
	int frame[3];
	memset(frame, -1, sizeof(frame));
	int fault = 0, ref = 0, available = 0;
	for (int i = 0; i < 20; i++)
	{
		available=0;
		for (int j = 0; j < fsize; j++)
		{
			if (arr[i] == frame[j]) {
				available = 1;
				break;
			}
		}
		if (available == 0)
		{
			frame[ref++] = arr[i];
			if (ref == 3) ref = 0;
			fault++;

		}
		for (int k = 0; k < fsize; k++)
			cout << frame[k] << "\t";
		if (available == 1) cout << "No fault";
		cout << endl;
	}
	cout << "Total page fault " << fault << endl;

}
