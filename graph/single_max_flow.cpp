#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

void print_graph(std::vector< std::vector<int> > graph) {
	std::cout << "G : " << std::endl;
	for(int i = 0; i < graph.size(); i++) {
		for(int j = 0; j < graph.size(); j++) {
			std::cout << graph[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::vector<int> bfs_traversal(std::vector< std::vector<int> > graph, int start) {
	std::vector<bool> visited(graph.size(), false);
	std::vector<int> parents(graph.size(), -1);
	std::queue<int> queue;

	visited[start] = true;
	queue.push(start);
	while(not queue.empty()) {
		int current_node = queue.front();
		queue.pop();

		for(int i = 0; i < graph.size(); i++) {
			if(not visited[i] and graph[current_node][i]) {
				visited[i] = true;
				parents[i] = current_node;
				queue.push(i);
			}
		}
	}

	return parents;
}

void get_path(std::vector<int> & path, std::vector<int> parents, int index) {
	int node = parents[index];
	if(node != -1) {
		get_path(path, parents, node);
	}
	path.push_back(index);
}

int maximum_flow(std::vector< std::vector<int> > cap_graph, int start, int target) {
	std::vector< std::vector<int> > residual_graph = cap_graph;
	std::vector<int> parents;

	while(true) {
		parents = bfs_traversal(residual_graph, start);
		if(parents[target] == -1) {
			int flow = 0;
			for(auto f : residual_graph[target]) flow += f;
			return flow;
		}

		std::vector<int> path;
		get_path(path, parents, target);

		std::vector<int> edges;
		for(int i = 0; i < path.size() - 1; i++) {
			int node0 = path[i];
			int node1 = path[i+1];
			edges.push_back(residual_graph[node0][node1]);
		}
		int min = *std::min_element(edges.begin(), edges.end());

		for(int i = 0; i < path.size()-1; i++) {
			int node0 = path[i];
			int node1 = path[i+1];
			if(residual_graph[node0][node1]) {
				residual_graph[node0][node1] -= min;
			}
			residual_graph[node1][node0] += min;
		}
	}

	return 0;
}

int main() {
	
	std::vector< std::vector<int> > graph1{ {0,3,2,0,0,0}, 
											{0,0,0,0,2,0}, 
											{0,3,0,2,0,0}, 
										    {0,0,0,0,3,2}, 
										    {0,0,1,0,0,2}, 
										    {0,0,0,0,0,0} };

	std::vector< std::vector<int> > graph2{ {0, 16, 13, 0, 0, 0}, 
					                        {0, 0, 10, 12, 0, 0}, 
					                        {0, 4, 0, 0, 14, 0}, 
					                        {0, 0, 9, 0, 0, 20}, 
					                        {0, 0, 0, 7, 0, 4}, 
					                        {0, 0, 0, 0, 0, 0} }; 

	std::vector< std::vector<int> > graph3{ {0, 16, 13, 0,  0,  0,  0, 16, 13, 0,  0,  0 }, 
					                        {0, 0,  10, 12, 0,  0,  0, 0,  10, 12, 0,  0 }, 
					                        {0, 4,  0,  0,  14, 0,  0, 4,  0,  0,  14, 0 }, 
					                        {0, 0,  9,  0,  0,  20, 0, 0,  9,  0,  0,  0 }, 
					                        {0, 0,  0,  7,  0,  4,  0, 19,  0,  7,  0,  0 }, 
					                        {0, 0,  0,  0,  0,  0,  0, 0,  0,  0,  0,  0 },
					                     	{0, 16, 13, 0,  19, 0,  0, 18, 13, 0,  0,  0 }, 
					                        {0, 0,  10, 12, 0,  0,  0, 0,  10, 12, 0,  0 }, 
					                        {0, 4,  0,  0,  17, 0,  0, 4,  0,  0,  14, 0 }, 
					                        {0, 0,  9,  0,  0,  24, 0, 0,  9,  0,  0,  0 }, 
					                        {0, 0,  0,  9,  0,  4,  0, 0,  0,  7,  0,  6 }, 
					                        {0, 0,  0,  0,  0,  0,  0, 0,  0,  0,  0,  0 } }; 


	std::vector< std::vector<int> > graph4{ {0, 5, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
											{0, 0, 0, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
											{0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
											{0, 0, 0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
											{0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
											{0, 0, 0, 5, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0 },
											{0, 0, 0, 0, 0, 7, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0 },
											{0, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0 },
											{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0 },
											{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 3, 0, 0, 0, 0 },
											{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0},
											{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 11, 3, 11, 0}, 
											{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 5, 0 },
											{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7 },
											{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
											{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };





	std::cout << "Maximum Flow Graph1  : " << maximum_flow(graph1, 0, 5) << std::endl;
	std::cout << "Maximum Flow Graph2  : " << maximum_flow(graph2, 0, 5) << std::endl;
	std::cout << "Maximum Flow Graph3  : " << maximum_flow(graph3, 0, 11) << std::endl;
	std::cout << "Maximum Flow Graph4  : " << maximum_flow(graph4, 0, 15) << std::endl;
	
	return 0;
}
