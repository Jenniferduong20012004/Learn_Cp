#include <bits/stdc++.h>
using namespace std;
int main (){
    long long m, n;
    cin >> m>> n;
    vector <vector<pair <long long, long long>>> bieuDo (m+1);
    for (long long i =0; i < n; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        bieuDo[a].push_back ({b, c});
    }
    vector <vector <long long>> dist (m+1, vector <long long> (2,LLONG_MAX));
    priority_queue<tuple<long long, long long, long long>, vector <tuple <long long, long long, long long>>, greater<>> pq;
    pq.push ({0, 1, 0}); // distance, start, usedDiscount
    dist[1][0]=0;
    while (!pq.empty()){
        tuple <long long, long long, long long> toop = pq.top();
        pq.pop();
        long long du = get<0>(toop);
        long long u = get <1>(toop);
        long long used = get<2>(toop);
        if (du > dist[u][used]){
            continue;
        }
        for (long long i =0; i < bieuDo[u].size(); i++){
            long long v = bieuDo[u][i].first;
            long long w = bieuDo[u][i].second;
            if (dist[u][used]+w < dist[v][used]){ // dont use discont
                dist[v][used]= dist[u][used]+ w;
                pq.push ({dist[v][used], v, used});
            }
            if (!used){// use discount if not used
                long long discount = dist[u][used]+ w/2;
                if (dist[v][1]> discount){
                    dist[v][1]= discount;
                    pq.push ({dist[v][1], v, 1});
                }
            }
        }
    }
    cout << dist[m][1]<< endl;

}