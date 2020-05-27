/* 
	1 do thi la cay khi co so dinh = so canh + 1, lien thong va khong co chu trinh.
*/

#include <iostream>
#include <stack>
#include <cstdio>
#include <vector>

using namespace std;

int n, m;
int ko;
vector<int> v[10001];

int dfs() {
	int i, j, k;
	stack<int> s;
	bool visit[10010];
	
	for (i = 0; i < n; i++) {
		visit[i] = 0;
	}
	
	s.push(1);
	ko = 0;
	
	while (s.size() > 0) {
		ko++;
		j = s.top();
		s.pop();
		
		if (visit[j] == true) {
			return 0;
		}
		
		visit[j] = true;
		
		for (i = 0; i < v[j].size(); i++) {
			s.push(v[j][i]);
		}
	}
	
	if (ko == n) return 1;
	else return 0;
}

int main() {
	int i, j, k, io, ko;
	cin >> n >> m;
	
	for (i = 0; i < m; i++) {
		cin >> j >> k;
		v[j].push_back(k);
	}
	
	k = dfs();
	
	if ((k == 1) && (m + 1 == n)) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;

	return 0;
}

