#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main(){
    long long n;
    cin >> n;
    ordered_multiset s, x;
    vector <tuple<long long, long long, long long>> v;
    for (long long i =0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        v.push_back (make_tuple (a, b, i));
    }
    sort (v.begin(), v.end(),[](const auto &a, const auto &b){
        if (get <0> (a) != get <0> (b)){
            return get <0> (a) < get <0> (b);
        }
        else{
            return get <1> (a) > get <1> (b);
        }
    });
    vector <long long> firstRowAns (n, 0);
    vector <long long> secondRowAns (n, 0);
    long long index =0;
    s.insert({get <1> (v[n-1]), index++});
    for (long long i = n-2; i >=0; i--){
        long long greater_count = s.order_of_key ({get <1> (v[i])+1, 0});
        firstRowAns[get<2>(v[i])]=greater_count;
        s.insert({get <1> (v[i]), index++});
    }
    index=0;
    x.insert({get <1>(v[0]), index++});  
    for (long long i = 1; i < n; i++){
        long long smaller_count = x.size() - x.order_of_key({get <1> (v[i]),0});
        secondRowAns[get<2>(v[i])]=smaller_count;
        x.insert ({get <1> (v[i]), index++});
    }
    for (long long i = 0; i < n; i++){
        cout << firstRowAns[i]<< " ";
    }
    cout << endl;
    for (long long i = 0; i < n; i++){
        cout << secondRowAns[i]<< " ";
    }
    return 0;
}





