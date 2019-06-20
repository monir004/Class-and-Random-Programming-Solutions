#include <bits/stdc++.h>
using namespace std;

#define size 3
#define BOUNDARY(i,j) ((i>=0 && i<size)&&(j>=0 && j<size))
#define output(n) cout<<n<<" "
#define FOR(i,n) for(int i=0;i<n;i++)
int X[] = { 1, 0, -1, 0 };
int Y[] = { 0, -1, 0, 1 };

struct Node
{
	int arr[size][size];
	int x, y;
	int cost;
	int level;
};

void printMatrix(int mat[][size])
{
	FOR(i,size){
		FOR(j, size)
			output(mat[i][j]);
		cout << endl;
	}
	cout << endl;
}

Node* newNode(int mat[][size], int x, int y, int newX,
	int newY, int level)
{
	Node* node = new Node;
	memcpy(node->arr, mat, sizeof node->arr);
	swap(node->arr[x][y], node->arr[newX][newY]);
	node->cost = 5555;
	node->level = level;
	node->x = newX;
	node->y = newY;
	return node;
}

int calculateCost(int start[][size], int goal[][size])
{
	int count = 0;
	FOR(i,size)
		FOR(j,size)
			if (start[i][j] != 0 && start[i][j] != goal[i][j])
				count++;
	return count;
}

struct comp
{
	bool operator()(const Node* left, const Node* right) const
	{
		return (left->cost + left->level) >(right->cost + right->level);
	}
};

void solve(int start[][size], int x, int y,
	int goal[][size])
{
	priority_queue<Node*, vector<Node*>, comp> pq;
	Node* root = newNode(start, x, y, x, y, 0);
	root->cost = calculateCost(start, goal);
	pq.push(root);
	while (!pq.empty())
	{
		Node* min = pq.top();
		pq.pop();
		if (min->cost == 0) { printMatrix(min->arr); return; }
		printMatrix(min->arr);
		FOR(i, 4)
		{
			if (BOUNDARY(min->x + X[i], min->y + Y[i]))
			{
				Node* child = newNode(min->arr, min->x,
				min->y, min->x + X[i],
				min->y + Y[i],
				min->level + 1);
				child->cost = calculateCost(child->arr, goal);
				pq.push(child);
			}
		}
	}
}
int main()
{
	cout << "Enter the value of row and col ";
	//freopen("input.txt", "r", stdin);
	//freopen("input2.txt", "w", stdout);
	int start[size][size], goal[size][size];
	FOR(i, size)
		FOR(j, size)
	{
		int value; cin >> value;
		start[i][j] = value;
	}
	FOR(i, size)
		FOR(j, size)
	{
		int value; cin >> value;
		goal[i][j] = value;
	}
	cout << "Enter space position " << endl;
	int x, y; cin >> x >> y;

	solve(start, x, y, goal);
	//system("pause");
	return 0;
}


