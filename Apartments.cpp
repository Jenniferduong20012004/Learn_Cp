#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, m, k;
    cin >> n>>m>> k;
    vector <long long> users, apartments;
    for (long long i =0; i <n; i++){
        long long a;
        cin >> a;
        users.push_back (a);
    }
    for (long long i =0; i <m; i++){
        long long a;
        cin >> a;
        apartments.push_back (a);
    }
    sort (users.begin(), users.end());
    sort (apartments.begin(), apartments.end());
    long long res =0;
    long long indexOfApartments=0;
    for (long long i =0; i <n; i++){
        if (indexOfApartments ==m){
            break;
        }
            if (apartments[indexOfApartments]>= users[i]-k && apartments[indexOfApartments]<= users[i]+k ){
                res++;
                indexOfApartments++;
            }
            else if (apartments[indexOfApartments]<users[i]-k ){
                while (apartments[indexOfApartments]<users[i]-k){
                    indexOfApartments++;
                    if (indexOfApartments ==m){
                    break;
                }
                }
                if (indexOfApartments ==m){
                    break;
                }
                if (apartments[indexOfApartments]>= users[i]-k && apartments[indexOfApartments]<= users[i]+k ){
                    res++;
                    indexOfApartments++;
                }
            }
        }

    cout << res;
    return 0;
    }

