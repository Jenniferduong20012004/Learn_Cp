#include <bits/stdc++.h>
using namespace std;
int main (){
    long long n, k;
    cin >> n>>k;
    vector <long long> v;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        v.push_back (a);
    }
    for (long long i =0; i < k; i++){
        long long a;
        cin >> a;
        long long high = n-1, low = 0;
        long long ans = n;
        while (low <= high){
            long long mid = low + (high - low)/2;
            if (v[mid]>= a){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        cout << ans+1<< endl;
    }
    return 0;
}