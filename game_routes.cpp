#include <bits/stdc++.h>
using namespace std;
int main (){
    long long n, m;
    cin >> n >> m;
    vector <long long> indegree (n+1, 0);
    vector <vector <long long>> teleporter (n+1, vector <long long> (0));
    for (long long i =0; i < m; i++){
        long long a, b;
        cin >> a >> b;
        teleporter [a].push_back (b);
        indegree[b]++;
    }
    queue<long long> q;
    for (long long i =1; i <= n; i++){
        if (indegree[i]==0){
            q.push (i);        
        }
    }
    vector <long long> topo;
    while (!q.empty()){
        long long a = q.front();
        q.pop();
        topo.push_back (a);
        for (long long b : teleporter[a]){
            indegree[b]--;
            if (indegree[b]==0){
                q.push (b);
            }
        }
    }
    vector <long long> dp (n+1, 0);
    dp [1]= 1;
    for (long long i : topo){
        for (long long u : teleporter[i]){
            dp[u] = (dp[u]+ dp[i]) % 1000000007;
        }
    }
    cout << dp[n];

}