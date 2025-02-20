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
    for (long long i =0; i < n-3; i++){
        bool checkI = false;
        for (long long j =i+1;j < n-2; j++){
            long long left = j+1, right = n-1;
            long long resLeft =LLONG_MIN, resRight = LLONG_MIN;
            while (left < right){
                if (get<0>(v[left])+ get<0>(v[right])== x- get <0>(v[i])- get<0>(v[j])){
                    resLeft = get<1>(v[left]);
                    resRight = get<1>(v[right]);
                    break;
                }
                else if (get<0>(v[left])+ get<0>(v[right])> x- get <0>(v[i])- get<0>(v[j])){
                    right--;
                }
                else{
                    left++;
                }
            }
            if (resLeft != LLONG_MIN){
                cout << get <1> (v[i])<< " "<<get <1>(v[j])<< " "<< resLeft<< " "<< resRight;
                checkI = true;
                check = false;
                break;
            }
        }
        if (checkI){
            break;
        }
        
    }
    if (check){
        cout << "IMPOSSIBLE";
    }

    return 0;
}

