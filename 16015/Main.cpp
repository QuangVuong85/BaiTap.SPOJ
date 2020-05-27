#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 1001;
int arr[MAX];
int high_index[100005];
int finalpos[MAX];


int main() {
	int k, n;
	
	cin >> n;
	
	while (n--) {
		cin >> k;
		
		int i, j;
		
		// resert value array
		memset(finalpos, 0, sizeof(finalpos));
		
		for (i = 0; i < k; i++) cin >> arr[i];
		for (i = 0; i < k; i++) cin >> high_index[arr[i]];
		
		sort(arr, arr+k);
		
		for (i = 0; i < k ; i++) {
			int count = high_index[arr[i]];
			
			// search pos
			for (j = 0; j < k; j++) {
				// count == 0 put
				if (count == 0 && finalpos[j] == 0) {
					finalpos[j] = arr[i];
					break;
				}
				
				if (finalpos[j] == 0) count--;
			}
		}
		
		for (i = 0; i < k; i++) cout << finalpos[i] << " ";
		cout << endl;
	}

	return 0;
}

