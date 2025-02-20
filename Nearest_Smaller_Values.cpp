#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector <long long> deBai;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        deBai.push_back (a);
    }
    vector <long long> ans;
    vector <long long> mono;
    for (long long i =0; i < n; i++){
        if (mono.size()==0){
            ans.push_back (0);
            mono.push_back (i+1);
        }
        else{
            if (deBai[mono[mono.size()-1]-1]< deBai[i]){
                ans.push_back (mono[mono.size()-1]);
                mono.push_back (i+1);
            }
            else{
                while (deBai[mono[mono.size()-1]-1]>= deBai[i]){
                    mono.pop_back();
                    if (mono.size()==0){
                        break;
                    }
                }
                if (mono.size()!=0){
                    ans.push_back (mono[mono.size()-1]);
                }
                else{
                    ans.push_back(0);
                }
                mono.push_back (i+1);

            }
        }
    }
    for (long long i =0; i < n; i++){
        cout << ans[i]<< " ";
    }
}

