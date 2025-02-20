#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector <long long> prefixSum (n+1,0);
    for (long long i =1; i <= n; i++){
        long long a;
        cin >> a;
        prefixSum[i]= prefixSum[i-1]+a;
    }
    map <long long, long long> m;
    m[0]++;
    long long res =0;
    for (long long i =1; i <=n; i++){
        long long cur = ((prefixSum[i]%n)+n)%n;
        res += m[cur];
        m[cur]++;
    }
    cout << res;
    return 0;
}


