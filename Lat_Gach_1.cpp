#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;

string addStrings(const string &num1, const string &num2) {
    string result = "";
    int carry = 0;  
    int i = num1.size() - 1, j = num2.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;  
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;  
        int sum = digit1 + digit2 + carry;          
        carry = sum / 10;                      
        result += (sum % 10) + '0';                 
    }
    std::reverse(result.begin(), result.end());
    return result;
}
string latGach (long long num, vector <string> &table){
    if (num ==1){
        return "1";
    }
    else if (num ==2){
        return "2";
    }
    else{
        if (table[num]!= "-1"){
            return table[num];
        }
        table[num]= (addStrings(latGach (num-1, table),latGach (num-2, table)));
        return table[num];
    }
}
int main(){
    // freopen("dplaga1.inp", "r", stdin);
    // freopen("dplaga1.out", "w", stdout);
    long long n;
    cin >> n;
    vector <string> table(400+1, "-1");
    for (long long i =0; i < n; i++){
        int a;
        cin >> a;
        cout << latGach (a, table)<< endl;
    }
    return 0;
}
    