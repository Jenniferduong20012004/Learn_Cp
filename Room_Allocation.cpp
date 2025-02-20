#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
int main(){
    long long n;
    cin >> n;
    vector <tuple<long long, long long, long long>> exercise;
    for (long long i =0; i < n; i++){
        long long a, b;
        cin >> a>> b;
        exercise.push_back (make_tuple (a,b,i));
    }
    sort (exercise.begin(), exercise.end());
    ordered_multiset saveDay;
    vector <long long> ans (n, 0);
    long long indexRoom =1;
    long long maxi = 0;
    for (long long i =0; i < n; i++){
        maxi = max (maxi, (long long)saveDay.size());
        if (saveDay.empty()){
            saveDay.insert ({get<1> (exercise[i]), indexRoom++});
            ans[get<2> (exercise[i])]=1;
            maxi++;
        }
        else{
            long long dayCome = get<0> (exercise[i]);
            auto nearestSmaller = saveDay.upper_bound ({dayCome,0});
            if (nearestSmaller == saveDay.begin()){
                saveDay.insert ({get<1> (exercise[i]), indexRoom++});
                ans[get<2> (exercise[i])]= indexRoom-1;
                maxi++;
            }
            else{
                long long roomFree = (--nearestSmaller)-> second;
                saveDay.erase (nearestSmaller);
                saveDay.insert ({get<1> (exercise[i]), roomFree});
                ans[get<2> (exercise[i])]= roomFree;
            }
        }
    }
    cout << maxi<< endl;
    for (long long i =0; i < ans.size(); i++){
        cout << ans[i]<< " ";
    }
 
    return 0;
}
 
