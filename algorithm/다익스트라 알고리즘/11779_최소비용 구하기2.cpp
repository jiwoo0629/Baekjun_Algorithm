#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	long long int INF = 1000000000;
	
	int n; //도시 개수
	cin >> n;
	int m; //버스 개수
	cin >> m;

	vector<pair<int, int>>* city = new vector<pair<int, int>>[m]; //도시정보
	long long int* dis = new long long int[n + 1]; //거리
	for (int i = 0; i < n + 1; i++)
		dis[i] = INF;
	int* prev = new int[n + 1]; //최단 거기로 갈 때 이전 도시
	for (int i = 0; i < n + 1; i++)
		prev[i] = 0;
		
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		city[a].push_back(make_pair(b, c));
	}
	int start, finish;
	cin >> start >> finish;

	dis[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));

	while (!pq.empty())
	{
		int current = pq.top().first;
		int distance = pq.top().second;
		pq.pop();

		if (dis[current] < distance)
			continue;

		for (unsigned int i = 0; i < city[current].size(); i++)
		{
			int next = city[current][i].first;
			int nextdistance = distance + city[current][i].second;
			if (nextdistance < dis[next])
			{
				dis[next] = nextdistance;
				prev[next] = current;
				pq.push(make_pair(next, nextdistance));
			}
		}
		
	}
	int count = 1;
	int reverse = finish;
	int* reversepath = new int[n + 1];
	reversepath[0] = finish;
	while (reverse != start)
	{
		reverse = prev[reverse];
		reversepath[count] = reverse;
		count++;
	}
	
	cout << dis[finish] << endl;
	cout << count << endl;
	for (int i = count; i > 0; i--)
		cout << reversepath[i - 1] << " ";

	delete[] reversepath;
	delete[] dis;
	delete[] prev;
	delete[] city;
	return 0;
}
