#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dpqvot.inp", "r", stdin);
    // freopen("dpqvot.out", "w", stdout);
    long long n, k;
    cin >> n>> k;
    vector <long long> ngayThiDau, tienThuong;
    vector <long long> dp;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        ngayThiDau.push_back (a);
    }
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        tienThuong.push_back (a);
        dp.push_back (a);
    }
    long long maxi = tienThuong[0];
    for (long long i =1; i < n; i++){
        for (long long j =0; j < i; j++){
            if (ngayThiDau[i]- ngayThiDau[j]>=k){
                dp[i]= max (dp[i], dp[j]+ tienThuong[i]);
            }
        }
        maxi = max (maxi, dp[i]);
    }
    cout << maxi;
}