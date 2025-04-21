#include <bits/stdc++.h>
using namespace std;
long long timeDfs =0;
void dfs (long long u, long long pre, vector<long long> &num, vector <long long> &low, vector <vector<long long>> &cities){
    long long child =0; 
    ++timeDfs;
    num[u]= timeDfs;
    low[u]= timeDfs;
    for (long long v: cities[u]){
        if (v== pre){
            continue;
        }else{
            if (num[v]==0){
                child ++;
                p[]
            }
        }
    }
}
int main(){
    long long n, e;
    cin >> n >> e;
    vector <vector<long long>> cities (n+1, vector<long long> (0));
    for (long long i =0; i < e; i++){
        long long a, b;
        cin >> a >> b;
        cities[a].push_back (b);
        cities[b].push_back (a);
    }
    vector <long long> depth (n+1, 0);
    vector <long long> num (n+1, 0);
    vector <long long> low (n+1, 0);
    long long q;
    cin >> q;
    for (long long i =0; i < q; i++){
        long long a;
        cin >> a;
        vector <long long> de;
        if (a==1){
            for (long long j =0; j < 4; j++){
                long long num;
                cin >> num;
                de.push_back (num);
            }
        }
        else{
            for (long long j =0; j < 3; j++){
                long long num;
                cin >> num;
                de.push_back (num);
            }
        }
    }
}