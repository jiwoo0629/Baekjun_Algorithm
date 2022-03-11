#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	int INF = 1000000;
	int v, e; //v:정점, e:간선
	cin >> v >> e;
	vector<pair<int, int>>* a = new vector<pair<int, int>>[e]; //arrived
	int* d = new int[e]; //최소 distance
	for (int i = 0; i < e; i++)
		d[i] = INF;

	int k; //k:시작 정점
	cin >> k;
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[u].push_back(make_pair(v, w));
	}

	//다익스트라 알고리즘
	d[k] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(k, 0));

	while (!pq.empty())
	{
		int cur = pq.top().first;
		int dis = pq.top().second;
		pq.pop();

		if (d[cur] < dis) continue;

		for (int i = 0; i < a[cur].size(); i++)
		{
			int next = a[cur][i].first;
			int nextdis = dis + a[cur][i].second;

			if (nextdis < d[next])
			{
				d[next] = nextdis;
				pq.push(make_pair(next, nextdis));
			}
		}
	}
	
	for (int i = 0; i < v; i++)
	{
		if (d[i+1] == INF)
			cout << "INF" << endl;
		else
			cout << d[i+1] << endl;
	}

	return 0;
}

void dijkstra(int start)
{
	
}
