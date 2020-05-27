#include<iostream>
#include<cstdio>
#include<cstring>
 
#define MAX 101
 
using namespace std;
 
int R, C;
char input[MAX][MAX];
 
int x[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int y[8] = {1, -1, 0, 0, 1, -1, 1, -1};
 
bool visited[MAX][MAX];
char pattern[11] = {'A', 'L', 'L', 'I', 'Z', 'Z', 'W', 'E', 'L', 'L'};
 
bool checkValid(int i, int j){
    if (i >= 0 && i < R && j >= 0 && j < C)
        return true;
 
    return false;
}
 
string dfs(int i, int j, int pattern_index) {
    string s;
    visited[i][j] = 1;
    
    if (pattern_index == 9) {
        return "YES";
    }
    else {
        for (int x_i = 0; x_i < 8; x_i++) {
            if(checkValid(i+x[x_i], j+y[x_i])) {
                if(input[i+x[x_i]][j+y[x_i]] == pattern[pattern_index+1] && !visited[i+x[x_i]][j+y[x_i]]) {
                    visited[i+x[x_i]][j+y[x_i]] = 1;
                    s = dfs(i+x[x_i], j+y[x_i], pattern_index + 1);
                    
                    if (s == "YES") {
                        return s;
                    	// visited[i+x[x_i]][j+y[x_i]] = 0;
                    }
                }
            }
        }
    }
    
    visited[i][j] = 0;
    
    return "NO";
}
 
int main(){
    int t;
    scanf("%d", &t);
    
    while(t--){
        scanf("%d%d", &R, &C);
 
        memset(visited, 0, sizeof(visited));
 
        for(int i=0; i<R; i++){
                scanf("%s", input[i]);
        }
 
        int flag = false;
 
        for( int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(input[i][j] == 'A' && dfs(i, j, 0) == "YES"){
                        flag = true;
                        break;
                }
            }
            
            if(flag) break;
        }
 
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}
