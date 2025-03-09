#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dpthuyen.inp", "r", stdin);
    // freopen("dpthuyen.out", "w", stdout);
    long long n;
    cin >> n;
    vector <tuple <long long , long long>> v;
    for (long long i =0; i < n; i++){
        long long a,b;
        cin >> a>> b;
        v.push_back (make_tuple (a, b));
    }
    sort (v.begin(), v.end(), [](const auto &a, const auto &b){
        if (get <0> (a) != get <0> (b)){
            return get <0> (a) < get <0> (b);
        }
        else{
            return get <1> (a) < get <1> (b);
        }
    });
    vector <long long> dp (n, 1);
    long long maxi = 1;
    for (long long i =1; i < n; i++){
        for (long long j =0; j < i; j++){
            if (get <1> (v[i]) >= get <1> (v[j])){
                dp[i]= max (dp[i], dp[j]+1);
            }
        }
        maxi = max (maxi, dp[i]);
    }
    cout << n- maxi;
    return 0;
}