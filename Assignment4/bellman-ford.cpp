// Question 1
// https://cses.fi/problemset/task/1197

#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v;
    long long w;
};

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    for(int i = 0; i < m; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges[i] = {--u, --v, w};
    }
    vector<long long> d(n, 0);
    vector<int> p(n, -1);
    int x;
    for(int i = 0; i < n; i++){
        x = -1;
        for(auto e : edges){
            if(d[e.u] + e.w < d[e.v]){
                d[e.v] = d[e.u] + e.w;
                p[e.v] = e.u;
                x = e.v;
            }
        }
    }
    if(x == -1){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        x = p[x];
    }
    vector<int> path;
    for(int y = x; ; y = p[y]){
        path.push_back(y);
        if(y == x && path.size() > 1){
            break;
        }
    }
    reverse(path.begin(), path.end());
    cout << "YES" << endl;
    for(auto x : path){
        cout << x + 1 << " ";
    }
    return 0;
}
