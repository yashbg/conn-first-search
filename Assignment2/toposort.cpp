// Question 1
// https://cses.fi/problemset/task/1679

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> col, order;

bool dfs(int u){
    col[u] = 1;
    for(int v : g[u]){
        if(col[v] == 1){
            return false;
        }
        if(!col[v] && !dfs(v)){
            return false;
        }
    }
    col[u] = 2;
    order.push_back(u);
    return true;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    g.assign(n, vector<int>());
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[--a].push_back(--b);
    }
    col.assign(n, 0);
    for(int i = 0; i < n; i++){
        if(!col[i]){
            if(!dfs(i)){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    for(int i = n - 1; i >= 0; i--){
        cout << order[i] + 1 << ' ';
    }
    return 0;
}
