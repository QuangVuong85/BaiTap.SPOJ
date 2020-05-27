#include <iostream>

using namespace std;

typedef int ll;

int count;

void air(ll x, ll y);
void water(ll x, ll y);
void fire(ll x, ll y);

void air(ll x, ll y) {
	ll h, a;
	count++;
	
	h = x + 3;
	a = y + 2;
	
	if (h - 5 > 0 && a - 10 > 0) water(h, a);
	else if (h - 20 > 0) fire(h, a);
}

void water(ll x, ll y) {
	ll h, a;
	count ++;
	
	h = x - 5;
	a = y - 10;
	
	air(h, a);
}

void fire(ll x, ll y) {
	ll h, a;
	count++;
	
	h = x - 20;
	a = y + 5;
	
	air(h, a);
}

int main() {
	ll t, H, A;
	cin >> t;
	
	while (t--) {
		count = 0;
		cin >> H >> A;
		
		air(H, A);
		cout << count << endl;
	}
	
	return 0;
}

