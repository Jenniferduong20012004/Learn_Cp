#include <bits/stdc++.h>
using namespace std;
int main (){
    long long n, diff;
    cin >> n>> diff;
    vector <long long> v;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        v.push_back (a);
    }
    map <long long, long long > m;
    long long ans=0, curDiff =0;
    long long left =0, right =0;
    while (left <n && right < n){
        long long cur = v[right];
        if (m[cur]==0){
            curDiff++;
        }
        m[cur]++;
        if (curDiff > diff){
            long long prevRight = right-1;
            ans += (prevRight - left+1); 
            // cout << left << " "<< right-1<< " "<< ans<<endl;  
            while (curDiff > diff){
                m[v[left]]--;
                if (m[v[left]]==0){
                    curDiff--;
                    left++;
                }
                else{
                    left++;
                    ans += (prevRight - left+1);
                    // cout << left << " "<< right-1<< " "<< ans<<endl;
                }
            }
        }
        right ++;

    }
    right --;
    while (left< n){
        ans += (right-left+1);
        left++;

    }
    cout << ans;
}