#include <bits/stdc++.h>
using namespace std;

int n = 10;
vector<vector<int>> adj(n);
vector<int> tin(n), tout(n);
vector<bool> vis(n, false);
int t = 0;

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

bool dfs_cycle(int u, int p){
    vis[u] = true;
    for(int v : adj[u]){
        if(v == p){
            continue;
        }
        else if(vis[u]){
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
            if(dfs_cycle(u, -1)){
                return true;
            }
        }
    }
    return false;
}

// Question 5

