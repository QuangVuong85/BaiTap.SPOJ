#include <iostream>
#include <cmath>

using namespace std;

bool isPerfectSquare(int n) {
	int s = sqrt(n);
	return (s*s == n);
}

bool isFiboPrime(int n) {
	return isPerfectSquare(5*n*n + 4) || 
           isPerfectSquare(5*n*n - 4); 
}

int main() {
	int k, n;
	
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n;
		if (isFiboPrime(n)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}

