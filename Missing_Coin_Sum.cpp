#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector <long long> v;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        v.push_back (a);
    }
    sort (v.begin(), v.end());
    long long curSum =1;
    bool check = false;
    for (long long i =0; i < n; i++){
        if (v[i]> curSum){
            check = true;
            cout << curSum;
            break;
        }
        curSum+=v[i];
    }
    if (!check){
        cout << curSum;
    }
    return 0;
}

