#include<iostream>
#include<vector>
#include<string>
#include<array>
using namespace std;
int main()
{
	cout << "..........Remember string will be case sensitive ........... " << endl;
	cout << "Enter a string  :";
	string str;
	cin >> str;
	cout << "Enter another string  :";
	string str2;
	cin >> str2;
	int len1 = str.size();
	int len2 = str2.size();
	vector<vector<int>>arr(len2 + 1);// row=len2+1 because of 1 extra row for base case
	for (int i = 0; i <= len2; i++) arr[i].resize(len1 + 1); // Column=len1+1 as column is higher
	for (int i = 0; i <= len2; i++)
	{
		for (int j = 0; j <= len1; j++)
		{
			if (i == 0 || j == 0)
				arr[i][j] = 0; // creating row and columns with zero
			else if (str2[i - 1] == str[j - 1]) // If equal of the two comparing caracters ... i-1 as string starting from 0
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else
				arr[i][j] = (arr[i][j - 1] > arr[i - 1][j] ? arr[i][j - 1] : arr[i - 1][j]);
		}
	}
	cout << "Length of the longest common subsequence is " << arr[len2][len1] << endl;
	vector<char>vc;
	cout << endl << "2d Matrix" << endl << endl;
	for (int i = 0; i <= len2; i++) {
		for (int j = 0; j <= len1; j++) {
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
	while (len2 && len1)
	{
		if (arr[len2][len1] == arr[len2 - 1][len1]) len2--;
		else if (arr[len2][len1] == arr[len2][len1 - 1]) len1--;
		else {
			vc.push_back(str2[len2 - 1]);
			len2--;
			len1--;
		}
	}
	cout << "LCS ELEMENT : ";
	for (vector<char>::reverse_iterator rit = vc.rbegin(); rit != vc.rend(); rit++) {
		cout << *rit << "  ";
	}
	cout << endl << endl;
	//system("pause");
}
