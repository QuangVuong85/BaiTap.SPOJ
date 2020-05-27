#include <iostream>

using namespace std;

bool isFactorial(int n) {
	int i =2;
	
	while (n > 1) {
		if (n % i != 0) return false;
		n /= i;
		i++;
	}
	
	return true;
}

int main() {
	int k, n;
	
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n;
		
		if (isFactorial(n-1) || isFactorial(n+1)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}

