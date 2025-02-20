#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
int main(){
    long long a;
    cin >> a;
    vector <tuple <long long, long long>> v;
    for (long long i =0; i <a; i++){
        long long a, b;
        cin >> a>>b;
        v.push_back (make_tuple (a, b));
    }
}