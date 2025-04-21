#include <bits/stdc++.h>
using namespace std;
int main (){
    long long m , n;
    cin >> m>> n;
    vector <long long> indegree (m+1, 0);
    vector <vector <long long>> bieuDo (m+1, vector <long long> (0));
    for (long long i =0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        bieuDo[a].push_back (b);
        indegree[b]++;
    }
    queue <long long> q;
    for (long long i = 1; i <=m; i++){
        if (indegree[i]==0){
            q.push (i);
        }
    }
    vector <long long> topo;
    vector <long long> dpStartBy (m+1, 0);
    vector <long long> dp (m+1,-1);
    while (!q.empty()){
        long long u = q.front();
        q.pop();
        topo.push_back (u);
        for (long long v: bieuDo[u]){
            indegree[v]--;
            if (indegree[v]==0){
                q.push (v);
            }
        }
    }
    if (topo.size()< m){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        dp[1]= 1;
        vector <long long> prev_city (m+1, 0);
        for (long long u : topo){
            if (dp[u]==-1){
                continue;
            }
            for (long long v : bieuDo [u]){
                if (dp[u]+1 > dp[v]){
                    dp[v]= dp[u]+1;
                    prev_city [v] =u;
                }
            }
        }
            if (dp[m]==-1){
                cout << "IMPOSSIBLE";
            }
            else{
                cout << dp[m]<< endl;
                long long r = prev_city [m];
                vector <long long> ans;
                ans.push_back (m);
                while (r !=0){
                    
                    ans.push_back (r);
                    r = prev_city[r];
                    if (r == 0){
                        break;
                    }
                }
                for (long long ii =ans.size()-1; ii >=0;ii--){
                    cout << ans[ii] <<" ";
                }
            }
    }

}