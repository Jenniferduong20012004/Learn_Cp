#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    deque <long long > dq;
    for (long long i =1; i <=n; i++){
        dq.push_back (i);
    }
    bool check = false;
    while (!dq.empty()){
        if (!check){
            dq.push_back (dq.front());
            dq.pop_front();
            check = true;
        }
        else{
            cout << dq.front() << " ";
            dq.pop_front();
            check = false;
        }
    }

    return 0;
}


