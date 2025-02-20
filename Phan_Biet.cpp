#include <bits/stdc++.h>
using namespace std;
int main(){
    // freopen("dpdiffarr.inp", "r", stdin);
    // freopen("dpdiffarr.out", "w", stdout);
    long long n,mi;
    cin >> n>> mi;
    vector <long long> deBai;
    vector <long long> ans (n+1, 0);
    map <long long, long long> m;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        deBai.push_back (a);
        // mangHieu
    }
    for (long long i = n-1; i >=0; i--){
        //deBai-1
        long long cur = deBai[i];
        m[cur]+=1;
        if (m[cur] ==1){
            ans[i]= ans[i+1]+1;
        }
        else{
            ans[i]= ans[i+1];
        }
    }
    for (long long i =0; i <mi; i++){
        long long num;
        cin >> num;
        cout << ans[num-1]<< endl;
    }
    // 1 2 1 4 5 3 2 5 9
    // 1 1 1 1 1 1 1 1 1   - 0  0 0 0 0 0 0 0 0
    // 2 1 1 1 1 1 1 1 1   - -1 0 0 0 0 0 0 0 0
    // 2
    // 
    return 0;
}
    