#include <bits/stdc++.h>
using namespace std;
long long finding (long long n, vector <long long> &v){
    if (n == v[n]){
        return v[n];
    }
    else{
        return finding (v[n], v);
    }
}
void unioning (long long a, long long b, vector <long long> &v, vector <long long> &size,vector <long long> &rank){
    long long parA = finding (a, v);
    long long parB = finding (b, v);
    if (parA != parB){
        if (rank[parA]< rank[parB]){
            swap (parA, parB);
        }
        v[parB]= parA;
        if (rank[parB]== rank[parA]){
            rank[parA]++;
        }
    }
}
void cut (long long a, long long b, vector <long long> &v, vector <long long> &rank){
    long long parA = finding (a, v);
    long long parB = finding (b, v);
    if (parA == parB){
        v[b]= b;
    }
}
int main (){
    long long n, m , k;
    cin >> n >> m >> k;
    vector <long long> v (n+1, 0);
    vector <long long> size (n+1, 1);
    vector <long long> rank (n+1, 0);
    for (long long i=1; i <= n; i++){
        v[i]= i;
    }
    for (long long i =0; i < m; i++){
        long long a, b;
        cin >> a >> b;
        unioning (a, b, v);

    }
    for (long long i =0; i < k; i++){
        string s;
        cin >> s;
        if (s == "ask"){
            long long g, d;
            cin >> g >> d;
            long long parA = finding (g, v);
            long long parB = finding (d, v);
            if (parA== parB){
                cout << "YES"<<endl;
            }
            else{
                cout << "NO"<< endl;
            }
        }
        else{
            long long g, d;
            cin >> g >> d;
            cut (g,d,v);
        }
    }
}