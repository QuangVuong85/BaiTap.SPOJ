#include <bits/stdc++.h>

#define mem(a, b) memset(a, b, sizeof(a))

using namespace std;

typedef long long ll;

ll power(ll a, ll n) {
    if (n == 0) {
      return 1;
    }
    
    ll p = power(a, n / 2);
    p *= p;
    
    if (n & 1) {
      p = p * a;
    }
    
    return p;
}

ll gcd(ll a, ll b) {
    if (b) {
      return gcd(b, a % b);
    }
    
    return a;
}

int n, dp[35][35], ar[35];

int solve1(int i, int j) {

    if (i >= j) 
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int a1 = ar[i] + max(solve1(i + 2, j), solve1(i + 1, j - 1));
    int a2 = ar[j] + max(solve1(i, j - 2), solve1(i + 1, j - 1));
    return dp[i][j] = max(a1, a2);
}

int solve2(int i, int j) {

    if (i >= j) 
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int a1 = ar[i] + min(solve2(i + 2, j), solve2(i + 1, j - 1));
    int a2 = ar[j] + min(solve2(i, j - 2), solve2(i + 1, j - 1));
    return dp[i][j] = max(a1, a2);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> ar[i];
        }

        mem(dp, -1);
        int dumb  = solve1(0, n - 1);
        mem(dp, -1);
        int smart = solve2(0, n - 1);

        cout << dumb << " " << smart << "\n";         
    }
    
    return 0;
}
