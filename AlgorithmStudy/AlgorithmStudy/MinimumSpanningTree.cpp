/*
����: https://dhpark-ghost.herokuapp.com/2018/06/12/c-peurim-prim-algorijeum/
*/
#include<cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> edge; 
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;	
// pq�� �⺻ ���� <T,Container,Compare> T: �ڷ��� �� Ŭ����, Container:T�� � �ڷᱸ���� ���� ���ΰ�. greater: �����ͺ��� pop�ǵ��� �Ѵ�.
bool visited[10001];
int v, e, c, k;

void prim(int v);

int main() {
	scanf("%d %d", &v, &e);
	edge.resize(v + 1); // ����� ����+1. ����� ��ȣ�� 1���� V���� �Ű����� ����.
	
	int x, y, z;
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &x, &y, &z);
		//edge[i]���� i�� ��忡 ���� ������ ����. {����ġ,������}
		edge[x].push_back({ z,y });
		edge[y].push_back({ z,x });
	}

	prim(1);	// 1�� ������ �����Ͽ� �ּ� ���д� Ʈ���� �����.
	printf("%d", k);	// �ּ� ���д� Ʈ���� ����ġ�� ���

	return 0;
}

void prim(int v) {
	visited[v] = true;	//v�� ���� Ʈ�� ������ ���Ե�.

	for (auto u : edge[v]) {
		if (!visited[u.second]) {	//v�� ��忡 ���� ���������� pq�� �߰�
			pq.push({ u.first,u.second });
		}
	}

	while (!pq.empty()) {
		auto w = pq.top();	// ������ �߰��� ������������ Ž��
		pq.pop();			// pq���� pop�ϹǷ� ������ ����ġ�� ���� �ͺ��� Ž���ϰ� �ȴ�.

		if (!visited[w.second]) {	//������ Ʈ���� ������� �ʾҴٸ� ����.
			k += w.first;	// �߰��� �����̹Ƿ� ���д�Ʈ���� ����ġ�� ����
			prim(w.second);
			return;
		}
	}
}