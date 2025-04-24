#include <bits/stdc++.h>
using namespace std;
int main  (){
    long long a, b;
    cin >> a >> b;
    vector <vector<pair<long long, long long>>> bieuDo (a+1);
    for (long long i =0; i < b; i++){
        long long d, e;
        cin >> d>> e;
        bieuDo[d].push_back ({e, 0});
        bieuDo[e].push_back({d, 1});
    }
    priority_queue <tuple <long long, long long, long long>, vector <tuple<long long, long long, long long>>, greater <>> pq;
    vector <vector<long long>> dist (a+1, vector <long long > (2, LLONG_MAX));
    long long s, t;
    cin >> s >> t;
    pq.push({0, s, 0});
    pq.push({0, s, 1});
    dist[s][0]= 0;
    dist[s][1]= 0;
    while (!pq.empty()){
        tuple <long long, long long, long long> toop = pq.top();
        long long currentChange = get <0> (toop);
        long long u = get <1> (toop);
        long long currentGear = get <2> (toop);
        pq.pop();
        for (long long i =0; i < bieuDo[u].size(); i++){
            pair <long long, long long> cur = bieuDo[u][i];
            long long v = cur.first;
            long long w = cur.second;
            long long change =0;
            if (currentGear == w){
                change =0;
            }
            else{
                change = 1;
            }
            if (dist [v][w]> currentChange+ change){
                dist[v][w]= currentChange + change;
                pq.push ({dist[v][w], v, w});

            }

        }
    }
    cout << min(dist[t][0], dist[t][1]);
    
}