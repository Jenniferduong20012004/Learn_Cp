#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e9;
int main (){
    long long n;
    cin >> n;
    long long townA, townB;
    cin >> townA >> townB;
    vector <vector <pair <long long, long long> >> bieuDo (n+1);
    vector <long long> thanhPho (n+1);
    thanhPho[townA]=1;
    thanhPho[townB]= 2;
    for (long long testcase =0; testcase < n; testcase++){
        long long l, r, k;
        cin >> l >> r >> k;
        bieuDo[l].push_back ({r, k});
    }
}