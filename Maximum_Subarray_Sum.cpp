#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector <long long> prefix (n+1, 0);
    for (long long i =1; i <=n; i++){
        long long a;
        cin >> a;
        prefix[i]= prefix[i-1]+a;
    }
    long long minSub =0;
    long long ans =LLONG_MIN;
    for (long long i =1; i <=n; i++ ){
        ans = max (ans, prefix[i]- minSub);
        minSub = min (minSub, prefix[i]);
    }
    cout << ans;
    return 0;
}

