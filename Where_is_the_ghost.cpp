//2520
#include <bits/stdc++.h>
using namespace std;
int main (){
    long long n;
    long long mod = 2520;
    cin >> n;
    vector <long long > v;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        v.push_back (a);
    }
    sort (v.begin(), v.end());

    return 0;
}