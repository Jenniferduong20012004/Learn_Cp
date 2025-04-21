#include<bits/stdc++.h>
using namespace std;
vector <long long> g(110, 0);
vector <long long> visit (110, 0);
int main(){
    long long n;
    cin >> n;
    vector <string> de;
    bool check = true;
    for (long long i =0; i < n; i++){
        string s;
        cin >> s;
        vector <long long> visit (110, 0);
        de.push_back (s);
        if (i > 0){
            if (de[i] < de[i-1]){
                cout <<"Impossible";
                check = false;
                break;
            }
            else{
                for (long long j =0; j < min (de[i].size(), de[i-1].size()); j++){
                    if (de[i][j]!= de[i-1][j]){
                        g[de[i-1][j]-'a'].push_back (de[i][j]-'a');
                        break;
                    }
                }
            }
        }
    }
    if (check){
        for (long long i =0; i <26; i++){
            if ()
        }
    }

}