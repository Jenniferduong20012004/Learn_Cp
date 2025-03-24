#include <bits/stdc++.h>
using namespace std;
long long components =0;
void bfs(long long s, vector <bool> &visit, vector <vector<long long >> &v){
    ++components;
    queue <long long> q;
    q.push (s);
    visit[s]= true;
    while (!q.empty()){
        long long u = q.front();
        q.pop();
        for (long long su : v[u]){
            if (!visit[su]){
                visit[su]= true;
                q.push(su);
            }
        }
    }
}
int main(){
    long long m, n;
    cin >> m >> n;
    vector <vector<long long>> v (m+1);
    for (long long i =0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector <bool> visit (n+1, false);
    for (long long i =1; i <=n; i++){
        if (!visit[i]){
            bfs (i, visit,v);
        }
    }
    cout << components;
}