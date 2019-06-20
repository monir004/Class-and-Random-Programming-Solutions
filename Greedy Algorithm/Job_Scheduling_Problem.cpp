#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct job
{
	char id;
	int dead;
	int profit;
};
bool comparison(job a, job b)
{
	return a.profit > b.profit;
}
void jobSecheduling(job arr[], int n)
{
	sort(arr, arr + n, comparison);
	vector<int>timeSlots(100, -1);
	int filledTimeSlots = 0;
	char joblist[100];
	int dmax = 0;  //String the largest deadline
	int profit = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].dead > dmax)
			dmax = arr[i].dead;
	}
	cout << "Maximum deadline " << dmax << endl;
	//for (int i = 0; i <= dmax; i++)
		//timeSlots[i] = -1;
	//Computing the maximum profit within the deadline
	for (int i = 0; i < n; i++)
	{
		int Min = arr[i].dead;
		while (Min >= 1)
		{
			if (timeSlots[Min] == -1)
			{
				timeSlots[Min] = Min;
				filledTimeSlots++;
				profit += arr[i].profit; //Counting the total profit
				joblist[Min] = arr[i].id; //Keeping the trace of the job id
				break;
			}
			Min--;
		}
		// If all the time slots are filled then stop
		if (filledTimeSlots == dmax)
			break;
	}
	cout << endl << "Total profit " << profit << endl;
	cout << "Required jobs" << endl;
	for (int i = 1; i <= dmax; i++)
	{
		if (timeSlots[i] != -1)
			cout << joblist[i]<< "   ";
	}

}




int main()
{
	job arr[] = { { 'a',2,100 } ,{ 'b',1,19 },{ 'c',2,27 },{ 'd',1,25 },{ 'e',3,15 } };
	int size = sizeof(arr) / sizeof(arr[0]);
	jobSecheduling(arr, size);
	//system("pause");
}
