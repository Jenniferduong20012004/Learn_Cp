#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main(){
    long long n, k;
    cin >> n>>k;
    ordered_multiset s;
    vector <long long> v;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        v.push_back (a);
    }
    long long medIndex;
    if (k %2==0){
        medIndex = (k/2)-1;
    }
    else{
        medIndex= (k-1)/2;
    }
    long long delePointer =0, addPointer = k;
    long long index =0;
    for (long long i =0; i < k; i++){
        s.insert ({v[i], index++});
    }
    cout << s.find_by_order (medIndex)-> first<< " ";
    while (addPointer < n){
        auto ite = s.lower_bound ({v[delePointer], 0});
        delePointer ++;
        s.erase (ite);
        s.insert ({v[addPointer], index++});
        addPointer++;
        cout << s.find_by_order (medIndex)-> first<< " ";
    }

    return 0;
}





