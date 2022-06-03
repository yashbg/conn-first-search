// Question 4
// https://cses.fi/problemset/task/1684

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g, gt;
vector<bool> vis, ans;
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
        if(comp[v] == -1){
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
    g.assign(2 * m, vector<int>());
    gt.assign(2 * m, vector<int>());
    for(int i = 0; i < n; i++){
        char ca, cb;
        int a, b, na, nb;
        cin >> ca >> a >> cb >> b;
        a--, b--;
        a = 2 * a + (ca == '+' ? 0 : 1);
        b = 2 * b + (cb == '+' ? 0 : 1);
        na = a ^ 1;
        nb = b ^ 1;
        g[na].push_back(b);
        g[nb].push_back(a);
        gt[a].push_back(nb);
        gt[b].push_back(na);
    }
    vis.assign(2 * m, false);
    for(int i = 0; i < 2 * m; i++){
        if(!vis[i]){
            dfs1(i);
        }
    }
    reverse(order.begin(), order.end());
    comp.assign(2 * m, -1);
    int k = -1;
    for(int u : order){
        if(comp[u] == -1){
            dfs2(u, ++k);
        }
    }
    ans.assign(m, false);
    for(int i = 0; i < m; i++){
        cout << comp[2 * i] << ' ' << comp[2 * i + 1] << endl;
    }
    for(int i = 0; i < m; i++){
        if(comp[2 * i] == comp[2 * i + 1]){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        ans[i] = comp[2 * i] > comp[2 * i + 1];
    }
    for(int i = 0; i < m; i++){
        cout << (ans[i] ? "+ " : "- ");
    }
    return 0;
}
