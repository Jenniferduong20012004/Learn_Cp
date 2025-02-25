#include <bits/stdc++.h>
using namespace std;
int main (){
    long long testcase;
    cin >> testcase;
    for (long long i =0; i < testcase; i++){
        long long n, l, r;
        cin >> n>>l>>r;
        vector <long long> v;
        for (long long j =0; j < n; j++){
            long long a;
            cin >> a;
            v.push_back (a);
        }
        sort (v.begin(), v.end());
        long long ans =0;
        for (long long j =0; j < n; j++){
            long long cur = v[j];
            long long leftBound = lower_bound (v.begin()+j+1, v.end(), l- cur)- v.begin();
            long long rightBound = upper_bound (v.begin()+j+1, v.end(), r- cur)- v.begin();
            ans+= rightBound- leftBound;
        }
        cout << ans<< endl;
    }
}