#include <cstdio>
#include <queue>
#include <vector>
#define	INF	1e9

using namespace std;
int main() {
	int V, E;
	scanf("%d %d", &V, &E);
	int K;	//시작 정점의 번호
	scanf("%d", &K);
	int x,y,w;
	x = y = w = 0;
	vector<vector<pair<int, int>>> edge(V+1);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &x, &y, &w);
		edge[x].push_back({ w,y });	//방향그래프이기 때문에 mst문제와 다르게 하나에만 추가!
	}
	
	vector<int> dist(V + 1,INF);	
	// 각 노드로의 최단 길이가 저장되는 벡터. 초기값은 inf.(시작노드로부터 닿을 수 없는 노드의 경우 초기값이 유지된다.)

	// 인접 노드들이 저장되는 pq. 가중치가 작은 노드부터 튀어나온다.
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	//시작 노드를 pq에 넣는다. 
	pq.push(make_pair(0, K));
	dist[K] = 0;

	while (!pq.empty()) {
		// 탐색할 노드를 꺼낸다. 가중치가 작은 노드부터 탐색.
		int here = pq.top().second;
		pq.pop();

		// 탐색 노드의 인접 노드들을 pq에 저장.
		for (auto w : edge[here]) {
			int next = w.second;
			int nextcost = w.first;
			// 탐색 노드를 거쳐 현재 노드로 가는 길이가 현재 저장된 현재 노드까지의 길이보다 짧다면 길이를 갱신하고 pq에 추가
			if (dist[next] > dist[here] + nextcost) {
				dist[next] = dist[here] + nextcost;
				pq.push({ dist[next],next });
			}
		}
	}

	for (int k = 1; k < dist.size();k++) {
		int i = dist[k];
		if (i == INF)
			printf("INF\n");
		else
			printf("%d\n", i);
	}


	return 0;
}