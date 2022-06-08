// Question 1
// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A?f0a28=1

#include <bits/stdc++.h>
using namespace std;

class dsu{
    vector<int> par;

public:
    dsu(int n){
        par.assign(n, 0);
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
    }

    void union_(int a, int b){
        a = find(a);
        b = find(b);
        par[b] = a;
    }

    int find(int u){
        if(par[u] == u){
            return u;
        }
        return par[u] = find(par[u]);
    }
};

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    dsu d(n);
    while(m--){
        string q;
        cin >> q;
        int u, v;
        cin >> u >> v;
        u--, v--;
        if(q == "union"){
            d.union_(u, v);
        }
        else{
            cout << (d.find(u) == d.find(v) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
