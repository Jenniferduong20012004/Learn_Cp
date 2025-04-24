#include <bits/stdc++.h>
using namespace std;
int main (){
    long long n;
    cin >> n;
    vector <vector <long long >> bieuDo (n, vector <long long>(n, 0));
    for (long long i=0;i < n; i++){
        for (long long j =0; j < n; j++){
            long long e;
            cin >> e;
            bieuDo[i][j]= e;
            }
        }

    vector <long long> deBai;
    for (long long i=0;i < n; i++){
        long long a;
        cin >> a;
        deBai.push_back (a-1);
    }
    vector <bool> add (n, false);
    vector <long long > ans (n, 0);
    for (long long k =deBai.size()-1; k >=0; k--){
        add[deBai[k]]= true;
        long long tong =0;
        for (long long i=0; i < n; i++){
            for (long long j =0; j < n; j++){
                if (bieuDo[i][deBai[k]]< LLONG_MAX && bieuDo[deBai[k]][j]< LLONG_MAX){
                    bieuDo[i][j]= min (bieuDo[i][j], bieuDo[i][deBai[k]]+ bieuDo[deBai[k]][j]);
                    if (add[i] && add[j]){
                        tong += bieuDo[i][j];
                    }
                }

            }
        }
        ans[k]= tong;
    }
    for (long long i=0; i < n; i++){
        cout << ans[i]<< " ";
    }
}