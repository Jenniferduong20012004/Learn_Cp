#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("dpthuyen3.inp", "r", stdin);
    // freopen("dpthuyen3.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n;
    cin >> n;
    vector <tuple <long long, long long>> v;
    for(int i=1; i<=n; i++) {
        long long soA, soB;
        cin >> soA >> soB;
        v.push_back (make_tuple (soA, soB));
    }
    sort (v.begin(), v.end(), [](const auto &a, const auto &b ){
        if (get <0> (a) != get <0> (b)){
            return get <0> (a) < get <0> (b);
        }
        else{
           return get <1> (a) > get <1> (b);
        }
    });
    vector <long long> dp (n+1, LLONG_MAX);
    dp[0]= LLONG_MIN;
    for(int i=0; i<n; i++) {
        long long des = upper_bound (dp.begin(), dp.end(), get<1> (v[i]))- dp.begin();
        if (dp[des-1]< get<1> (v[i])){
            dp[des]= get <1> (v[i]);
        }
    }
    long long r =0;
    for(int i=1; i<=n; i++) {   
        if (dp[i]== LLONG_MAX){
            break;
        }
        r++;
    }
    cout << n-r;
}
