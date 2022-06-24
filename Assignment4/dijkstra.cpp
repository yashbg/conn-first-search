// Question 2
// https://cses.fi/problemset/task/1202

#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

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
    vector<int> p(n, -1), nr(n, 0), mine(n, INT_MAX), maxe(n, 0);
    nr[0] = 1;
    mine[0] = maxe[0] = 0;
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
                nr[v] = nr[u];
                mine[v] = mine[u] + 1;
                maxe[v] = maxe[u] + 1;
                s.insert({d[v], v});
            }
            else if(d[u] + w == d[v]){
                nr[v] = (nr[v] + nr[u]) % mod;
                mine[v] = min(mine[v], mine[u] + 1);
                maxe[v] = max(maxe[v], maxe[u] + 1);
            }
        }
    }
    cout << d[n - 1] << ' ' << nr[n - 1] << ' ' << mine[n - 1] << ' ' << maxe[n - 1] << endl;
    return 0;
}
