#include <bits/stdc++.h>
using namespace std;
long long doChoi (long long cur, long long n, vector <long long> &deBai, vector <long long> &ans ){
    if (cur > n-1){
        return 0;
    }
    else if (cur == n-1){
        return deBai[cur];
    }
    else if (cur == n-2){
        return deBai[cur]+ deBai[cur+1];
    }
    else if (cur == n-3){
        return deBai[cur]+ deBai[cur+1]+ deBai[cur+2];
    }
    else {
        if (ans[cur]!= -1){
            return ans[cur];
        }
        return ans[cur] = max (deBai[cur]+ doChoi(cur+2,n,deBai, ans), max (deBai[cur]+ deBai[cur+1]+ doChoi(cur+4,n,deBai,ans), deBai[cur]+deBai[cur+1]+deBai[cur+2]+ doChoi(cur+6,n,deBai,ans)));
    }

}
int main(){
    // freopen("dptoys.inp", "r", stdin);
    // freopen("dptoys.out", "w", stdout);
    long long testcase;
    cin >> testcase;
    for (long long i =0; i < testcase; i++){
        long long n;
        cin >>n;
        vector <long long> deBai;
        vector <long long> ans (n, -1);
        for (long long j =0; j < n; j++){
            long long a;
            cin >> a;
            deBai.push_back (a);
        }
        cout << doChoi (0,n,deBai,ans)<< endl;
    }
    return 0;
}
// -5 -4 -3 1 -2 -1
// 1 1 1 2 1 1
// so sanh voi so sau, neu nhan < 0 thi += cai trc
    