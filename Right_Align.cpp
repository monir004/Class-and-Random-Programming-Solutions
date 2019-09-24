#include<iostream>
#include<string>
#include<deque>
#include<sstream>
#include<cstdio>
using namespace std;

int main()
{
	deque<char>temp;
	deque<string>line;
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	getline(cin, str);
	int maximum_character = 60;
	int length_count = 0;
	int length = str.size();

	stringstream iss(str);
	string word;
	cout << endl << endl;
	while (iss >> word)
	{
		word += " ";

		if (length_count + word.length() <= 60)
		{
			line.push_back(word);
			length_count += word.length();
		}
		else
		{
			int space_needed = 60 - length_count;
			for (int i = 0; i < space_needed; i++)
				cout << " ";
			for (deque<string>::iterator it = line.begin(); it != line.end(); it++)
			{
				cout << *it;
			}
			length_count = 0;
			length_count += word.length();
			cout << endl;
			line.clear();
			line.push_back(word);
		}

	}


}

