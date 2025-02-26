#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dpseg.inp", "r", stdin);
    // freopen("dpseg.out", "w", stdout);
    long long n;
    cin >> n;
    vector <tuple<long long, long long>> doan;
    vector <long long> dp (n, 1);
    for (long long i =0; i < n; i++){
        long long a,b;
        cin >> a>> b;
        doan.push_back (make_tuple(a, b));
    }
    sort(doan.begin(), doan.end(), [](tuple<long long, long long> a, tuple<long long, long long> b) {
        return get<0>(a) < get<0>(b) || (get<0>(a) == get<0>(b) && get<1>(a) > get<1>(b));
    });
    
    long long maxi =1;
    for (long long i =1; i < n; i++){
        for (long long j =0; j < i; j++){
            if (  get <1> (doan[i])<= get <1> (doan[j])){
                dp[i]= max (dp[i], dp[j]+1);
            }
        }
        maxi = max (maxi, dp[i]);
    }
    cout << maxi;
}