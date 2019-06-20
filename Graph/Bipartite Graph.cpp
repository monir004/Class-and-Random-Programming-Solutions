#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool bipartite(int s, vector<int>*v,int length)
{
	queue<int>q;
	bool *visited = new bool[length];
	for (int i = 0; i < length; i++) visited[i] = false;
	string *color = new string[1000];
	q.push(s); visited[s] = true; color[s] = "red";
	while (!q.empty())
	{
		int pf = q.front();   //pf= pop front
		q.pop();
		vector<int>::iterator i;
		for (i = v[pf].begin(); i != v[pf].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				//I am coloring all of the neibhours with two different colors.If red then bule vice versa
				//Again i am coloring all of the neighbours neighbour color with different.
				//Only two set suppose set V1={some elements} and set v2={some elements}
				//DAG=Directed asyclic graph.The graph also could be a cycle with even number of elemnts.
				q.push(*i);
				if (color[pf] == "red") color[*i] = "blue";  //marking the adjacent vertix with different color
				else color[*i] = "red";  //Marking the agjacent vetrix with different color
			}
			else if (color[pf] == color[*i]) return false; // No need visit or non visit check..
			//because if visited then it will automatically come in else if block
			// I just need to check whether it's connected vertice is colored with same color or not
			//If it is colored with same color that means the graph at least is not bipartite graph
		}
	}
	//If here the programe comes that means all of the color of neighbour vertices is different.
	//and the graph is bipartite grapg... return true

	return true;
}
int main()
{
	cout << "Enter number of vertices and edges" << endl;
	int vertice, edge;
	cin >> vertice >> edge;
	vector<int>* V = new vector<int>[vertice];  //This type of decaration is very good.....
	for (int i = 0; i < edge; i++)
	{
		int x, y; cin >> x >> y;   // Not directive grpah
		V[x].push_back(y);
		V[y].push_back(x);
	}
	bool ans = bipartite(0, V, vertice);
	if (ans) cout << "The graph is bipartite graph" << endl;
	else cout << "Not!!!!!!!!!!!!!!!!!!!!!!!" << endl;

	//system("pause");
}
//8 10
//0 4
//0 5
//0 7
//1 4
//1 5
//1 6
//2 6
//2 7
//3 6
//3 4
// Bipartite
