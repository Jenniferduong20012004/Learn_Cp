#include <bits/stdc++.h>
using namespace std;
int main (){
    long long a, b;
    while (cin >> a ){
        if (a ==-1){
            break;
        }
        cin >> b;
        vector <vector <pair <long long, long long>>> bieuDo (a+1);
        vector <long long> dist (a+1, 0);
        for (long long i =0; i < b; i++){
            long long d, e, f;
            cin >> d>> e>>f;
            bieuDo[d].push_back ({e, f});
            bieuDo[e].push_back ({d, f});
        }
        priority_queue <
    }
}