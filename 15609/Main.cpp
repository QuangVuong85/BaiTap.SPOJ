#include <iostream>
#include <vector>
using namespace std;
 
int m = 10, n = 10;
 
bool sovle(vector<vector<char>> &board, int i, int j, int p, vector<vector<bool>> &visit){
	if (i < 0 || i >= m || j < 0 || j >= n || p < 0 || board[i][j] == '#' ) return false;
	if (board[i][j] == 'x' ) return true;
	if (!visit[i][j]) {
		visit[i][j] = true;
		
		if (sovle(board, i+1, j, (board[i][j]=='s')?p-1:p, visit)) return true;
		if (sovle(board, i, j+1, (board[i][j]=='s')?p-1:p, visit)) return true;
		if (sovle(board, i, j-1, (board[i][j]=='s')?p-1:p, visit)) return true;
		if (sovle(board, i-1, j, (board[i][j]=='s')?p-1:p, visit)) return true;
		
		board[i][j] = '#';
		visit[i][j] = false;
	}
	
	return false;
}
int main() {
	int z;
	int a, b;
	
	cin >> m >> n >> z;
	
	vector<vector<char>> board(m, vector<char>(n,32)); 
	vector<vector<bool>> visit(m, vector<bool>(n,0));
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			
			if(board[i][j] == '@') {
				a = i;
				b = j;
			}			
		}	
	}
	if (sovle( board, a, b, (int) z/2, visit)) {
		cout << "SUCCESS" << endl;
	}
	else {
		cout << "IMPOSSIBLE" << endl;
	}
	
	return 0;
}
