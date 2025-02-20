#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    map <long long, long long> m;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        m[a]++;
    }
    cout << m.size();
    return 0;
    }

