#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dpthuyen2.inp", "r", stdin);
    // freopen("dpthuyen2.out", "w", stdout);
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cin.exceptions(cin.failbit);
    long long n; 
    cin >> n;
    vector<tuple <long long, long long>> a(n);
    for (long long i = 0; i < n ; i++) {
        long long soA, soB;
        cin >> soA;
        cin >> soB;
        a[i]= make_tuple (soA, soB);
    }
    sort(a.begin(), a.end());
    vector <long long> dp (n+1, LLONG_MAX);
    dp[0]= LLONG_MIN;
    for (long long i =0; i <n; i++){
        long long cur = get <1> (a[i]);
        long long des = upper_bound (dp.begin(), dp.end(), cur)- dp.begin();
        // cout << cur  << " "<< des<< endl;
        dp[des]= cur;
    }
    long long koCanXoa =0;
    for (long long i =1; i <=n; i++){
        if (dp[i] == LLONG_MAX){
            break;
        }
        koCanXoa++;
    }
    long long res = n - koCanXoa;
    cout << res;
    return 0;
}