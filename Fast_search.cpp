#include <bits/stdc++.h>
using namespace std;
int main (){
    long long n;
    cin >> n;
    vector <long long> v;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        v.push_back (a);
    }
    sort (v.begin(), v.end());
    long long k;
    cin >> k;
    for (long long i =0; i < k; i++){
        long long a , b;
        cin >> a >> b;
        bool check = true;
        long long des = lower_bound (v.begin(), v.end(), a)- v.begin();
        long long desHigh = upper_bound (v.begin(), v.end(), b)- v.begin();
        cout << desHigh - des << " ";
        
    }
    return 0;
}