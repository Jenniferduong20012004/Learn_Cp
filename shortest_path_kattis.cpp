#include <bits/stdc++.h>
using namespace std;
int main (){
    long long a,b,c,d;
    while(cin >> a>> b>> c>> d){
        if (a==0 && b==0 && c==0 && d==0){
            break;
        }
        vector <vector <pair <long long, long long>>> bieuDo (a);
        for (long long i =0; i < b; i++){
            long long g,e,f;
            cin >> g>> e>> f;
            bieuDo[g].push_back ({e, f});
        }
        vector <long long> dist (a, LLONG_MAX);
        dist[d]= 0;
        priority_queue <pair<long long, long long>, vector <pair <long long, long long>>, greater<>> pq;
        pq.push ({0, d});
        while (!pq.empty()){
            pair<long long, long long> toop= pq.top();
            pq.pop();
            long long du = toop.first;
            long long u = toop.second;
            if (du > dist[u]){
                continue;
            }
            for (long long i =0; i < bieuDo[u].size(); i++){
                long long v = bieuDo[u][i].first;
                long long w = bieuDo[u][i].second;
                if (dist[u]+ w< dist[v]){
                    dist[v]= dist[u]+ w;
                    pq.push ({dist[v], v});
                }
            }
        }
        for (long long ii =0; ii < c; ii++){
            long long r;
            cin >> r;
            if (dist[r]== LLONG_MAX){
                cout << "Impossible"<< endl;
            }
            else{
                cout << dist[r]<< endl;
            }
        }
        cout<< endl;



    }

}