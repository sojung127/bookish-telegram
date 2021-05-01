/*
참고: https://dhpark-ghost.herokuapp.com/2018/06/12/c-peurim-prim-algorijeum/
*/
#include<cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> edge; 
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;	
// pq의 기본 형태 <T,Container,Compare> T: 자료형 및 클래스, Container:T를 어떤 자료구조에 담을 것인가. greater: 작은것부터 pop되도록 한다.
bool visited[10001];
int v, e, c, k;

void prim(int v);

int main() {
	scanf("%d %d", &v, &e);
	edge.resize(v + 1); // 노드의 갯수+1. 노드의 번호가 1부터 V까지 매겨지기 때문.
	
	int x, y, z;
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &x, &y, &z);
		//edge[i]에는 i번 노드에 대한 정보가 들어간다. {가중치,연결노드}
		edge[x].push_back({ z,y });
		edge[y].push_back({ z,x });
	}

	prim(1);	// 1번 노드부터 시작하여 최소 스패닝 트리를 만든다.
	printf("%d", k);	// 최소 스패닝 트리의 가중치를 출력

	return 0;
}

void prim(int v) {
	visited[v] = true;	//v번 노드는 트리 정점에 포함됨.

	for (auto u : edge[v]) {
		if (!visited[u.second]) {	//v번 노드에 대한 인접정점을 pq에 추가
			pq.push({ u.first,u.second });
		}
	}

	while (!pq.empty()) {
		auto w = pq.top();	// 위에서 추가된 인접정점들을 탐색
		pq.pop();			// pq에서 pop하므로 엣지의 가중치가 작은 것부터 탐색하게 된다.

		if (!visited[w.second]) {	//정점이 트리와 연결되지 않았다면 연결.
			k += w.first;	// 추가된 엣지이므로 스패닝트리의 가중치에 합함
			prim(w.second);
			return;
		}
	}
}