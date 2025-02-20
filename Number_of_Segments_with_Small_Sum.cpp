#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
int main(){
    long long n,m;
    cin >> n >> m;
    vector <long long> v(n+1,0);
    ordered_set os;
    for (long long i =1; i <= n; i++){
        long long a;
        cin >> a;
        v[i]= v[i-1]+a;
    }
    os.insert (0);
    long long ans =0;
    for (long long i =1; i <=n; i++){
        long long a = os.size()- os.order_of_key (v[i]- m);
        ans+=a;
        os.insert (v[i]);
    }
    cout << ans;
    return 0;
}

