#include <bits/stdc++.h>
using namespace std;
void bfs (long long i, vector <bool> &visit, vector <vector<long long>> &v){
    queue <long long> q;
    q.push (i);
    visit[i]= true;
    while (!q.empty()){
        long long a = q.front();
        q.pop();
        for (long long u : v[a]){
            if (!visit[u]){
                visit[u] = true;
                q.push(u);
            }
        }
    }
}
int main (){
    long long m, n;
    cin >> m>> n;
    vector <vector<long long>> v (m+1, vector<long long> (0));
    vector <bool> visit (m+1, false);
    for (long long i =0; i < n; i++){
        long long a, b;
        cin >> a>> b;
        v[a].push_back (b);
        v[b].push_back (a);
    }
    vector <long long> ans;
    for (long long i =1; i <=m; i++){
        if (!visit[i]){
            ans.push_back (i);
            bfs(i, visit, v);
        }
    }
    cout << ans.size()-1 << endl;
    for (long long i =1; i < ans.size(); i++){
        cout << ans[0]<< " "<< ans[i]<< endl;
    }
    return 0;
}