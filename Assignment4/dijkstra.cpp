// Question 2
// https://cses.fi/problemset/task/1202

#include <bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> g(n);
    for(int i = 0; i < m; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g[--u].push_back({--v, w});
    }
    vector<long long> d(n, LLONG_MAX);
    d[0] = 0;
    vector<int> p(n, -1);
    set<pair<long long, int>> s;
    s.insert({0, 0});
    while(!s.empty()){
        int u = s.begin()->second;
        s.erase(s.begin());
        for(auto e : g[u]){
            auto [v, w] = e;
            if(d[u] + w < d[v]){
                s.erase({d[v], v});
                d[v] = d[u] + w;
                p[v] = u;
                s.insert({d[v], v});
            }
        }
    }
    cout << d[n - 1] << endl;
    return 0;
}
