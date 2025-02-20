#include <bits/stdc++.h>
using namespace std;
int main(){
    string n;
    cin >> n;
    vector <long long> phanChia;
    sort (n.begin(), n.end());
    string zeros="";
    bool firstTime = true;
    for (char c: n){
        if (c=='0'){
            zeros.append("0");
        }
        else if (c != '0'){
            if (firstTime){
                cout << c;
                cout <<zeros;
                firstTime= false;
            }
            else{
                cout << c;
            }
        }
    }
}

