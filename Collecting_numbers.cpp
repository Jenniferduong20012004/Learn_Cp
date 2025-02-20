#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector <tuple<long long, long long>> deBai;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        deBai.push_back (make_tuple(a, i));
    }
    sort (deBai.begin(), deBai.end());
    long long res =1;
    for (long long i =0; i < n-1; i++){
        if (get<1> (deBai[i]) > get<1> (deBai[i+1])){
            res++;
        }
    }
    cout << res;

    return 0;
}
// 4 2 1 5 3
// 0 1 2 3 4
// 1 2 3 4 5
// 2 1 4 0 3
// Input:

// 5
// 4 2 1 5 3
// Output:
// 3

// 1 2 4 5 