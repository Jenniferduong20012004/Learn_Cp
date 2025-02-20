#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
int main(){
    long long n, k;
   cin >> n>> k;
   vector <long long> nums;
   vector <long long> exercise;
   for (long long i =0; i < k; i++){
    long long a;
    cin >> a;
    nums.push_back (a);
    exercise.push_back (a);
   }
    nums.push_back (0);
    nums.push_back (n);
    sort (nums.begin(), nums.end());
    vector <long long > ans (k);
    ordered_multiset ms;
    long long maxi = LLONG_MIN;
    for (long long i =0; i < nums.size(); i++){
        if (i!= nums.size()-1){
            long long a = nums[i];
            ms.insert ({a, nums[i+1]- nums[i]});
            // cout << nums[i+1]- nums[i]<< endl;
            maxi = max (maxi, nums[i+1]- nums[i]);
        }
        else{
            long long a = nums[i];
            ms.insert ({a, 0});
        }
    }
    // for (auto it = ms.begin(); it != ms.end(); ++it) {
    //     cout << it->first << " "<< it-> second  << endl;
    // }
    ans [k-1]= maxi;
    for (long long i = k-1; i>0; i--){
        long long a = exercise[i];
        auto it = ms.lower_bound ({a,0});
        auto lowIt = --ms.lower_bound ({a,0});
        long long sum = it->second+ lowIt-> second;
        // cout << lowIt->first<< " "<< it-> first << endl;
        ms.erase (it);
        ms.erase (lowIt);
        ms.insert ({a, sum});
        maxi = max (maxi, sum);
        ans[i-1]= maxi;
    }
    for (long long i =0; i < k; i++){
        cout << ans[i]<< " ";
    }
    return 0;
}