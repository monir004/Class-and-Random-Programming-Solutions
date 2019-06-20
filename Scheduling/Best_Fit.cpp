#include<iostream>
#include<string>
using namespace std;
int main()
{
	cout << "Enter procee size ";
	int processSize; cin >> processSize;
	int process[5];
	cout << "Enter all the processes " << endl;
	for (int i = 0; i < processSize; i++)
	{
		int num; cin >> num;
		process[i] = num;
	}
	cout << "Enter block size ";
	int blockSize; cin >> blockSize;
	cout << "Enter all the blocks " << endl;
	int block[5];
	for (int i = 0; i < blockSize; i++)
	{
		int num; cin >> num;
		block[i] = num;
	}
	int external_fragmentation = 0;
	for (int i = 0; i < processSize; i++)
	{
		int temp = 99999,ref=-1;
		for (int j = 0; j < blockSize; j++)
		{
			if (process[i] <= block[j])
			{
				if (block[j] < temp) {
					temp = block[j];
					ref = j;
				}
			}
		}
		if (ref == -1)
		{
			int sum = 0;
			for (int l = 0; l < blockSize; l++) {
				sum += block[l];
			}
			if(sum>=process[i])
			  external_fragmentation += process[i];
		}
		else
		   block[ref] -= process[i];

	}
	for (int i = 0; i < blockSize; i++)
		cout << block[i] << "  ";

	cout << "External fragmentation " << external_fragmentation << endl;

}
