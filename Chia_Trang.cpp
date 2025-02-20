#include <bits/stdc++.h>
using namespace std;
// 4 5
// 3 2 2 4
int main(){
    // freopen("dpdivi.inp", "r", stdin);
    // freopen("dpdivi.out", "w", stdout);
    long long n, l;
    cin >> n>> l;
    vector <long long> prefixSum (n+1, 0);
    vector <long long> dp (n+1, LLONG_MAX);
    dp[0]=0;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        prefixSum [i+1]= prefixSum[i]+a;
    }
    for (long long i =1; i <= n; i++){
        for (long long j =1; j <=i; j++){
            long long sumFromJtoI = prefixSum[i]- prefixSum[j-1];
            if (sumFromJtoI<= l){
                long long phat = l - sumFromJtoI;
                dp[i]= min (dp[i], max (dp[j-1], phat));
            }
        }
    }
    cout << dp[n];
    return 0;
}
