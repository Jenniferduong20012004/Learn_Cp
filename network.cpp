#include <bits/stdc++.h>
using namespace std;

void dfs(long long a, long long parent, vector<vector<long long>>& v, vector<long long>& num, vector<long long>& low, vector<bool>& joint, long long& timer) {
    num[a] = low[a] = ++timer;
    long long children = 0;

    for (long long child : v[a]) {
        if (child == parent) continue;

        if (!num[child]) {
            dfs(child, a, v, num, low, joint, timer);
            low[a] = min(low[a], low[child]);
            if (parent != a && low[child] >= num[a]) {
                joint[a] = true;
            }
            ++children;
        } else {
            low[a] = min(low[a], num[child]);
        }
    }

    if (parent == a && children > 1) {
        joint[a] = true;
    }
}

int main() {
    long long n;
    while (cin >> n && n != 0) {
        cin.ignore();
        vector<vector<long long>> v(n + 1);
        string s;
        
        while (getline(cin, s)) {
            if (s[0] == '0') break;
            stringstream ss(s);
            long long from, to;
            ss >> from;
            while (ss >> to) {
                v[from].push_back(to);
                v[to].push_back(from);
            }
        }

        vector<long long> num(n + 1, 0), low(n + 1, 0);
        vector<bool> joint(n + 1, false);
        long long timer = 0;

        for (long long i = 1; i <= n; ++i) {
            if (!num[i]) {
                dfs(i, i, v, num, low, joint, timer);
            }
        }

        long long count = 0;
        for (bool isJoint : joint) {
            count += isJoint;
        }

        cout << count << endl;
    }

    return 0;
}
