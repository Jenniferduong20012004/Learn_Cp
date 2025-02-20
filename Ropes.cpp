#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> v;
    long long max_element = 0;
    for (long long i = 0; i < n; i++) {
        long long a;
        cin >> a;
        v.push_back(a);
        if (a > max_element) {
            max_element = a;
        }
    }
    double mini = 1;
    double maxi = max_element; 
    double ans = 0;
    while (fabs(maxi - mini) > 1e-7) { 
        double mid = mini + (maxi - mini) / 2;
        long long curSum = 0;
        for (long long i = 0; i < n; i++) {
            curSum += (long long)(v[i] / mid);
            if (curSum >= k) break; 
        }
        if (curSum >= k) {
            ans = mid;
            mini = mid;
        } else {
            maxi = mid;
        }
    }
    cout << setprecision(6) << ans;
    return 0;
}