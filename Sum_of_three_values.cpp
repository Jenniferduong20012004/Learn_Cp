#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, x;
    cin >> n>> x;
    vector <tuple<long long, long long>> v(n);
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        v[i]= make_tuple (a, i+1);
    }
    sort (v.begin(), v.end());
    bool check = true;
    for (long long i =0; i < n-2; i++){
        long long left = i+1, right = n-1;
        long long resLeft =LLONG_MIN, resRight = LLONG_MIN;
        while (left < right){
            if (get<0>(v[left])+ get<0>(v[right])== x- get <0>(v[i])){
                resLeft = get<1>(v[left]);
                resRight = get<1>(v[right]);
                break;
            }
            else if (get<0>(v[left])+ get<0>(v[right])> x- get <0>(v[i])){
                right--;
            }
            else{
                left++;
            }
        }
        if (resLeft != LLONG_MIN){
            cout << get <1> (v[i])<< " "<< resLeft<< " "<< resRight;
            check = false;
            break;
        }
    }
    if (check){
        cout << "IMPOSSIBLE";
    }

    return 0;
}

