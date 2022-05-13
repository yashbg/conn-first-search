#include <bits/stdc++.h>
using namespace std;

int n = 10;
vector<vector<int>> adj(n);
vector<int> tin(n), tout(n);
vector<bool> vis(n, false);
int t = 0;

vector<int> bfs(int s){
    queue<int> q;
    vector<int> d(n, -1);
    vector<bool> vis(n, false);
    q.push(s);
    d[s] = 0;
    vis[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(!vis[v]){
                q.push(v);
                d[v] = d[u] + 1;
                vis[v] = true;
            }
        }
    }
    return d;
}

void dfs(int u){
    vis[u] = true;
    tin[u] = t++;
    for(int v : adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    tout[u] = t++;
}
