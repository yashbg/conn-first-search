#include <bits/stdc++.h>
using namespace std;

int n = 10;
vector<vector<int>> adj(n);
vector<int> tin(n), tout(n);
vector<bool> vis(n, false);
int t = 0;
vector<int> low(n);
vector<vector<bool>> deleted(n, vector<bool>(n));

// Question 1

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

bool dfs_tree_edge(int a, int u, int v){
    vis[a] = true;
    for(int b : adj[a]){
        if(!vis[b]){
            if((u == a && v == b) || (u == b && v == a)){
                return true;
            }
            if(dfs_tree_edge(b, u, v)){
                return true;
            }
        }
    }
    return false;
}

bool is_tree_edge(int u, int v){
    vis.assign(n, false);
    for(int a = 0; a < n; a++){
        if(!vis[a]){
            if(dfs_tree_edge(a, u, v)){
                return true;
            }
        }
    }
    return false;
}

// Question 2

vector<int> bfs(int s){
    queue<int> q;
    vector<int> d(n, -1);
    vis.assign(n, false);
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

// Question 3

void dfs_comp(int u, int k, vector<int>& comps){
    vis[u] = true;
    comps[u] = k;
    for(int v : adj[u]){
        if(!vis[v]){
            dfs_comp(v, k, comps);
        }
    }
}

vector<int> conn_comp(){
    vector<int> comps(n);
    vis.assign(n, false);
    int k = 0;
    for(int u = 0; u < n; u++){
        if(!vis[u]){
            k++;
            dfs_comp(u, k, comps);
        }
    }
    return comps;
}

// Question 4

bool dfs_cycle(int u, int p = -1){
    vis[u] = true;
    for(int v : adj[u]){
        if(v == p){
            continue;
        }
        if(vis[u]){
            return true;
        }
        if(dfs_cycle(v, u)){
            return true;
        }
    }
    return false;
}

bool is_cyclic(){
    vis.assign(n, false);
    for(int u = 0; u < n; u++){
        if(!vis[u]){
            if(dfs_cycle(u)){
                return true;
            }
        }
    }
    return false;
}

// Question 5

void dfs_bridge(int u, int p = -1){
    vis[u] = true;
    tin[u] = t++;
    low[u] = tin[u];
    for(int v : adj[u]){
        if(v == p){
            continue;
        }
        if(vis[v]){
            low[u] = min(low[u], tin[v]);
        }
        else{
            dfs_bridge(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u]){
                deleted[u][v] = true;
                deleted[v][u] = true;
            }
        }
    }
}

void delete_bridges(){
    vis.assign(n, false);
    t = 0;
    deleted.assign(n, vector<bool>(n, false));
    for(int u = 0; u < n; u++){
        if(!vis[u]){
            dfs_bridge(u);
        }
    }
}
