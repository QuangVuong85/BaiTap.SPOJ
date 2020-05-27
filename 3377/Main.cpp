#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

#define MALE 4
#define FEMALE 5

#define COMPLIMENT(X) (X == MALE)?FEMALE:MALE

using namespace std;

int scen, n, inter, a, b, cur_node;
int genders[2005];
bool visited[2005];
bool f;

int main() {
	cin >> scen;
	
	for (int i = 1; i <= scen; i++) {
		cin >> n >> inter;
		vector<int> adj_vector[2005];
		
		for (int j = 0; j < inter; j++) {
			cin >> a >> b;
			
			adj_vector[a].push_back(b);
			adj_vector[b].push_back(a);
		}
		
		memset(visited, 0, sizeof(visited));
		memset(genders, -1, sizeof(genders));
		f = true;
		queue<int> nodes;
		
		// use BFS
		for (int v = 1; v <= n && f; v++) {
			if (visited[v]) continue;
			nodes.push(v);
			genders[v] = MALE;
			
			while (!nodes.empty() && f) {
				cur_node = nodes.front();
				nodes.pop();
				visited[cur_node] = true;
				
				for (vector<int>::iterator it = adj_vector[cur_node].begin(); it != adj_vector[cur_node].end() && f; it++) {
					if (genders[*it] == genders[cur_node]) {
						f = false;
						break;
					}
					else if(!visited[*it] && f) {
						nodes.push(*it);
						genders[*it] = COMPLIMENT(genders[cur_node]);
					}
				}
			}
		}
		
		// check
		if (f) {
			cout << "Scenario #" << i << ":" << endl;
			cout << "No suspicious bugs found!" << endl;
		}
		else {
			cout << "Scenario #" << i << ":" << endl;
			cout << "Suspicious bugs found!" << endl;
		}
	}

	return 0;
}

