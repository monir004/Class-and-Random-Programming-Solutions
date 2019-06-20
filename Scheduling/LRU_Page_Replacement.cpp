#include<bits/stdc++.h>

using namespace std;
int main()
{
	cout << "Enter number of pages ";
	int page; cin >> page;
	cout << "Enter the page number ";
	int arr[20];

	for (int i = 0; i < page; i++)
	{
		int num; cin >> num;
		arr[i] = num;
	}
	cout << "Enter the frame size ";
	int fsize; cin >> fsize;
	int frame[3];
	memset(frame, -1, sizeof(frame));
	int fault = 3, ref = 0, available = 0;
	frame[0] = arr[0];
	frame[1] = arr[1];
	frame[2] = arr[2];
	vector<int>v;
	for (int i = 3; i < page; i++)
	{
		available = 0;
		for (int j = 0; j < fsize; j++)
		{
			if (arr[i] == frame[j]) {
				available = 1;
				break;
			}
		}
		if (available == 0)
		{
			fault++;
			int last,count=0;
			for (int j = i - 1; count!=fsize; j--)
			{
				int found = 0;
				for (int l = 0; l < v.size(); l++)
				{
					if (v[l] == arr[j])
					{
						found = 1;
						break;
					}
				}
				if (found == 0) {
					for (int k = 0; k < fsize; k++)
					{
						if (frame[k] == arr[j])
						{
							v.push_back(arr[j]);
							count++;
							last = arr[j];
							break;
						}
					}
				}
			}
			for (int j = 0; j < fsize; j++)
			{
				if (frame[j] == last)
				{
					frame[j] = arr[i];

				}
			}
			v.clear();
		}
		for (int k = 0; k < fsize; k++)
			cout << frame[k] << "\t";
		if (available == 1) cout << "No fault ";
		cout << endl;
	}
	cout << "Total page fault " << fault << endl;

}
