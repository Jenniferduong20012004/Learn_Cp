#include <bits/stdc++.h>
using namespace std;
long long const MAXN = 1005;
vector<vector <long long>> g(MAXN); 
vector <long long> mt (MAXN);
vector <bool> used (MAXN);
vector <long long> visRow (MAXN);
vector <long long> visCol (MAXN);
bool try_kuhn (long long v){
    if (used[v]){
        return false;
    }
    used[v]= true;
    for (long long to : g[v]){
        if (mt[to]==-1|| try_kuhn(mt[to])){
            mt[to]= v;
            return true;
        }
    }
    return false;
}
void dfs(int v) {
    visRow[v] = true;
    for (int u : g[v]) {
        if (!visCol[u] && mt[u] != v) {
            visCol[u] = true;
            if (mt[u] != -1)
                dfs(mt[u]);
        }
    }
}
int main (){
    long long a, b, c;
    while (cin >> a >> b>> c){
        if (a ==0){
            break;
        }
        for (int i = 0; i < MAXN; i++) {
            g[i].clear();
            mt[i] = -1;
            visRow[i] = visCol[i] = false;
        }
        for (long long i =0; i < b+1; i++){
            mt[i]= -1;
        }
        for (long long i =0; i < c; i++){
            long long d, e;
            cin >> d>> e;
            g[d].push_back (e);
        }
        for (long long i =1; i <=a; i++){
            for (long long j =0; j < a+1; j++){
                used[j]= false;
            }
            try_kuhn (i);
        }
        for (long long v =1 ; v <=a; v++){
            bool matched = false;
            for (long long u : g[v]){
                if (mt[u]== v){
                    matched = true;
                    break;
                }
            }
            if (!matched){
                dfs (v);
            }
        }
        vector <string> result;
        for (int i = 1; i <= a; i++) {
            if (!visRow[i]) result.push_back("r" + to_string(i));
        }
        for (int i = 1; i <= b; i++) {
            if (visCol[i]) result.push_back("c" + to_string(i));
        }
        cout << result.size();
        for (string& s : result) cout << " " << s;
        cout << "\n";

    }

}
