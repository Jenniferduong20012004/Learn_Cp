#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

long long latGach(long long num, vector<vector<long long>> &table, vector<long long> &ans) {
    if (num == 0) return 0; 
    if (num == 1) return 3; 
    
    if (ans[num] != -1) {
        return ans[num];
    }
    
    long long prev = latGach(num - 1, table, ans) % MOD; 
    
    if (table[num][0] == -1) table[num][0] = prev;
    if (table[num][1] == -1) table[num][1] = (prev - table[num - 1][1] + MOD) % MOD;
    if (table[num][2] == -1) table[num][2] = (prev - table[num - 1][2] + MOD) % MOD;
    
    return ans[num] = (table[num][0] + table[num][1] + table[num][2]) % MOD;
}

int main() {
    // freopen("dplaga2.inp", "r", stdin);
    // freopen("dplaga2.out", "w", stdout);

    long long n;
    cin >> n;

    vector<long long> ans(n + 1, -1);
    vector<vector<long long>> table(n + 1, vector<long long>(3, -1));

    table[1][0] = 1;
    table[1][1] = 1;
    table[1][2] = 1;

    cout << latGach(n, table, ans) << endl;

    return 0;
}
