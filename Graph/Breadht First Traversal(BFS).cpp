#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void BFS(int s, vector<int>*V,int vertice)
{
	bool *visited = new bool [vertice];    // * visited.. creating a pointer
	for (int i = 0; i < vertice; i++) visited[i] = false; //Never use memset.. For loop is better
	queue<int>q;
	q.push(s);
	visited[s] = true;
	while (!q.empty())
	{
		s = q.front();
		cout << s << "  ";
		q.pop();
		vector<int>::iterator i;
		for (i = V[s].begin(); i!=V[s].end();++i)  //Calling every edges from source
		{
			if (visited[*i] == false)
			{
				visited[*i] = true;
				q.push(*i);
			}
		}
	}
}
int main()
{
	cout << "Enter total number vertice and edge" << endl;
	int vertice, edge;
	cin >> vertice>>edge;
	vector<int>*V = new vector<int>[vertice];
	for (int i = 0; i < edge; i++)
	{
		int x, y; cin >> x >> y;
		V[x].push_back(y);
	}
	BFS(0,V,vertice);  //passing the reference of vector V

	//system("pause"); // To pause the console
}
