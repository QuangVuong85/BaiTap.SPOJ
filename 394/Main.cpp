#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	string s;
	int arr[5001];
	
	while (cin >> s) {
		if (s.compare("0") == 0) break;
		
		s = "0" + s;
		memset(arr, 0, sizeof(arr)); // set n bytes of arr start pos = 0 is value = 0
		arr[s.size()] = 1;
		
		for (int i = s.size()-1; i >= 1; i--) {
			if (s[i]-'0' >= 1) {
				arr[i] += arr[i+1];
			}
			
			if (((s[i]-'0')*10 + s[i+1]-'0' <= 26)
				&& ((s[i]-'0')*10 + s[i+1]-'0' > 9)) {
				arr[i] += arr[i+2];	
			}
		}
		
		cout << arr[1] << endl;
	}

	return 0;
}

