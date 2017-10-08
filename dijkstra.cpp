#include <vector>
#include <queue>
#include <limits.h>
#include <iostream>

#define INFINITY INT_MAX

std::vector<unsigned int> dijkstra(const std::vector<std::vector<std::pair< unsigned int, unsigned int >>>& adj_list, 
									const unsigned int init_node){
	std::vector<unsigned int> dist(adj_list.size(), INFINITY);
	std::vector<bool> visited(adj_list.size(), false);
	std::queue<unsigned int> q;
	q.push(init_node);
	dist[init_node] = 0;
	unsigned int node;
	while(!q.empty()){
		node = q.front(); q.pop();
		visited[node] = true;
		for(auto neighbour : adj_list[node]){
			if(!visited[neighbour.second])
				q.push(neighbour.second);
			if(dist[node] + neighbour.first < dist[neighbour.second])
				dist[neighbour.second] = dist[node] + neighbour.first;
		}
	}
	return dist;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	std::vector<std::vector<std::pair< unsigned int, unsigned int>>> adj_list(n);
	unsigned int first, weight, second;
	for(int i = 0 ; i < m ; ++i){
		scanf("%d %d %d",&first, &weight, &second);
		adj_list[first].push_back(std::make_pair(weight, second));
		adj_list[second].push_back(std::make_pair(weight, first));
	}
	std::vector<unsigned int> dist = dijkstra(adj_list, 2);
	for(auto it : dist)
		std::cout << it << " ";
}