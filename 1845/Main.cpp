#include <iostream>

using namespace std;

const int MAX_INT = 1 << 20; // a << b = a*2^b
const int MAX = 105;

int N, M, E, T;
int Matrix[MAX][MAX];
int Mark[MAX], Value[MAX];

int findIdMinValue() {
	int idm = 0, _min = MAX_INT;
	for(int i = 1; i <= N; i++)
		if(Mark[i] == 0 && Value[i] < _min) {
			_min = Value[i];
			idm  = i;
		}
		
	return idm;
}

void dijkstra(int start) {
	int cnt = 0;
	
	for(int i = 1; i <= N; i++) {
		Mark[i] = 0;
		Value[i] = MAX_INT;
	}

	Value[start] = 0;
	
	while(cnt < N) {
		int idmin = findIdMinValue();
		Mark[idmin] = 1;
		cnt++;
		
		for(int i = 1; i <= N; i++)
			if(Mark[i] == 0 && Matrix[idmin][i] > 0 && 
				Value[idmin] + Matrix[idmin][i] < Value[i])
				Value[i] = Value[idmin] + Matrix[idmin][i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> E >> T >> M;
	
	for (int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			Matrix[i][j] = 0;
		
	int a, b, t;
	for(int i = 0; i < M; i++) {
		cin >> a >> b >> t;
		Matrix[b][a] = t;
	}

	// implementing code
	dijkstra(E);


	int Answer = 0;
	for(int i = 1; i <= N; i++)
		if(Value[i] <= T) Answer++;

	// output
	cout << Answer << endl;
	
	return 0;
}
