#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct srtn {
	int num,at, bt, rt,tat,wt;
}arr[10];
bool comparison(srtn a, srtn b) {
	return a.at < b.at;
}
int main()
{
	int test=9999;
	int  completionTime, i, smallest;
	int remain = 0, n, time, sum_wait = 0, sum_turnaround = 0;

	printf("Enter no of Processes : ");
	std::cin >> n;
	for (i = 0; i<n; i++)
	{
		arr[i].num = i+1;
		printf("Enter arrival time for Process P%d : ", i + 1);
		int a; std::cin >> a;
		arr[i].at=a;
		printf("Enter burst time for Process P%d : ", i + 1);
		int b; std::cin >> b;
		arr[i].bt = b;
		arr[i].rt = arr[i].bt;
	}

	sort(arr, arr + n, comparison);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].at << " " << arr[i].bt << endl;
	}

	arr[9].rt = 9999;
	for (time = 0; remain != n; time++)
	{
		smallest = 9;
		for (i = 0; i<n; i++)
		{
			if (arr[i].at <= time && arr[i].rt<arr[smallest].rt && arr[i].rt>0)
			{
				smallest = i;
			}
		}
		if (test != smallest) {
			//std::cout << time << " p" << smallest + 1 << " ";
			std::cout << time << " p" << arr[smallest].num << " ";
		}
		test = smallest;
		arr[smallest].rt--;
		if (arr[smallest].rt == 0)
		{
			remain++;
			completionTime = time + 1;
			arr[smallest].tat = completionTime - arr[smallest].at;
			arr[smallest].wt = arr[smallest].tat - arr[smallest].bt;
			//printf("\nP[%d]\t|\t%d\t|\t%d", smallest + 1, completionTime - arr[smallest].at, (completionTime - arr[smallest].at) - arr[smallest].bt);
			sum_wait += completionTime - arr[smallest].bt - arr[smallest].at;
			sum_turnaround += completionTime - arr[smallest].at;
		}
	}
	std::cout << time << std::endl;

	printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");
	for (int i = 0; i < n; i++)
	{
		cout << "p" << arr[i].num << "\t" << arr[i].tat << "\t" << arr[i].wt << endl;
	}


	printf("\n\nAverage waiting time = %f\n", sum_wait*1.0 / n);
	printf("Average Turnaround time = %f", sum_turnaround*1.0 / n);
	return 0;
}

