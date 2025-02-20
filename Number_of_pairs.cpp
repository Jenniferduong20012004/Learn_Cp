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
        long long left =0, right =0;
        long long sum =0, ans =0;
        while (right < n && left < n){
            sum += v[right];
            if (sum < )
            right ++;
        }
    }
}