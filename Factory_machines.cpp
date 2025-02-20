#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, t;
    cin >> n>> t;
    vector <long long> machines;
    long long maxi = LLONG_MAX;
    for (long long i =0; i < n; i ++){
        long long a;
        cin >> a;
        maxi = min (maxi, a);
        machines.push_back (a);
    }
    maxi *= t;
    long long mini = 1;
    long long ans = 0;
    while (mini <= maxi){
        long long mid = (maxi+mini)/2;
        // check
        long long sumi =0;
        bool check = false;
        for (long long i =0; i < n; i++){
            sumi += mid/machines[i];
            if (sumi >= t){
                check = true;
                break;
            }
        }
        if (sumi >= t){
            check = true;
        }
        if (check){
            ans = mid;
            maxi = mid -1;
        }
        else{
            mini = mid +1;
        }

    }
    cout << ans;
    return 0;
}