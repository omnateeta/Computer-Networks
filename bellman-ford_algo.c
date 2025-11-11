#include<stdio.h>
#define INF 99999

int i, j, k, u, v;

void printpath(int parent[], int v)
{
	if (parent[v] == -1)
	{
		printf("%d", v);
		return;
	}
	printpath(parent, parent[v]);
	printf("-> %d", v);
}

void bellmanFord(int graph[20][20], int V, int src)
{
	int dist[20], parent[20];

	for (i = 0; i < V; i++)
	{
		dist[i] = INF;
		parent[i] = -1;
	}
	dist[src] = 0;

	// Step 1: Relax edges V-1 times
	for (k = 0; k < V - 1; k++)
	{
		for (u = 0; u < V; u++)
		{
			for (v = 0; v < V; v++)
			{
				if (graph[u][v] != INF && dist[u] + graph[u][v] < dist[v])
				{
					dist[v] = dist[u] + graph[u][v];
					parent[v] = u;
				}
			}
		}
	}

	// Step 2: Check for negative weight cycles
	for (u = 0; u < V; u++)
	{
		for (v = 0; v < V; v++)
		{
			if (graph[u][v] != INF && dist[u] + graph[u][v] < dist[v])
			{
				printf("Graph contains a negative weight cycle!\n");
				return;
			}
		}
	}

	// Step 3: Print the results
	printf("\nVertex\tDistance\tPath\n");
	for (i = 0; i < V; i++)
	{
		if (dist[i] == INF)
		{
			printf("%d -> %d\tINF\t\tNo path\n", src, i);
		}
		else
		{
			printf("%d -> %d\t%d\t\t", src, i, dist[i]);
			printpath(parent, i);
			printf("\n");
		}
	}
}

int main()
{
	int V, src;
	int graph[20][20];

	printf("\nEnter the number of vertices: ");
	scanf("%d", &V);

	printf("\nEnter the adjacency matrix (use 99999 for no edge):\n");
	for (i = 0; i < V; i++)
	{
		for (j = 0; j < V; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}

	printf("\nEnter source vertex: ");
	scanf("%d", &src);

	bellmanFord(graph, V, src);
	return 0;
}

