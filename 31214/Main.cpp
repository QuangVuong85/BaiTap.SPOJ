#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int &n) {
	int t = sqrt(n);
	for (int i = 2; i <= t; i++) {
		if (n % i == 0) return false;
	}
	
	return true;
}

int maxPrime(int &n) {
	int t = n;
	while (t >= 2) {
		if (isPrime(t)) return t;
		t--;
	}
	
	return -1;
}

int main() {
	int k, n;
	
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n;
		cout << maxPrime(n) << endl;
	}
	
	return 0;
}
