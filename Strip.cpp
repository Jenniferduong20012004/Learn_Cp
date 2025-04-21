#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e8;
long long queryMin(int L, int R, const vector<vector<long long>> &st, const vector<long long> &a) {
    int j = log2(R - L + 1);
    return min(a[st[L][j]], a[st[R - (1 << j) + 1][j]]);
}

long long queryMax(int L, int R, const vector<vector<long long>> &st, const vector<long long> &a) {
    int j = log2(R - L + 1);
    return max(a[st[L][j]], a[st[R - (1 << j) + 1][j]]);
}

int main (){
    long long n, l, s;
    cin >> n >> l >> s;
    vector <long long> deBai;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        deBai.push_back (a);
    }
    long long chiSoY = log2(n) + 1;;
    vector <vector<long long>> parseTable (n, vector <long long> (chiSoY, 0));
    vector <vector <long long>> parseTableMax (n, vector <long long> (chiSoY, 0));
    for (long long i =0; i < n; i++){
        parseTable [i][0]= i;
        parseTableMax [i][0]= i;
    }
    for (long long j = 1; (1 << j) <= n; j++) {
        for (long long i = 0; i + (1 << j) - 1 < n; i++) {
            if (deBai[parseTable[i][j - 1]] < deBai[parseTable[i + (1 << (j - 1))][j - 1]]) {
                parseTable[i][j] = parseTable[i][j - 1];
            } else {
                parseTable[i][j] = parseTable[i + (1 << (j - 1))][j - 1];
            }
        }
    }
    for (long long j = 1; (1 << j) <= n; j++) {
        for (long long i = 0; i + (1 << j) - 1 < n; i++) {
            if (deBai[parseTableMax[i][j - 1]] > deBai[parseTableMax[i + (1 << (j - 1))][j - 1]]) {
                parseTableMax[i][j] = parseTableMax[i][j - 1];
            } else {
                parseTableMax[i][j] = parseTableMax[i + (1 << (j - 1))][j - 1];
            }
        }
    }
    // for (long long i =0; i < parseTable.size(); i++){
    //     for (long long j =0; j < parseTable[0].size(); j++){
    //         cout << parseTableMax[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<long long> dp(n + 1, INF);
    dp[0] = 0;
    multiset<long long> minSet; 
    int left = 0;
    for (int i = l - 1; i < n; ++i) {
        int lo = 0, hi = i - l + 1, best = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            long long mn = queryMin(mid, i, parseTable, deBai);
            long long mx = queryMax(mid, i, parseTableMax, deBai);
            if (mx - mn <= s) {
                best = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        if (best == -1) continue;

        // dp[i+1] = min(dp[best..i-l+1]) + 1
        long long res = INF;
        for (int j = best; j <= i - l + 1; ++j) {
            res = min(res, dp[j]);
        }
        dp[i + 1] = (res == INF ? INF : res + 1);
    }

    if (dp[n] >= INF)
        cout << -1;
    else
        cout << dp[n];

    
}

    