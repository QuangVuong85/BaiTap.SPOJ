#include <iostream>

using namespace std;

const int MAX = 200005;
long long result;
int arr[MAX];

void merge(int *a, int left, int m, int right) {
	int *temp = new int[right - left + 1];
	int k = 0, i = left, j = m + 1;
	
	while (i <= m && j <= right) {
		if (a[i] > a[j]) {
			temp[k++] = a[i++];
			result += right - j + 1;
		}
		else {
			temp[k++] = a[j++];
		}
	}

	while (i <= m) temp[k++] = a[i++];
	while (j <= right) temp[k++] = a[j++];
	
	for (int i = 0; i < k; i++) {
		a[i + left] = temp[i];
	}
	
	delete[] temp;
}

void mergeSort(int *a, int left, int right) {
	int m;
	if (left < right) {
		m = (left + right) / 2;
		
		mergeSort(a, left, m);
		mergeSort(a, m + 1, right);
		merge(a, left, m, right);
	}
}

int main() {
	int k, n;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		result = 0;
		cin >> k;
		
		for (int j = 0; j < k; j++) {
			cin >> arr[j];
		}
		
		mergeSort(arr, 0, k-1);
		
		cout << result << endl;
	}

	return 0;
}

