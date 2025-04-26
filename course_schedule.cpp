#include <bits/stdc++.h>
using namespace std;
int main (){
    long long a, b;
    cin >> a>> b;
    vector <long long> indegree (a+1, 0);
    queue<long long> q;
    vector <vector <long long>> v (a+1);
    vector <long long> topo;
    for (long long i = 0; i < b; i++){
        long long c, d;
        cin >> c >> d;
        indegree[d]++;
        v[c].push_back (d);
    }
    for (long long i = 1; i <= a; i++){
        if (indegree[i]==0){
            q.push (i);
        }
    }
    while (!q.empty()){
        long long r = q.front();
        q.pop();
        topo.push_back(r);
        for (long long i: v[r]){
            indegree[i]--;
            if (indegree[i]==0){
                q.push(i);
            }
        }
    }
    if (topo.size() < a){
        cout << "IMPOSSIBLE";
    }
    else{
        for (long long i : topo){
            cout << i << " ";
        }
    }
}