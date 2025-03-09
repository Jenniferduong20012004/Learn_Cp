#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dpsancorp2.inp", "r", stdin);
    // freopen("dpsancorp2.out", "w", stdout);
    long long test ;
    cin >> test;
    for (long long te =0; te < test; te++){
        long long n;
        cin >> n;
        vector <tuple <long long, long long ,long long>> v;
        for (long long i =0; i < n; i++){
            long long a,b,c;
            cin >>a>>b>>c;
            v.push_back (make_tuple (a,b,c));
        }
        sort (v.begin(), v.end(), [](const auto &a, const auto &b){
            if (get <0> (a) != get <0> (b)){
                return get <0> (a) < get <0> (b);
            }
            else{
                if (get <1> (a) != get <1> (b)){
                    return get <1> (a) < get <1> (b);
                }
                else{
                    if (get <2> (a) != get <2> (b)){
                        return get <2> (a) > get <2> (b);
                    }
                }
            }
        });
        vector <long long> dp (n+1, 0);
        dp[0]= get <2> (v[0]);
        long long maxi =dp[0];
        for (long long i =1; i < n; i++){
            dp[i]= get <2> (v[i]);
            for (long long j =0; j < i; j++){
                if (get <0> (v[i])> get <1> (v[j]) + get<0> (v[j])-1){
                    dp[i]= max (dp[i], dp[j]+ get <2> (v[i]));
                }
            }
            maxi = max (maxi, dp[i]);
        }
        cout << maxi<< endl;
    }
    return 0;
}