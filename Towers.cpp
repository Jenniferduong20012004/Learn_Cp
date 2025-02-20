#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector <tuple<long long, long long>> v;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        v.push_back (make_tuple (a, i));
    }
    sort (v.begin(), v.end());
    long long res =0;
    vector <long long> cur;
    for (long long i = 0; i < n; i++){
        if (cur.size()==0){
            cur.push_back (get<1> (v[i]));
            res++;
        }
        else{// giam xuong
            long long current =get<1> (v[i]);
            long long des = upper_bound (cur.begin(), cur.end(), current)- cur.begin();
            if (des >= cur.size()){
                cur.push_back(current);
                res++;
            }
            else{
                cur[des]= current;
            }

        }
    }
    cout << res;
    return 0;
}

