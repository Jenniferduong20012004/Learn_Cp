#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dpcsc.inp", "r", stdin);
    // freopen("dpcsc.out", "w", stdout);
    long long n;
    cin >> n;
    vector <long long> capSoCong;
    vector <long long> dp;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        capSoCong.push_back (a);
    }
    // for (long long i =1; i < n; i++){
    //     for (long long j =0; j < i; j++){
    //         if (ngayThiDau[i]- ngayThiDau[j]>=k){
    //             dp[i]= max (dp[i], dp[j]+ tienThuong[i]);
    //         }
    //     }
    //     maxi = max (maxi, dp[i]);
    // }
    cout << maxi;
}