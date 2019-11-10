#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
private:
	int V; // number of nodes
	list<int>* adj; //a list containing all the adjacent nodes to the given one
public:
	Graph(int V); // constructor
	void addEdge(int v, int link); //add a connection from node v to node link
	void BFS(int start); //bfs from starting node start

};

Graph::Graph(int V) {
	this->V = V; 
	adj = new list<int>[V]; //we create an array of lists for every edge in the graph
}

void Graph::addEdge(int v, int link) {
	adj[v].push_back(link); //we add link to the list of adjacent nodes to v
}

void Graph::BFS(int start) {

	//we create an array of the visited nodes of the graph
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = 0;
	}

	//we create a queue to store the nodes
	queue<int> queue;

	//we mark the starting node as visited and add it into the queue
	visited[start] = 1;
	queue.push(start);

	//we create an iterator i to traverse through the list of adjacent nodes
	list<int>::iterator i;

	while (!queue.empty()) {
		//we print the current node and remove it from the queue
		start = queue.front();
		cout << start << " ";
		queue.pop();

		for (i = adj[start].begin(); i != adj[start].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = 1;
				queue.push(*i);
			}
		}
	}
}

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);
}
