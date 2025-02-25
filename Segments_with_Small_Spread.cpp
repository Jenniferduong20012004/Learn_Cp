#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
int main (){
    long long n, diff;
    cin >> n>> diff;
    vector <long long> v;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        v.push_back (a);
    }
    ordered_set s;
    long long left =0, right=0;
    long long ans =0;
    while (left < n && right < n){
        s.insert (v[right]);
        while (*s.rbegin()- *s.begin()>diff){
            auto it = s.find(v[left]);
            s.erase(it);
            left++;
        }
        ans +=(right-left+1);
        right ++;
    }
    cout << ans;

}