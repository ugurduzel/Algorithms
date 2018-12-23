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

int super_maximum_flow(std::vector< std::vector<int> > cap_graph, std::vector<int> start, std::vector<int> target) {
	std::vector< std::vector<int> > temp = cap_graph;
	int size = temp.size();
	for(int i = 0; i < size; i++) {
		temp[i].push_back(0);
		bool pushed = false;
		for(auto t : target) {
			if(t==i) {
				temp[i].push_back(INT_MAX);
				pushed = true;
				break;
			}
		}
		if(pushed == false) {
			temp[i].push_back(0);
		}
	}


	std::vector<int>  super_start(temp.size()+2,0);
	std::vector<int>  super_target(temp.size()+2,0);
	for(auto node : start) {
		super_start[node] = INT_MAX;
	}

	temp.push_back(super_start);
	temp.push_back(super_target);

	return maximum_flow(temp, cap_graph.size(), cap_graph.size()+1);
}

int limited_super_maximum_flow(std::vector< std::vector<int> > cap_graph, std::vector< std::pair<int,int> > start, std::vector< std::pair<int,int> > target) {
	std::vector< std::vector<int> > temp = cap_graph;
	int size = temp.size();
	for(int i = 0; i < size; i++) {
		temp[i].push_back(0);
		bool pushed = false;
		for(auto t : target) {
			if(t.first==i) {
				temp[i].push_back(t.second);
				pushed = true;
				break;
			}
		}
		if(pushed == false) {
			temp[i].push_back(0);
		}
	}


	std::vector<int>  super_start(temp.size()+2,0);
	std::vector<int>  super_target(temp.size()+2,0);
	for(auto node : start) {
		super_start[node.first] = node.second;
	}

	temp.push_back(super_start);
	temp.push_back(super_target);

	print_graph(temp);

	return maximum_flow(temp, cap_graph.size(), cap_graph.size()+1);
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

	std::vector< std::vector<int> > graph5{ {0,0,0,4,2,0,0,0,0},
											{0,0,0,0,5,0,0,0,0},
											{0,0,0,0,3,4,0,0,0},
											{0,0,0,0,0,0,3,1,0},
											{0,0,0,0,0,0,0,3,5},
											{0,0,0,0,0,0,0,0,3},
											{0,0,0,0,0,0,0,0,0},
											{0,0,0,0,0,0,0,0,0},
											{0,0,0,0,0,0,0,0,0} };
	
	std::vector<int> start{0,1,2};
	std::vector<int> target{6,7,8};
	
	std::cout << "Super Max Flow : " << super_maximum_flow(graph5, start, target) << std::endl;

	std::vector< std::pair<int,int> > start_pair;
	std::pair<int,int> t0(0,INT_MAX);
	std::pair<int,int> t1(1,INT_MAX);
	std::pair<int,int> t2(2,5);
	start_pair.push_back(t0);
	start_pair.push_back(t1);
	start_pair.push_back(t2);
	std::vector< std::pair<int,int> > target_pair;
	std::pair<int,int> t3(6,INT_MAX);
	std::pair<int,int> t4(7,INT_MAX);
	std::pair<int,int> t5(8,8);
	target_pair.push_back(t3);
	target_pair.push_back(t4);
	target_pair.push_back(t5);

	std::cout << "Super Max Flow : " << limited_super_maximum_flow(graph5, start_pair, target_pair) << std::endl;
	return 0;
}
