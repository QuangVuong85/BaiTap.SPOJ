/* bfs */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dist[50005];

int bfs(vector<pair<int,int>> v[], int n) {
	int vis[50005] = {0}, ans, d = 0;
	queue<int> q;
	q.push(n);
	dist[n] = 0;
	
	while (!q.empty()) {
		int m = q.front();
		vis[m] = 1;
		q.pop();
		
		for(int i = 0; i < v[m].size(); i++) {
			int h = v[m][i].first;
			int w = v[m][i].second;
			
			if(!vis[h]) {
				dist[h] = dist[m] + w;
				q.push(h);
			}
					
		}
		
		if (d < dist[m]) {
			d = dist[m];
			ans = m;
		}
	}
	
	return ans;
}

int main() {
	int t, n, a, b, c;
	cin >> t;
	
	while (t--) {
		cin >> n;
		
		vector<pair<int,int>> v[n+9];
		
		for (int i = 0; i < n-1; i++) {
			cin >> a >> b >> c;
			
			v[a].push_back(make_pair(b, c));
			v[b].push_back(make_pair(a, c));
		}
		
		int start =  bfs(v,1);
		int end = bfs(v,start);
		
		cout << dist[end] << endl;	
	}
	
	return 0;
}
