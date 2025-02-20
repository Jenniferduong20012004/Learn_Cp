#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector <long long > v;
    for (long long i =0; i <n; i++){
        long long a;
        cin >> a;
        v.push_back(a);
    }
    sort (v.begin(), v.end());
    // median
    long long medDes=0;
    if (n%2!=0){
        medDes= (n-1)/2;
    }
    else{
        medDes = (n/2)-1;
    }
    long long res =0;
    long long med= v[medDes];
    for (long long i =0; i < n; i++){
        res += abs (v[i]- med);
    }
    cout << res;

    // 1 2 2 3 5
    // 1 0 0 1 3
    // 1 2 3 4 5 6 7 8 9 10
    // 4 3 2 1 0 1 2 3 4 5

    return 0;
}