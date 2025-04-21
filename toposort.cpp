#include <bits/stdc++.h>
using namespace std;
int main (){
    long long m, n;
    cin >> m>> n;
    vector <long long> indegree (m+1, 0);
    priority_queue<long long, vector<long long>, greater<long long>>  listSource;
    vector <long long> topo;
    vector <vector <long long >> bieuDo (m+1, vector <long long> (0));
    for (long long i =0; i < n; i++){
        long long a, b;
        cin >> a>> b;
        bieuDo[a].push_back (b);
        indegree[b]++;
    }
    for (long long i =1; i <=m;i++){
        if (indegree[i]==0){
            listSource.push(i);
        }
    }
    while (!listSource.empty()){
        long long u = listSource.top();
        listSource.pop();
        topo.push_back (u);
        for (auto v: bieuDo[u]){
            indegree[v]--;
            if (indegree[v]==0){
                listSource.push(v);
            }
        }
    }
    if (topo.size()<m){
        cout << "Sandro fails."<< endl;
    }
    else{
        for (auto x: topo){
            cout << x << " ";
        }
    }
}