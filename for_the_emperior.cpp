#include <bits/stdc++.h>
using namespace std;
int main (){
    long long t;
    cin >> t;
    for (long long test =0; test < t; test++){
        long long n, m;
        cin >> n>> m;
        vector <long long> messenger(n+1, 0);
        for (long long i =1; i <= n; i++){
            long long mess;
            cin >> mess;
            messenger[i]= mess;
        }
        vector <vector <long long>> v (m+1, vector <long long> (m+1, LLONG_MAX));
        for (long long i =0; i < m; i++){
            long long a, b;
            cin >> a >> b;
            v[a][b]= 1;
        }
        long long ans =0;
        vector <bool> visit (n+1, false);
        visit[1]= true;

        for (long long k =1; k < =n; k++){
            for (long long i = 1; i <=n ; i++){
                for (long long j =1; j <= n; j++){
                    if (v[i][j] != LLONG_MAX && messenger[i] !=0){
                        v[i][j]= min (v[i][j], v[i][k]+ v[k][j]);
                        
                    }
                }
            }
        }
    
    }
}