#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, m;
    cin >> n>> m;
    vector <long long> passengers;
    map <long long, long long> tickets;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        tickets[a] ++;
    }
    for (long long i =0; i < m; i++){
        long long a;
        cin >> a;
        passengers.push_back (a);
    }
    for (long long i =0; i < m; i++){
        auto des = tickets.upper_bound (passengers[i]);
        if (des == tickets.begin()){
            cout << "-1"<< endl;
        }
        else {
            des--;
            cout << des-> first << endl;
            tickets[des->first]--;
            if (des->second==0){
                tickets.erase (des);
            }
        }
    }
    return 0;
}

