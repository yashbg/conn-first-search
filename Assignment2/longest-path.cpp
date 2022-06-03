// Question 2
// https://cses.fi/problemset/task/1680

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> vis;
vector<int> order, l_longest, par;

void dfs(int u){
    vis[u] = true;
    for(int v : g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    order.push_back(u);
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
    vis.assign(n, false);
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    l_longest.assign(n, INT_MIN);
    par.assign(n, -1);
    for(int i = 0; i < n; i++){
        if(order[i] == n - 1){
            l_longest[order[i]] = 1;
        }
        else{
            for(int v : g[order[i]]){
                if(l_longest[v] + 1 > l_longest[order[i]]){
                    par[order[i]] = v;
                    l_longest[order[i]] = l_longest[v] + 1;
                }
            }
        }
    }
    if(l_longest[0] < 0){
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << l_longest[0] << endl;
    int cur = 0;
    while(cur != -1){
        cout << cur + 1 << ' ';
        cur = par[cur];
    }
    return 0;
}
