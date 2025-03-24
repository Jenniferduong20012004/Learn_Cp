#include <bits/stdc++.h>
using namespace std;

void TryX(long long i, long long n, long long x, long long sum, vector<long long> t, vector<long long> &A) {
    if (i > n) {
        A.push_back(sum);
        return; 
    }
    TryX(i + 1, n, x, sum, t, A);
    TryX(i + 1, n, x, sum + t[i], t, A);
}

int main() {
    long long n, x;
    cin >> n >> x;
    vector<long long> t(n);
    for (long long i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<long long> A, B;
    vector<long long> left(t.begin(), t.begin() + n/2);
    vector<long long> right(t.begin() + n/2, t.end());

    TryX(0, left.size() - 1, x, 0, left, A);
    TryX(0, right.size() - 1, x, 0, right, B);

    sort(B.begin(), B.end());

    long long ans = 0;
    for (long long sum : A) {
        ans += upper_bound(B.begin(), B.end(), x - sum) - lower_bound(B.begin(), B.end(), x - sum);
    }

    cout << ans;
}
