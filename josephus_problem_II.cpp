#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 

int main() {
    long long n, k;
    cin >> n >> k;
    ordered_set s;

    for (long long i = 1; i <= n; i++) {
        s.insert(i);
    }

    long long cur = 0; 
    while (!s.empty()) {
        cur = (cur + k ) % s.size(); 
        auto it = s.find_by_order(cur);
        cout << *it << " "; 
        s.erase(it); 
    }
    
    return 0;
}
