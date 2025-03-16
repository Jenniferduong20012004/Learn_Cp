#include <bits/stdc++.h>
using namespace std;


int main () {
    // freopen("dprentma2.inp", "r", stdin);
    // freopen("dprentma2.out", "w", stdout);
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cin.exceptions(cin.failbit);
    long long n; 
    cin >> n;
    vector<tuple <long long, long long>> a(n+1);
    for (long long i = 1 ; i <= n ; i++) {
        long long soA, soB;
        cin >> soA;
        cin >> soB;
        a[i]= make_tuple (soA, soB);
    }
    sort(a.begin()+1, a.end(), [](const auto &a, const auto &b){
        if (get<1> (a)== get <1> (b)){
            return get<0> (a)< get <0> (b);
        }
        else{
            return get<1> (a)< get <1> (b);
        }
    });
    map<long long , long long> dp;
    dp[0] = 0;
    for (int i = 1 ; i <=n ; i++) {
        dp[get <1>(a[i])] = dp[get <1>(a[i-1])];
        auto it = dp.lower_bound(get <0>(a[i]));
        it--;   
        dp[get <1>(a[i])] = max(dp[get <1>(a[i])], get <1>(a[i]) - get <0>(a[i]) + 1 + it->second);
    }
    cout << dp[get <1>(a[n])];
    return 0;
}
