#include <bits/stdc++.h>
using namespace std;
bool asenBoyen (long long l, long long m, long long currentCoints, long long turn, vector<vector<long long>> &map){
    if (currentCoints ==0){
        if (turn ==1){
            return false;
        }
        else{
            return true; //boyen
        }
    }
    else if (currentCoints <0){
        if (turn ==1){
            return true;
        }
        else{
            return false; //boyen
        }
    }
     else if (currentCoints ==1 || currentCoints == l|| currentCoints ==m){
        if (turn ==1){
            return true;
        }
        else{
            return false; //boyen
        }
    }
    else{
        if (map[currentCoints][turn]!=-1){
            if (map[currentCoints][turn]==0){
                return false;
            }
            else{
                return true;
            }
        }
        else{
            if (turn ==0){ // boyen
                bool atThisMoment = asenBoyen (l,m,currentCoints-1,1,map)&& asenBoyen(l,m,currentCoints-l,1,map)&& asenBoyen(l,m,currentCoints-m,1,map);
                if (atThisMoment){
                    map[currentCoints][turn]=1;
                }
                else{
                    map[currentCoints][turn]=0;
                }
                return atThisMoment;
            }
            else{// asen
                bool atThisMoment = asenBoyen (l,m,currentCoints-1,0,map)|| asenBoyen(l,m,currentCoints-l,1,map)|| asenBoyen(l,m,currentCoints-m,0,map);
                if (atThisMoment){
                    map[currentCoints][turn]=1;
                }
                else{
                    map[currentCoints][turn]=0;
                }
                return atThisMoment;
            }
        }
    }
}
int main(){
    // freopen("dpcoing.inp", "r", stdin);
    // freopen("dpcoing.out", "w", stdout);
    long long k,l,m;
    cin >>k >> l>> m;
    string res = "";
    vector <vector<long long>> map (1000001, vector<long long> (2, -1 ));

    for (long long i =0; i < m; i++){
        long long c;
        cin >> c;
        bool atthis = asenBoyen (l,m,c,1,map);
        cout << atthis<< endl;
        if (atthis){
            res.append("A");
        }
        else{
            res.append("B");
        }
    }
    cout << res;
    return 0;
}
    