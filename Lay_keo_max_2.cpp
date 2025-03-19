#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dpsmax2.inp", "r", stdin);
    // freopen("dpsmax2.out", "w", stdout);
    long long n;
    cin >> n;
    vector <long long> v;
    v.push_back (0);
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        v.push_back (a);
    }
    map <long long, long long> m;
    m[0]= 0;
    long long curMax =0;
    vector <long long> dp;
    for (long long i =1; i <= n; i++){
        auto l = m.lower_bound (v[i]);
        if (l->first == v[i]){
            
        }
        if (m[v[i]]==0){
            m[v[i]]= l->second + v[i];
        }
        else{
            m[v[i]]= m[v[i]]+ v[i];
        }
        curMax = max (curMax, m[v[i]]);

    }
    cout <<curMax<< endl;
}