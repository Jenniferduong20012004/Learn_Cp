#include <bits/stdc++.h>
using namespace std;
int main (){
    long long m, n;
    cin >> m>> n;
    vector <pair <long long, long long>> bieuDo (m+1);
    for (long long i =0; i < n; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        bieuDo[a].push_back ({b, c});
    }
    vector <long long> dist (m+1, LLONG_MAX);
    vector <long long> distWith
    priority_queue<pair<long long, long long>, vector <pair <long long, long long>>, greater<>> pq;
    pq.push ({0, 1});
    dist[1]=0;
    vector <long long> dp (m+1, 0);
    while (!pq.empty()){
        pair <long long, long long> toop = pq.top();
        pq.pop();
        long long du = toop.first;
        long long u = toop.second;
        if (du > dist[u]){
            continue;
        }
        for (long long i =0; i < bieuDo[u].size(); i++){
            long long v = bieuDo[u][i].first;
            long long w = bieuDo[u][i].second;
            if (dist[u]+w < dist[v]){
                dist[v]= dist[u]+ w;
                pq.push ({dist[v], v});
            }
        }
    }

}