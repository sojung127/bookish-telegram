#include <cstdio>
#include <queue>
#include <vector>
#define	INF	1e9

using namespace std;
int main() {
	int V, E;
	scanf("%d %d", &V, &E);
	int K;	//���� ������ ��ȣ
	scanf("%d", &K);
	int x,y,w;
	x = y = w = 0;
	vector<vector<pair<int, int>>> edge(V+1);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &x, &y, &w);
		edge[x].push_back({ w,y });	//����׷����̱� ������ mst������ �ٸ��� �ϳ����� �߰�!
	}
	
	vector<int> dist(V + 1,INF);	
	// �� ������ �ִ� ���̰� ����Ǵ� ����. �ʱⰪ�� inf.(���۳��κ��� ���� �� ���� ����� ��� �ʱⰪ�� �����ȴ�.)

	// ���� ������ ����Ǵ� pq. ����ġ�� ���� ������ Ƣ��´�.
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	//���� ��带 pq�� �ִ´�. 
	pq.push(make_pair(0, K));
	dist[K] = 0;

	while (!pq.empty()) {
		// Ž���� ��带 ������. ����ġ�� ���� ������ Ž��.
		int here = pq.top().second;
		pq.pop();

		// Ž�� ����� ���� ������ pq�� ����.
		for (auto w : edge[here]) {
			int next = w.second;
			int nextcost = w.first;
			// Ž�� ��带 ���� ���� ���� ���� ���̰� ���� ����� ���� �������� ���̺��� ª�ٸ� ���̸� �����ϰ� pq�� �߰�
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