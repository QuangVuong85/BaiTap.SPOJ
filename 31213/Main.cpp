#include <iostream>

using namespace std;

int Max(int list[], int n, int maxWeight) {
    int choose[] = { 0, 1, 2 };
    int Current = 2;
    int Max = 0, Max2;
    
    while (true) {
        Max2 = list[choose[0]] + list[choose[1]] + list[choose[2]];
        
        if (Max2 <= maxWeight && Max < Max2)
            Max = Max2;
            
        while ((++choose[Current]) == n - 2 + Current) {
            Current--;
            
            if (Current == -1)
                return Max;
        }
        
        for (int i = Current; i < 2; i++)
            choose[i + 1] = choose[i] + 1;
        Current = 2;
    }
}

int main() {
    int maxWeight;
    int list[20];
    int n, k;
    cin >> k;
    
    for (int i = 0; i < k; i++) {
        cin >> n;
        
        for (int j = 0; j < n; j++)
            cin >> list[j];
            
        cin >> maxWeight;
        
        cout << Max(list, n, maxWeight) << endl;
    }
    
    return 0;
}
