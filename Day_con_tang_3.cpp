#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dplis1.inp", "r", stdin);
    // freopen("dplis1.out", "w", stdout);
    long long n;
    cin >> n;
    vector <long long> v;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        v.push_back (a);
    }
    vector <long long> dp(n+1, LLONG_MAX);
    dp[0]= LLONG_MIN;
    for (long long i =0; i < n; i++){
        long long l = upper_bound (dp.begin(), dp.end(), v[i])- dp.begin();
        if (dp[l-1]< v[i]){
            dp[l]= v[i];
        }
    }
    long long ans =0;
    for (long long i =0; i <=n ; i++){
        if (dp[i]< LLONG_MAX){
            ans = i;
        }
    }
    cout << ans;
}