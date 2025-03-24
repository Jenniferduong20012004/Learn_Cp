#include <bits/stdc++.h>
using namespace std;
bool bfs(long long s, vector<bool> & visit, vector<long long> &ans, vector<vector<long long>> &v){
    queue <long long> q;
    q.push (s);
    visit[s]= true;
    ans[s]= 1;
    while (!q.empty()){
        long long u = q.front();
        q.pop();
        long long cur = ans[u];
        for (long long a: v[u]){
            if (!visit[a]){
                visit [a]= true;
                if (cur ==1){
                    ans[a] =2;
                }
                else{
                    ans[a]=1;
                }
                q.push (a);
            }
            else{
                if (ans[a]== cur){
                    return false;
                }
            }
        }
    }
    return true;
    
}
int main (){
    long long m , n;
    cin >> m>> n;
    vector <vector <long long>> v(m+1, vector<long long >(0));
    vector <long long> ans (m+1, 0);
    vector <bool> visit (m+1, false);
    for (long long i =0; i < n; i++){
        long long a, b;
        cin >> a>> b;
        v[a].push_back (b);
        v[b].push_back (a);
    }
    bool tong = true;
    for (long long i=1; i<=m; i++){
        if (!visit[i]){
            bool im = bfs(i, visit, ans, v);
            if (im == false){
                tong = false;
                break;
            }
        }
    }
    if (tong){
        for (long long i =1; i <= m; i++){
            cout << ans[i]<< " ";
        }
    }
    else{
        cout << "IMPOSSIBLE";
    }
    
}