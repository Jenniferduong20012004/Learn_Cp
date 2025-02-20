#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,x;
    cin >> n >> x;
    vector <long long> prefixSum (n+1, 0);
    for (long long i =1; i <=n; i++){
        long long a;
        cin >> a;
        prefixSum[i]= prefixSum[i-1]+a;
    }
    long long res =0;
    map <long long, long long> m;
    m[0]++;
    for (long long i =1; i <=n; i++){
        long long cur = prefixSum[i];
        res += m[cur- x];
        m[cur]++;
    }
    cout << res;
    return 0;
}

