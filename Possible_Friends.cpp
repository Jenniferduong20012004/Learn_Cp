#include <bits/stdc++.h>
using namespace std;
int main (){
    long long t;
    cin >> t;
    for (long long q = 0; q < t; q++){
        vector <string> deBai;
        string s;
        cin >> s;
        deBai.push_back (s);
        for (long long i =0; i < s.size()-1; i++){
            string a;
            cin >> a;
            deBai.push_back (a);
        }
        vector <vector <long long>> maTran (s.length(), vector <long long>(s.length(), LLONG_MAX));
        for (long long i =0; i < s.length(); i++){
            for (long long j =0; j < s.length(); j++){
                if (deBai[i][j]== 'Y'){
                    maTran[i][j]= 1;
                }
            }
        }
        for (long long k = 0; k < s.length(); k++){
            for (long long i =0; i < s.length(); i++){
                for (long long j =0; j < s.length(); j++){
                    if (maTran[i][k]< LLONG_MAX && maTran[k][j]< LLONG_MAX){
                        maTran[i][j]= min (maTran[i][j], maTran[i][k]+ maTran[k][j]);
                    }
                }
            }
        }
        vector <long long> ans (s.length(), 0);
        long long maxi = 0, index =0;
        for (long long i =0; i < s.length(); i++){
            for (long long j =0; j < s.length(); j++){
                if (maTran[i][j]==2 && deBai[i][j]== 'N'&& i !=j){
                    ans[i]++;
                    // cout << maTran[i][j]<< " ";
                }
            }
            // cout << endl;
            if (ans[i]> maxi){
                maxi = ans[i];
                index = i;
            }
        }
        cout << index << " "<< maxi<< endl;

    }
    return 0;
}