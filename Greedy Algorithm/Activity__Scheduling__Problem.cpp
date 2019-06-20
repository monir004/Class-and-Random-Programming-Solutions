#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct activity
{
	string name;
	int start;
	int end;
};

int total,start_,end_;
string activity_name;
bool comparator(activity a, activity b)
{
	return a.end < b.end;
}
void activitySelection(activity arr[])
{
	sort(arr, arr + total, comparator);
	cout << "Sorted list as per their finishing time........." << endl;
	for (int i = 0; i < total; i++)
	{
		cout << arr[i].name << " = " << arr[i].start << "   " << arr[i].end << endl;
	}
	cout << endl;
	int temp=arr[0].end;
	cout << "Job = " << arr[0].name << "    Starting Point = " << arr[0].start;
	cout << "     Ending point = " << arr[0].end << endl;
	for (int i = 1; i < total; i++)
	{
		if (arr[i].start >= temp)
		{
			cout << "Job = " << arr[i].name << "    Starting Point = " << arr[i].start;
			cout<<"     Ending point = " << arr[i].end << endl;
			temp = arr[i].end; //Assigning end time...
		}
	}
}
int main()
{
	cout << "Enter total number of activity  ";
	cin >> total;
	cout << endl;
	activity arr[100];
	for (int i = 0; i < total; i++)
	{
		cout << "Enter " << i << " no activity name ";
		cin >> activity_name;
		arr[i].name = activity_name;
		cout << "Enter "<<i<< " no activity starting point ";
		cin >> start_;
		arr[i].start = start_;
		cout << "Enter "<<i<< " no activity ending point ";
		cin >> end_;
		arr[i].end = end_;
		cout << endl;
	}
	cout << endl;
	activitySelection(arr);

	system("pause");
}
