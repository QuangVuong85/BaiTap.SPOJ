#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int inp() {
	int x = 0;
	char c;
	do {
		c = getchar();
	} while (c<=32);
	
	do {
		x = (x<<1) + (x<<3) + c - '0';
		c = getchar();
	} while (c > 32);
	
	return x;
}

int main() {
	int t;
//	cin >> t;
	t = inp();
	
	while (t--) {
		int h, m;
//		cin >> h >> m;
		h = inp();
		m = inp();
		
		int arr[h+9][m+9];
		for (int i = 0; i < h; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = inp();
				
		int ma = -1;
		for (int i = 0; i < m; i++)
			ma = max(ma, arr[0][i]);
			
		for (int i = 1; i < h; i++) {
			ma = -1;
			
			for (int j = 0; j < m; j++) {
				if(j > 0 && j < m - 1)
                    arr[i][j] = max(arr[i-1][j] + arr[i][j], max(arr[i-1][j-1]+arr[i][j], arr[i-1][j+1]+arr[i][j]));
                else if(j > 0)
                    arr[i][j] = max(arr[i-1][j]+arr[i][j], arr[i-1][j-1]+arr[i][j]);
                else if(j < m - 1)
                    arr[i][j] = max(arr[i-1][j]+arr[i][j], arr[i-1][j+1]+arr[i][j]);
                ma = max(arr[i][j] , ma);
			}
		}
//		cout << ma << endl;
		printf("%d\n", ma);
	}
	
	return 0;
}

