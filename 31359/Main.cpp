#include <iostream>

using namespace std;

int SLPLN(int n) {
	int i = 1;
	int j;
	
	while (0 == 0) {
		j = i + 1;
		if (j * j * j > n) break;
		i = j;
	}
	
	return i;
}

int main() {
	int k, n;
	
	cin >> k;
	
	for (int i = 0; i < k; i++) {
		cin >> n;
		cout << SLPLN(n) << endl;
	}
	

	return 0;
}

