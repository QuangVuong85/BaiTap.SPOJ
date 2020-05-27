#include <iostream>
#include <cstring>
#include <cstdio>
#include <climits>

using namespace std;

#define MAX 1009

int a[MAX][MAX];
int p, n, m;

int minkey(int visited[], int cost[]) {
	int mini = INT_MAX, index;
	
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0 && cost[i] < mini) {
			mini = cost[i];
			index = i;
		}
	}
	
	return index;
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		memset(a, 0, sizeof(a));
		cin >> p >> n >> m;
		
		for (int i = 0; i < m; i++) {
			int s, e, l;
			cin >> s >> e >> l;
			
			a[s][e] = l*p;
			a[e][s] = l*p;
		}
		
		int cost[n+1], visited[n+1];
		
		for (int i = 1; i <= n; i++) {
			visited[i] = 0;
			cost[i] = INT_MAX;
		}
		
		cost[1] = 0;
		
		for (int i = 1; i <= n; i++) {
			int u = minkey(visited, cost);
			visited[u] = 1;
			
			for (int i = 1; i <= n; i++) {
				if (a[u][i] && visited[i] == 0 && a[u][i] < cost[i]) {
					cost[i] = a[u][i];
				}
			} 
		}
		
		int result = 0;
		
		for (int i = 1; i <= n; i++) {
			result += cost[i];
		}
		
		cout << result << endl;
	}

	return 0;
}

