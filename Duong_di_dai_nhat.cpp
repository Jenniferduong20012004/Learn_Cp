#include <bits/stdc++.h>
using namespace std;
int main (){
    long long n, m;
    cin >> n>> m;
    vector <vector <long long >> bieuDo (n+1, vector <long long> (0));
    vector <long long> indegree (n+1, 0);
    vector <long long> ll;
    vector <long long> dp (n+1, 0);
    for (long long i =0; i < m; i++){
        long long a, b;
        cin >> a>> b;
        bieuDo[a].push_back (b);
        indegree[b]++;
    }
    queue <long long> q;
    for (long long i =1; i <= n; i++){
        if (indegree[i]==0){
            q.push (i);
        }
    }
    long long maxi =0;
    while (!q.empty()){
        long long u = q.front();
        q.pop();
        ll.push_back (u);
        for (long long v: bieuDo[u]){
            indegree[v]--;
            dp [v] = max (dp[v], dp[u]+1);
            maxi = max (maxi,dp[v]);
            if (indegree[v]==0){
                q.push (v);
            }
        }
    }
    cout << maxi;
}