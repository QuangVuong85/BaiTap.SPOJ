#include <iostream>
#include <algorithm>

using namespace std;

class node {
	public:
  		int start,end;
};

node A[100000];

bool cmp(node a, node b) {
  return a.end < b.end;
}

int main() {
  int t, n, i, j, k;
  cin >> t;
  
	while (t--) {
	    cin >> n;
	    
	    for (i = 0; i < n; i++) {
	      cin >> A[i].start;
	      cin >> A[i].end;
	    }
	    
	    sort(A, A+n, cmp);
	    j = 1;
	    k = A[0].end;
	    
	    for (i = 1; i < n; i++) {
	    	if( A[i].start >= k){
				j++;
				k = A[i].end;
	    	}
	    }
	    
	    cout<<j<<endl;
  	}
  
	return 0;
}
