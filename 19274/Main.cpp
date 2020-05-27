/* 
- Dung thuat toan tham lam
+ Tao 1 mang luu dau truoc moi so (mac dinh la true +)
+ Tinh tong cua mang neu bang s thi break
+ Duyet tu n -> 1: thu dat dau - vao truoc so i va giam di 2i (ban dau deu la +)
*/

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

bool pos[600]; // array luu dau truoc moi so

int main() {
    memset(pos, true, sizeof(pos));
    int n, s;
    cin >> n >> s;
    int ans = n*(n+1)/2;

    if (abs(ans-s)%2 == 1 || s > ans || s < -ans+2) {
        cout << "Impossible" << endl;
        return 0;
    } 
	else {
        for (int i = n; i >= 1; i--) {
            if (ans-2*i >= s) {
                pos[i] = false;
                ans -= 2*i;
            }
        }
        
        if (!pos[1]) { // truoc so 1 khong duoc la dau - -> pos[1] = 1
            bool check = false;
            
            for (int i = 3; i <= n; i++) {
                if (!pos[i-1] && pos[i]) {
                    pos[i] = false;
                    pos[i-1] = true;
                    check = true;
                    break;
                }
            }
            
            if (!check) {
                int j = 4;
                while (pos[j]) j++;
                pos[2] = false;
                pos[j] = true;
                pos[j-1] = false;
            }
        }
        
        cout << "1";
        
        for (int i = 2; i <= n; i++) {
            if (pos[i]) cout << "+";	// true
			else cout << "-";	// false
            cout << i;
        }
        cout << endl;
    }
    
    return 0;
}
