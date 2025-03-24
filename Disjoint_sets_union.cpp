#include <bits/stdc++.h>
using namespace std;
long long par[100004];
struct DSU{
    void ini (int n){
        for (long long i =1; i <=n; i++){
            par[i]= i;
        }
    }
    long long find (long long v){
        if (v == par[v]){
            return v;
        }
        else{
            return par[v]= find (par[v]);
        }
    }
    void Union (long long u, long long v){
        u = find (u);
        v = find (v);
        if (u !=v){
            par[v]=u;
        }
    }
}dsu;
int main (){
    long long n,m;
    cin >> n>> m;
    for (long long te = 0; te < m; te++){
        string s;
        cin >> s;
        long long a, b;
        cin >> a >> b;
        if(s == "union") {
            dsu.Union(a,b);
        } else {
            cout << (dsu.find(a) == dsu.find(b) ? "YES\n" : "NO\n");
        }
    }
}