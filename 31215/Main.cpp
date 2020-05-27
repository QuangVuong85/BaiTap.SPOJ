#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
	int t = sqrt(n);
	for (int i = 2; i <= t; i++) {
		if (n % i == 0) return false;
	}
	
	return true;
}

int main() {
	int k, n;
	
	cin >> k;
	
	for (int i = 0; i < k; i++) {
		cin >> n;
		
		if (isPrime(n) && isPrime(n+4)) 
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}

	return 0;
}

