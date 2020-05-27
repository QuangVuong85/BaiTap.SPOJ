#include <iostream>

using namespace std;

int countMissing(char c[], int n) {
	int stack_count = 0;
	int count = 0;
	
	for (int i = 0; i < n; i++) {
		if (c[i] == '{') 
			stack_count++;
		else{
			if (stack_count > 0) 
				stack_count--;
			else 
				count++;
		}
	}
	
	return count / 2 + count % 2 + stack_count / 2 + count % 2;
}

int main() {
	int k = 1, n;
	char c[2002];
	
	while (true) {
		cin >> c;
		if (c[0] != '{' && c[0] != '}' && c[0] == '-')
			break;
		n = 0;
		while (c[n] != '\0')
			n++;
		cout << k << ". " << countMissing(c, n) << endl;
		k++;
	}

	return 0;
}

