#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("dpsubseg.inp", "r", stdin);
    // freopen("dpsubseg.out", "w", stdout);
    long long t;
    cin >> t;
    for (long long i =0; i < t; i++){
        long long n;
        cin >> n;
        vector <long long> deBai;
        vector <long long> ans(n, 1);
        for (long long j =0; j < n; j++){
            long long a;
            cin >> a;
            deBai.push_back (a);
        }
        for (long long j =n-1; j >0; j--){
            if (deBai[j]*deBai[j-1]<0){
                ans[j-1]+=ans[j];
            }
        }
        for (long long j =0; j <n; j++){
            cout << ans[j]<< " ";
        }
        cout << endl;
    }
    return 0;
}
// -5 -4 -3 1 -2 -1
// 1 1 1 2 1 1
// so sanh voi so sau, neu nhan < 0 thi += cai trc
    