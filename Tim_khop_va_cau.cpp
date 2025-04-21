#include <bits/stdc++.h>
using namespace std;

long long timeDfs = 0;
vector<long long> num, low;
vector<vector<long long>> graph;
set<long long> articulationPoints;
vector<pair<long long, long long>> bridges;

void dfs(long long u, long long pre, long long root, long long &childCount) {
    num[u] = low[u] = ++timeDfs;
    long long children = 0; 

    for (long long v : graph[u]) {
        if (v == pre) continue; 

        if (!num[v]) {  
            children++;
            dfs(v, u, root, childCount);
            low[u] = min(low[u], low[v]); 
            if (u == root && children > 1) articulationPoints.insert(u);
            if (u != root && low[v] >= num[u]) articulationPoints.insert(u);

            // Điều kiện để (u, v) là cầu
            if (low[v] > num[u]) bridges.push_back({u, v});

        } else {  // Nếu v đã thăm trước đó => back edge
            low[u] = min(low[u], num[v]);
        }
    }
}

int main() {
    long long m, n;
    cin >> m >> n;

    graph.assign(m, vector<long long>());
    num.assign(m, 0);
    low.assign(m, 0);

    for (long long i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        a--; b--;  
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (long long i = 0; i < m; i++) {
        if (num[i] == 0) {
            long long childCount = 0;
            dfs(i, -1, i, childCount);
        }
    }

    cout << articulationPoints.size() << " " << bridges.size() << endl;

    return 0;
}
