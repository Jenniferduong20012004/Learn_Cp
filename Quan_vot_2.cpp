#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dpqvot2.inp", "r", stdin);
    // freopen("dpqvot2.out", "w", stdout);
    long long n, k;
    cin >> n>> k;
    vector <long long> ngayThiDau, tienThuong;
    vector <long long> dp (n+1, LLONG_MAX);
    dp[0]= LLONG_MIN;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        ngayThiDau.push_back (a);
    }
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        tienThuong.push_back (a);
    }
    for (long long i =0; i < n; i++){
        long long des = upper_bound (dp.begin(), dp.end(), ngayThiDau[i]- k)- dp.begin();
        cout << des << endl;
        if (dp[des-1]< ngayThiDau[i]- k){
            dp[des]= ngayThiDau[i];
            cout << dp[des]<< " ";
        }
    }
    cout << endl;
    for (long long i =1; i <= n; i++){
        if (dp[i] == LLONG_MAX){
            break;
        }
        cout << dp[i]<< " ";
    }
    
}