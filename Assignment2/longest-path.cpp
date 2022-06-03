// Question 2
// https://cses.fi/problemset/task/1680

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> col, order, l_longest;

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
                // cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    l_longest.assign(n, INT_MIN);
    for(int i = 0; i < n; i++){
        if(order[i] == n - 1){
            l_longest[order[i]] = 1;
        }
        else{
            for(int v : g[order[i]]){
                l_longest[order[i]] = max(l_longest[order[i]], l_longest[v] + 1);
            }
        }
    }
    if(l_longest[0] < 0){
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << l_longest[0] << endl;
    return 0;
}
