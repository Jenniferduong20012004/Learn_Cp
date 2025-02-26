#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dprentht.inp", "r", stdin);
    // freopen("dprentht.out", "w", stdout);
    long long n;
    cin >> n;
    vector <tuple<long long, long long>> thoigianthue;
    vector <long long> dp (n, 1);
    for (long long i =0; i < n; i++){
        long long a,b;
        cin >> a>> b;
        thoigianthue.push_back (make_tuple(a, b));
    }
    sort (thoigianthue.begin(), thoigianthue.end());
    long long maxi =1;
    for (long long i =1; i < n; i++){
        for (long long j =0; j < i; j++){
            if (get <0> (thoigianthue[i])> get <1> (thoigianthue[j])){
                dp[i]= max (dp[i], dp[j]+ 1);
            }
        }
        maxi = max (maxi, dp[i]);
    }
    cout << maxi;
}