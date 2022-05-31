// Question 3
// https://cses.fi/problemset/task/1683

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g, gt;
vector<bool> vis;
vector<int> order, comp;

void dfs1(int u){
    vis[u] = true;
    for(int v : g[u]){
        if(!vis[v]){
            dfs1(v);
        }
    }
    order.push_back(u);
}

void dfs2(int u, int k){
    comp[u] = k;
    for(int v : gt[u]){
        if(!comp[v]){
            dfs2(v, k);
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    g.assign(n, vector<int>());
    gt.assign(n, vector<int>()); 
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[--a].push_back(--b);
        gt[b].push_back(a);
    }
    vis.assign(n, false);
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs1(i);
        }
    }
    comp.assign(n, 0);
    int k = 0;
    for(int i = n - 1; i >= 0; i--){
        if(!comp[order[i]]){
            dfs2(order[i], ++k);
        }
    }
    cout << k << endl;
    for(int i = 0; i < n; i++){
        cout << comp[i] << ' ';
    }
    return 0;
}
