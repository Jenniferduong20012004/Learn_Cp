#include <bits/stdc++.h>
using namespace std;
long long muaVe (long long n, long long ngHienTai, vector <long long> &t, vector <long long> &r, vector <long long> &ans, vector<long long> &ngMuaVe){
    if (ngHienTai==n-1){
        ngMuaVe.push_back (n);
        return t[n-1];
    }
    else if (ngHienTai == n-2){
        if (t[ngHienTai]+ t[ngHienTai+1]< r[ngHienTai]){
            ngMuaVe.push_back (ngHienTai+1);
            ngMuaVe.push_back (ngHienTai+2);
        }
        return min (r[ngHienTai], t[ngHienTai]+ t[ngHienTai+1]);
    }
    else{
        if (ans[ngHienTai]!=-1){
            return ans[ngHienTai];
        }
        return ans[ngHienTai]= min (t[ngHienTai]+ muaVe(n, ngHienTai+1, t,r,ans), r[ngHienTai]+ muaVe(n, ngHienTai+2,t,r,ans));
    }
}
int main(){
    // freopen("dptick2.inp", "r", stdin);
    // freopen("dptick2.out", "w", stdout);
    long long n;
    cin >> n;
        vector <long long> t;
        vector <long long> r;
        vector <long long> ans(n, -1);
        for (long long j =0; j < n; j++){
            long long a;
            cin >> a;
            t.push_back (a);
        }
        for (long long j =0; j < n-1; j++){
            long long a;
            cin >> a;
            r.push_back (a);
        }
        cout << muaVe (n, 0, t,r,ans);
        cout << endl;
    return 0;
}
