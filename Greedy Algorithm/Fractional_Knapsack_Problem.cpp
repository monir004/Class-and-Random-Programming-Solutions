#include<iostream>
#include<algorithm>
using namespace std;
struct knapsack
{
	int weight;
	int price;
	double ratio;
};
bool comparison(knapsack a, knapsack b)
{
	return a.ratio > b.ratio;
}
void knapsack_print(knapsack arr[], int n)
{
	sort(arr, arr + n, comparison); //Sorting by ratios....
	cout << "Enter knapsack size ";
	int ca; cin >> ca;
	double total_profit = 0;
	for (int i = 0; i < n; i++)
	{

		if (arr[i].weight <= ca)
		{
			ca -= arr[i].weight;
			total_profit += arr[i].price;
		}
		else {
			total_profit += (arr[i].ratio*ca);
			break;
		}
	}
	cout << "Total price earned by the thief " << total_profit << endl;

}
int main()
{
	knapsack arr[10];
	cout << "Enter how many elements " << endl;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter " << i << " no weight ";
		double Weight;
		cin >> Weight;
		arr[i].weight = Weight;

		cout << "Enter " << i << " no price ";
		double Price;
		cin >> Price;
		arr[i].price = Price;

		arr[i].ratio = (Price / Weight); //Ratio determining...
	}
	knapsack_print(arr, n);
	//system("pause");
}
