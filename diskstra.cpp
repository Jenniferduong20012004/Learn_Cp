#include <bits/stdc++.h>
using namespace std;
int main (){
    long long m, n;
    cin >> m>> n;
    vector <vector <pair<long long, long long>>> bieuDo (m+1);
    for (long long i =0; i < n; i++){
        long long a, b, c;
        cin >> a>> b>> c;
        bieuDo[a].push_back ({b, c});
        bieuDo[b].push_back ({a, c});
    }
    vector <long long> dist (m+1, LLONG_MAX);
    priority_queue <pair<long long, long long>, vector <pair<long long, long long>>, greater<>> pq;
    pq.push ({0, 1});
    vector <long long> startPosition (m+1, 0);
    dist[1] = 0;
    startPosition[1] = 0;
    while (!pq.empty()){
        pair <long long, long long> toop = pq.top();
        pq.pop();
        long long du = toop.first;
        long long u = toop.second;
        if (du>dist[u]){
            continue;
        }
        for (long long i =0; i <bieuDo[u].size();i++ ){
            long long v = bieuDo[u][i].first;
            long long w = bieuDo[u][i].second;
            if (dist[u]+ w < dist[v]){
                dist[v]= dist[u]+ w;
                startPosition[v] = u;
                pq.push ({dist[v], v});
            }
        }

    }
    if (dist[m]== LLONG_MAX){
        cout << "-1";
    }
    else{
        vector <long long> ans;
        long long r = m;
        while (r !=0){
            ans.push_back (r);
            r = startPosition[r];
        }
        for (long long i = ans.size()-1; i >=0; i--){
            cout << ans[i]<< " ";
        }
    }
}