#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dprentma.inp", "r", stdin);
    // freopen("dprentma.out", "w", stdout);
    long long n;
    cin >> n;
    vector <tuple<long long, long long>> thoigianthue;
    vector <long long> dp (n, 0);
    for (long long i =0; i < n; i++){
        long long a,b;
        cin >> a>> b;
        thoigianthue.push_back (make_tuple(a, b));
    }
    sort (thoigianthue.begin(), thoigianthue.end());
    // for (long long i =0; i < n; i++){
    //     cout << get <0> (thoigianthue[i])<< " "<< get <1> (thoigianthue[i]) << endl;
    // }
    dp[0] = get <1> (thoigianthue[0])-get <0> (thoigianthue[0])+1;
    long long maxi =dp[0];
    for (long long i =1; i < n; i++){
        dp[i] = get <1> (thoigianthue[i])-get <0> (thoigianthue[i])+1;
        for (long long j =0; j < i; j++){
            if (get <0> (thoigianthue[i])> get <1> (thoigianthue[j])){
                dp[i]= max (dp[i], dp[j]+ get <1> (thoigianthue[i])-get <0> (thoigianthue[i])+1);
            }
        }
        maxi = max (maxi, dp[i]);
    }
    cout << maxi;
}