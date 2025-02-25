#include <bits/stdc++.h>
using namespace std;
int main(){
    // freopen("dpliq1.inp", "r", stdin);
    // freopen("dpliq1.out", "w", stdout);
    long long n;
    cin >> n;
    vector <long long> v;
    for (long long i =0; i < n; i++){
        long long a;
        cin >>a;
        v.push_back (a);
    }
    vector <long long> dp (n, 1);
    long long maxi =1;
    for (long long i = 1; i < n; i++){
        for (long long j =0; j < i; j++){
            if (v[i]> v[j]){
                dp[i] = max (dp[i], dp[j]+1);
            }
        }
        maxi = max (maxi, dp[i]);
    }
    cout << maxi;
    return 0;
}