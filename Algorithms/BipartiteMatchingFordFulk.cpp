#include <iostream>
#include <vector>

// Uses a version of the Ford-Fulkerson method optimized for bipartite matching.
bool bipartite_matching_dfs(const vector<vector<int>>& graph, int u, vector<bool>& visited, vector<int>& match)
{
	for (int v : graph[u])
	{
		if (!visited[v])
		{
			visited[v] = true;
			if (match[v] < 0 || bipartite_matching_dfs(graph, match[v], visited, match))
			{
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}

// Computes a maximum bipartite matching and returns its size (the number of matches).
// graph: A vector of vectors of ints. The Kth vector indicates the indices of right-side nodes to which the Kth left-side node has an edge. Nodes are 0-indexed.
// m: The size of the left-side set of nodes.
// n: The size of the right-side set of nodes.
int bipartite_matching(const vector<vector<int>>& graph, int m, int n)
{
	int matchings = 0;
	vector<int> match(n, -1);
	for (int u = 0; u < m; u++)
	{
		vector<bool> visited(n, false);
		matchings += bipartite_matching_dfs(graph, u, visited, match);
	}
	return matchings;
}
