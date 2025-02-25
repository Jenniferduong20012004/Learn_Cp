#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
int main(){
    long long testcase;
    cin >> testcase;
    for (long long t =0; t < testcase; t++){
        long long n, m;
        cin >> n>> m;
        vector <long long> v;
        for (long long i =0; i < n; i++){
            long long a;
            cin >> a;
            v.push_back (a);
        }
        sort (v.begin(), v.end());
        // can co (du) de dat duoc m
        ordered_set s;
        long long curM = 2;
        long long curLeft =0;
        for (long long i =0; i < n; i++){
            if (curM > m){
                break;
            }
            for (long long j = curM; j < m; j++){
                i
            }
        }

    }
}