#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
int main(){
    long long n,m;
    cin >> n>> m;
    vector <long long> deBai;
    deBai.push_back (0);
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        deBai.push_back (a);
    }
    vector <long long> res;
    vector <long long> position (n+1);
    long long count =1;
    for (long long i =1; i <=n; i++){
        position[deBai[i]]=i;
    }
    for (long long i =1; i < n; i++){
        count += (position[i]> position[i+1]);
    }
    set <pair<long long, long long>> updated;
    for (long long i =0; i < m; i++){
        long long a, b;
        cin >> a>> b;
        if (deBai[a]+1<=n){
            updated.insert ({deBai[a], deBai[a]+1});
        }
        if (deBai[a]-1>=1){
            updated.insert ({deBai[a]-1, deBai[a]});
        }
        if (deBai[b]+1<= n){
            updated.insert ({deBai[b], deBai[b]+1});
        }
        if(deBai[b]-1>=1){
            updated.insert({deBai[b]-1, deBai[b]});
        }
        for (auto swapped: updated){
            count-= position[swapped.first]> position[swapped.second];
        }
        swap(deBai[a], deBai[b]);
        position[deBai[a]]=a;
        position[deBai[b]]=b;
        for (auto swapped: updated){
            count+= position[swapped.first]> position[swapped.second];
        }
        cout << count << endl;
        updated.clear();
    }
    return 0;
}
