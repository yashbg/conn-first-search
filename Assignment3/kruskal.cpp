// Question 3
// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/E

#include <bits/stdc++.h>
using namespace std;

vector<int> p, r;

class Edge{
public:
    int u, v, w;

    Edge(int u, int v, int w) : u(u), v(v), w(w) {}

    bool operator<(const Edge &e){
        return w < e.w;
    }
};

int find(int v){
    if(v == p[v]){
        return v;
    }
    return p[v] = find(p[v]);
}

void union_(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(r[a] < r[b]){
            swap(a, b);
        }
        p[b] = a;
        if(r[a] == r[b]){
            r[a]++;
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
    vector<Edge> edges;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(--u, --v, w));
    }
    p.assign(n, 0);
    r.assign(n, 0);
    iota(p.begin(), p.end(), 0);
    sort(edges.begin(), edges.end());
    long long sum = 0;
    int cnt = 0;
    for(auto e : edges){
        if(find(e.u) != find(e.v)){
            sum += e.w;
            union_(e.u, e.v);
            cnt++;
            if(cnt == n - 1){
                break;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
