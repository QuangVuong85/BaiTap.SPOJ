#include <iostream>

typedef long long ll;

using namespace std;

int main() {
	
	int n, m, max = 0;
	
	cin >> n >> m;
	int *h = new int[n];
	
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		if (h[i] > max) max = h[i];
	}

	
	ll hi = max - 1;
	ll lo = 0;
	ll mid, res;
	
	while (hi > lo) {
		mid = (hi + lo + 1) / 2;
		res = 0;
		
		for (int i = 0; i < n; i++) {
			int temp = h[i] - mid;
			
			if (temp > 0) res += temp;
			if (res > 2000000000) break;
		}
		
		if (res >= m) lo = mid;
		else hi = mid - 1;
	}
	
	cout << hi << endl;

	return 0;
}

